/*
 * Copyright (C) 2010-2016 Dynare Team
 *
 * This file is part of Dynare.
 *
 * Dynare is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Dynare is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Dynare.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "ConfigFile.hh"
#include <boost/algorithm/string/trim.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/tokenizer.hpp>

#include "dyn_error.hh"

using namespace std;

Hook::Hook(string &global_init_file_arg)
{
  if (global_init_file_arg.empty())
    {
      dyn_error("ERROR: The Hook must have a Global Initialization File argument.\n");
    }
  hooks["global_init_file"] = global_init_file_arg;
}

Path::Path(vector<string> &includepath_arg)
{
  if (includepath_arg.empty())
    {
      dyn_error("ERROR: The Path must have an Include argument.\n");
    }
  paths["include"] = includepath_arg;
}

SlaveNode::SlaveNode(string &computerName_arg, string port_arg, int minCpuNbr_arg, int maxCpuNbr_arg, string &userName_arg,
                     string &password_arg, string &remoteDrive_arg, string &remoteDirectory_arg,
                     string &dynarePath_arg, string &matlabOctavePath_arg, bool singleCompThread_arg,
                     string &operatingSystem_arg) :
  computerName(computerName_arg), port(port_arg), minCpuNbr(minCpuNbr_arg), maxCpuNbr(maxCpuNbr_arg), userName(userName_arg),
  password(password_arg), remoteDrive(remoteDrive_arg), remoteDirectory(remoteDirectory_arg), dynarePath(dynarePath_arg),
  matlabOctavePath(matlabOctavePath_arg), singleCompThread(singleCompThread_arg), operatingSystem(operatingSystem_arg)
{
  if (computerName.empty())
    {
      dyn_error("ERROR: The node must have a ComputerName.\n");
    }

  if (!operatingSystem.empty())
    if (operatingSystem.compare("windows") != 0 && operatingSystem.compare("unix") != 0)
      {
        dyn_error("ERROR: The OperatingSystem must be either 'unix' or 'windows' (Case Sensitive).\n");
      }
}

Cluster::Cluster(member_nodes_t  member_nodes_arg) :
  member_nodes(member_nodes_arg)
{
  if (member_nodes.empty())
    {
      dyn_error("ERROR: The cluster must have at least one member node.\n");
    }
}

ConfigFile::ConfigFile(bool parallel_arg, bool parallel_test_arg,
                       bool parallel_slave_open_mode_arg, const string &cluster_name_arg) :
  parallel(parallel_arg), parallel_test(parallel_test_arg),
  parallel_slave_open_mode(parallel_slave_open_mode_arg), cluster_name(cluster_name_arg)
{
}

ConfigFile::~ConfigFile()
{
}

void
ConfigFile::getConfigFileInfo(const string &config_file)
{
  using namespace boost;
  ifstream *configFile;

  if (config_file.empty())
    {
      string defaultConfigFile ("");
      // Test OS and try to open default file
#if defined(_WIN32) || defined(__CYGWIN32__)
      if (getenv("APPDATA") == NULL)
        {
          std::string msg;
          if (parallel || parallel_test)
            msg = "ERROR: ";
          else
            msg = "WARNING: ";
          msg = msg +  "APPDATA environment variable not found.\n";

          if (parallel || parallel_test)
              dyn_error(msg.c_str());
          else {
              dyn_warning(msg.c_str());
           }
        }
      else
        {
          defaultConfigFile += getenv("APPDATA");
          defaultConfigFile += "\\dynare.ini";
        }
#else
        if (getenv("HOME") == NULL)
          {
            std::string msg;
            if (parallel || parallel_test)
              msg = "ERROR: ";
            else
              msg = "WARNING: ";
            msg = msg +  "HOME environment variable not found.\n";
            if (parallel || parallel_test) {
                dyn_error(msg.c_str());
            } else {
                dyn_warning(msg.c_str());
            }
          }
        else
          {
            defaultConfigFile += getenv("HOME");
            defaultConfigFile += "/.dynare";
          }
#endif
        configFile = new ifstream(defaultConfigFile.c_str(), fstream::in);
        if (!configFile->is_open()) {
          if (parallel || parallel_test)
            {
                std::string msg = "ERROR: Could not open the default config file (" + defaultConfigFile + ")\n";
                dyn_error(msg);
            }
          else
            return;
        }
      }
    else
      {
        configFile = new ifstream(config_file.c_str(), fstream::in);
        if (!configFile->is_open())
          {
            std::string msg = "ERROR: Couldn't open file " + config_file + "\n";
            dyn_error(msg);
          }
      }


  string name, computerName, port, userName, password, remoteDrive,
    remoteDirectory, dynarePath, matlabOctavePath, operatingSystem,
    global_init_file;
  vector<string> includepath;
  int minCpuNbr = 0, maxCpuNbr = 0;
  bool singleCompThread = true;
  member_nodes_t member_nodes;

  bool inHooks = false;
  bool inNode = false;
  bool inCluster = false;
  bool inPaths = false;
  while (configFile->good())
    {
      string line;
      getline(*configFile, line);
      trim(line);
      if (line.empty() || !line.compare(0, 1, "#"))
        continue;

      if (!line.compare("[node]")
          || !line.compare("[cluster]")
          || !line.compare("[hooks]")
          || !line.compare("[paths]"))
        {
          if (!global_init_file.empty())
            // we were just in [hooks]
            addHooksConfFileElement(global_init_file);
          else if (!includepath.empty())
            // we were just in [paths]
            addPathsConfFileElement(includepath);
          else
            // we were just in [node] or [cluster]
            addParallelConfFileElement(inNode, inCluster, member_nodes, name,
                                       computerName, port, minCpuNbr, maxCpuNbr, userName,
                                       password, remoteDrive, remoteDirectory,
                                       dynarePath, matlabOctavePath, singleCompThread,
                                       operatingSystem);

          //! Reset communication vars / option defaults
          if (!line.compare("[hooks]"))
            {
              inHooks = true;
              inNode = false;
              inCluster = false;
              inPaths = false;
            }
          else if (!line.compare("[node]"))
            {
              inHooks = false;
              inNode = true;
              inCluster = false;
              inPaths = false;
            }
          else if (!line.compare("[paths]"))
            {
              inHooks = false;
              inNode = false;
              inCluster = false;
              inPaths = true;
            }
          else
            {
              inHooks = false;
              inNode = false;
              inCluster = true;
              inPaths = false;
            }

          name = userName = computerName = port = password = remoteDrive
            = remoteDirectory = dynarePath = matlabOctavePath
            = operatingSystem = global_init_file = "";
          includepath.clear();
          minCpuNbr = maxCpuNbr = 0;
          singleCompThread = true;
          member_nodes.clear();
        }
      else
        {
          vector<string> tokenizedLine;
          split(tokenizedLine, line, is_any_of("="));
          if (tokenizedLine.size() != 2)
            {
              dyn_error("ERROR (in config file): Options should be formatted as 'option = value'.\n");
            }
          trim(tokenizedLine.front());
          trim(tokenizedLine.back());

          if (inHooks)
            if (!tokenizedLine.front().compare("GlobalInitFile"))
              if (global_init_file.empty())
                global_init_file = tokenizedLine.back();
              else
                {
                  dyn_error("ERROR: May not have more than one GlobalInitFile option in [hooks] block.)\n");
                }
            else
              {
                std::string msg = "ERROR: Unrecognized option " + tokenizedLine.front() + " in [hooks] block.\n";
                dyn_error(msg);
              }
          else if (inPaths)
            if (!tokenizedLine.front().compare("Include"))
              if (includepath.empty())
                {
                  vector<string> tokenizedPath;
                  split(tokenizedPath, tokenizedLine.back(), is_any_of(":"), token_compress_on);
                  for (vector<string>::iterator it = tokenizedPath.begin();
                       it != tokenizedPath.end(); it++ )
                    if (!it->empty())
                      {
                        trim(*it);
                        includepath.push_back(*it);
                      }
                }
              else
                {
                  dyn_error("ERROR: May not have more than one Include option in [paths] block.\n");
                }
            else
              {
                std::ostringstream msg;
                msg << "ERROR: Unrecognized option " << tokenizedLine.front() << " in [paths] block." << endl;
                dyn_error(msg);
              }
          else
            if (!tokenizedLine.front().compare("Name"))
              name = tokenizedLine.back();
            else if (!tokenizedLine.front().compare("CPUnbr"))
              {
                vector<string> tokenizedCpuNbr;
                split(tokenizedCpuNbr, tokenizedLine.back(), is_any_of(":"));
                try
                  {
                    if (tokenizedCpuNbr.size() == 1)
                      {
                        minCpuNbr = 1;
                        maxCpuNbr = lexical_cast< int >(tokenizedCpuNbr.front());
                      }
                    else if (tokenizedCpuNbr.size() == 2
                             && tokenizedCpuNbr[0].at(0) == '['
                             && tokenizedCpuNbr[1].at(tokenizedCpuNbr[1].size()-1) == ']')
                      {
                        tokenizedCpuNbr[0].erase(0, 1);
                        tokenizedCpuNbr[1].erase(tokenizedCpuNbr[1].size()-1, 1);
                        minCpuNbr = lexical_cast< int >(tokenizedCpuNbr[0]);
                        maxCpuNbr = lexical_cast< int >(tokenizedCpuNbr[1]);
                      }
                  }
                catch (const bad_lexical_cast &)
                  {
                    dyn_error("ERROR: Could not convert value to integer for CPUnbr.\n");
                  }

                if (minCpuNbr <= 0 || maxCpuNbr <= 0)
                  {
                      dyn_error("ERROR: Syntax for the CPUnbr option is as follows:\n"
                         "       1) CPUnbr = <int>\n"
                         "    or 2) CPUnbr = [<int>:<int>]\n"
                         "       where <int> is an Integer > 0.\n");
                  }

                minCpuNbr--;
                maxCpuNbr--;
                if (minCpuNbr > maxCpuNbr)
                  {
                    int tmp = maxCpuNbr;
                    maxCpuNbr = minCpuNbr;
                    minCpuNbr = tmp;
                  }
              }
            else if (!tokenizedLine.front().compare("Port"))
              port = tokenizedLine.back();
            else if (!tokenizedLine.front().compare("ComputerName"))
              computerName = tokenizedLine.back();
            else if (!tokenizedLine.front().compare("UserName"))
              userName = tokenizedLine.back();
            else if (!tokenizedLine.front().compare("Password"))
              password = tokenizedLine.back();
            else if (!tokenizedLine.front().compare("RemoteDrive"))
              remoteDrive = tokenizedLine.back();
            else if (!tokenizedLine.front().compare("RemoteDirectory"))
              remoteDirectory = tokenizedLine.back();
            else if (!tokenizedLine.front().compare("DynarePath"))
              dynarePath = tokenizedLine.back();
            else if (!tokenizedLine.front().compare("MatlabOctavePath"))
              matlabOctavePath = tokenizedLine.back();
            else if (!tokenizedLine.front().compare("SingleCompThread"))
              if (tokenizedLine.back().compare("true") == 0)
                singleCompThread = true;
              else if (tokenizedLine.back().compare("false") == 0)
                singleCompThread = false;
              else
                {
                  dyn_error("ERROR (in config file): The value passed to SingleCompThread may only be 'true' or 'false'.\n");
                }
            else if (!tokenizedLine.front().compare("OperatingSystem"))
              operatingSystem = tokenizedLine.back();
            else if (!tokenizedLine.front().compare("Members"))
              {
                char_separator<char> sep(" ,;", "()", drop_empty_tokens);
                tokenizer<char_separator<char> > tokens(tokenizedLine.back(), sep);
                bool begin_weight = false;
                string node_name;
                for (tokenizer<char_separator<char> >::iterator it = tokens.begin();
                     it != tokens.end(); it++)
                  {
                    string token (*it);
                    if (token.compare("(") == 0)
                      {
                        begin_weight = true;
                        continue;
                      }
                    else if (token.compare(")") == 0)
                      {
                        node_name.clear();
                        begin_weight = false;
                        continue;
                      }

                    if (!begin_weight)
                      {
                        if (!node_name.empty()) {
                          if (member_nodes.find(node_name) != member_nodes.end())
                            {
                              dyn_error("ERROR (in config file): Node entered twice in specification of cluster.\n");
                            }
                          else
                            member_nodes[node_name] = 1.0;
                        }
                        node_name = token;
                      }
                    else
                      try
                        {
                          double weight = lexical_cast<double>(token.c_str());
                          if (weight <= 0)
                            {
                              dyn_error("ERROR (in config file): Misspecification of weights passed to Members option.\n");
                            }
                          member_nodes[node_name] = weight;
                        }
                      catch (bad_lexical_cast &)
                        {
                          dyn_error("ERROR (in config file): Misspecification of weights passed to Members option.\n");
                        }
                  }
                if (!node_name.empty()) {
                  if (member_nodes.find(node_name) == member_nodes.end())
                    member_nodes[node_name] = 1.0;
                  else
                    {
                      dyn_error("ERROR (in config file): Node entered twice in specification of cluster.\n");
                    }
                }
              }
            else
              {
                std::ostringstream msg;
                msg << "ERROR (in config file): Option " << tokenizedLine.front() << " is invalid." << endl;
                dyn_error(msg);
              }
        }
    }

  if (!global_init_file.empty())
    addHooksConfFileElement(global_init_file);
  else if (!includepath.empty())
    addPathsConfFileElement(includepath);
  else
    addParallelConfFileElement(inNode, inCluster, member_nodes, name,
                               computerName, port, minCpuNbr, maxCpuNbr, userName,
                               password, remoteDrive, remoteDirectory,
                               dynarePath, matlabOctavePath, singleCompThread,
                               operatingSystem);

  configFile->close();
  delete configFile;
}

void
ConfigFile::addHooksConfFileElement(string &global_init_file)
{
  if (global_init_file.empty())
    {
      dyn_error("ERROR: The global initialization file must be passed to the GlobalInitFile option.\n");
    }
  else
    hooks.push_back(new Hook(global_init_file));
}

void
ConfigFile::addPathsConfFileElement(vector<string> &includepath)
{
  if (includepath.empty())
    {
      dyn_error("ERROR: The path to be included must be passed to the Include option.\n");
    }
  else
    paths.push_back(new Path(includepath));
}

void
ConfigFile::addParallelConfFileElement(bool inNode, bool inCluster, member_nodes_t member_nodes,
                                       string &name, string &computerName, string port, int minCpuNbr, int maxCpuNbr, string &userName,
                                       string &password, string &remoteDrive, string &remoteDirectory,
                                       string &dynarePath, string &matlabOctavePath, bool singleCompThread,
                                       string &operatingSystem)
{
  //! ADD NODE
  if (inNode)
    if (!member_nodes.empty())
      {
        dyn_error("Invalid option passed to [node].\n");
      }
    else
      if (name.empty() || slave_nodes.find(name) != slave_nodes.end())
        {
          dyn_error("ERROR: Every node must be assigned a unique name.\n");
        }
      else  {
        slave_nodes[name] = new SlaveNode(computerName, port, minCpuNbr, maxCpuNbr, userName,
                                          password, remoteDrive, remoteDirectory, dynarePath,
                                          matlabOctavePath, singleCompThread, operatingSystem);
       }
  //! ADD CLUSTER
  else if (inCluster) {
    if (minCpuNbr > 0 || maxCpuNbr > 0 || !userName.empty()
        || !password.empty() || !remoteDrive.empty() || !remoteDirectory.empty()
        || !dynarePath.empty() || !matlabOctavePath.empty() || !operatingSystem.empty())
      {
        dyn_error("Invalid option passed to [cluster].\n");
      }
    else
      if (name.empty() || clusters.find(name) != clusters.end())
        {
          dyn_error("ERROR: The cluster must be assigned a unique name.\n");
        }
      else
        {
          if (clusters.empty())
            firstClusterName = name;
          clusters[name] = new Cluster(member_nodes);
        }
    }
}

void
ConfigFile::checkPass(WarningConsolidation &warnings) const
{
  bool global_init_file_declared = false;
  for (vector<Hook *>::const_iterator it = hooks.begin() ; it != hooks.end(); it++)
    {
      const map <string, string> hookmap = (*it)->get_hooks();
      for (map <string, string>::const_iterator mapit = hookmap.begin() ; mapit != hookmap.end(); mapit++)
        if (mapit->first.compare("global_init_file") == 0) {
          if (global_init_file_declared == true)
            {
              dyn_error("ERROR: Only one global initialization file may be provided.\n");
            }
          else
            global_init_file_declared = true;
        }
    }

  if (!parallel && !parallel_test)
    return;

  //! Check Slave Nodes
  if (slave_nodes.empty())
    {
      dyn_error("ERROR: At least one node must be defined in the config file.\n"); 
    }

  for (map<string, SlaveNode *>::const_iterator it = slave_nodes.begin();
       it != slave_nodes.end(); it++)
    {
#if !defined(_WIN32) && !defined(__CYGWIN32__)
      //For Linux/Mac, check that cpuNbr starts at 0
      if (it->second->minCpuNbr != 0)
        warnings << "WARNING: On Unix-based operating systems, you cannot specify the CPU that is "
                 << "used in parallel processing. This will be adjusted for you such that the "
                 << "same number of CPUs are used." << endl;
#endif
      if (!it->second->port.empty())
        try
          {
            boost::lexical_cast< int >(it->second->port);
          }
        catch (const boost::bad_lexical_cast &)
          {
            std::ostringstream msg;
            msg << "ERROR (node " << it->first << "): the port must be an integer." << endl;
            dyn_error(msg);
          }
      if (!it->second->computerName.compare("localhost")) // We are working locally
        {
          if (!it->second->remoteDrive.empty())
            {
              std::ostringstream msg;
              msg << "ERROR (node " << it->first << "): the RemoteDrive option may not be passed for a local node." << endl;
              dyn_error(msg);
            }
          if (!it->second->remoteDirectory.empty())
            {
              std::ostringstream msg;
              msg << "ERROR (node " << it->first << "): the RemoteDirectory option may not be passed for a local node." << endl;
              dyn_error(msg);
            }
        }
      else
        {
          if (it->second->userName.empty())
            {
              std::ostringstream msg;
              msg << "ERROR (node " << it->first << "): the UserName option must be passed for every remote node." << endl;
              dyn_error(msg);
            }
          if (it->second->operatingSystem.compare("windows") == 0)
            {
              if (it->second->password.empty())
                {
                  std::ostringstream msg;
                  msg << "ERROR (node " << it->first << "): the Password option must be passed under Windows for every remote node." << endl;
                  dyn_error(msg);
                }
              if (it->second->remoteDrive.empty())
                {
                  std::ostringstream msg;
                  msg << "ERROR (node " << it->first << "): the RemoteDrive option must be passed under Windows for every remote node." << endl;
                  dyn_error(msg);
                }
            }
#if defined(_WIN32) || defined(__CYGWIN32__)
          if (it->second->operatingSystem.empty())
            {
              if (it->second->password.empty())
                {
                  std::ostringstream msg;
                  msg << "ERROR (node " << it->first << "): the Password option must be passed under Windows for every remote node." << endl;
                  dyn_error(msg);
                }
              if (it->second->remoteDrive.empty())
                {  
                  std::ostringstream msg;
                  msg << "ERROR (node " << it->first << "): the RemoteDrive option must be passed under Windows for every remote node." << endl;
                  dyn_error(msg);
                }
            }
#endif
          if (it->second->remoteDirectory.empty())
            {
              std::ostringstream msg;
              msg << "ERROR (node " << it->first << "): the RemoteDirectory must be specified for every remote node." << endl;
              dyn_error(msg);
            }
        }
    }

  //! Check Clusters
  if (clusters.empty())
    {
      dyn_error("ERROR: At least one cluster must be defined in the config file.\n");
    }

  if (!cluster_name.empty() && clusters.find(cluster_name) == clusters.end())
    {
      std::ostringstream msg;
      msg << "ERROR: Cluster Name " << cluster_name << " was not found in the config file." << endl;
      dyn_error(msg);
    }

  for (map<string, Cluster *>::const_iterator it = clusters.begin();
       it != clusters.end(); it++)
    for (member_nodes_t::const_iterator itmn = it->second->member_nodes.begin();
         itmn != it->second->member_nodes.end(); itmn++)
      if (slave_nodes.find(itmn->first) == slave_nodes.end())
        {
          std::ostringstream msg;
          msg << "Error: node " << itmn->first << " specified in cluster " << it->first << " was not found" << endl;
          dyn_error(msg);
        }
}

void
ConfigFile::transformPass()
{
  if (!parallel && !parallel_test)
    return;

#if !defined(_WIN32) && !defined(__CYGWIN32__)
  //For Linux/Mac, check that cpuNbr starts at 0
  for (map<string, SlaveNode *>::const_iterator it = slave_nodes.begin();
       it != slave_nodes.end(); it++)
    if (it->second->minCpuNbr != 0)
      {
        it->second->maxCpuNbr = it->second->maxCpuNbr - it->second->minCpuNbr;
        it->second->minCpuNbr = 0;
      }
#endif

  map<string, Cluster *>::const_iterator cluster_it;
  if (cluster_name.empty())
    cluster_it = clusters.find(firstClusterName);
  else
    cluster_it = clusters.find(cluster_name);

  double weight_denominator = 0.0;
  for (member_nodes_t::const_iterator it = cluster_it->second->member_nodes.begin();
       it != cluster_it->second->member_nodes.end(); it++)
    weight_denominator += it->second;

  for (member_nodes_t::iterator it = cluster_it->second->member_nodes.begin();
       it != cluster_it->second->member_nodes.end(); it++)
    it->second /= weight_denominator;
}

vector<string>
ConfigFile::getIncludePaths() const
{
  vector<string> include_paths;
  for (vector<Path *>::const_iterator it = paths.begin() ; it != paths.end(); it++)
    {
      map <string, vector<string> > pathmap = (*it)->get_paths();
      for (map <string, vector<string> >::const_iterator mapit = pathmap.begin() ; mapit != pathmap.end(); mapit++)
        for (vector<string>::const_iterator vecit = mapit->second.begin(); vecit != mapit->second.end(); vecit++)
          include_paths.push_back(*vecit);
    }
  return include_paths;
}

void
ConfigFile::writeHooks(ostream &output) const
{
  for (vector<Hook *>::const_iterator it = hooks.begin() ; it != hooks.end(); it++)
    {
      map <string, string> hookmap = (*it)->get_hooks();
      for (map <string, string>::const_iterator mapit = hookmap.begin() ; mapit != hookmap.end(); mapit++)
        output << "options_." << mapit->first << " = '" << mapit->second << "';" << endl;
    }
}

void
ConfigFile::writeCluster(ostream &output) const
{
  if (!parallel && !parallel_test)
    return;

  map<string, Cluster *>::const_iterator cluster_it;
  if (cluster_name.empty())
    cluster_it = clusters.find(firstClusterName);
  else
    cluster_it = clusters.find(cluster_name);

  int i = 1;
  for (map<string, SlaveNode *>::const_iterator it = slave_nodes.begin();
       it != slave_nodes.end(); it++)
    {
      bool slave_node_in_member_nodes = false;
      for (member_nodes_t::const_iterator itmn = cluster_it->second->member_nodes.begin();
           itmn != cluster_it->second->member_nodes.end(); itmn++)
        if (!it->first.compare(itmn->first))
          slave_node_in_member_nodes = true;

      if (!slave_node_in_member_nodes)
        continue;

      output << "options_.parallel";
      if (i > 1)
        output << "(" << i << ")";
      i++;
      output << " = struct('Local', ";
      if (it->second->computerName.compare("localhost"))
        output << "0, ";
      else
        output << "1, ";

      output << "'ComputerName', '" << it->second->computerName << "', "
             << "'Port', '" << it->second->port << "', "
             << "'CPUnbr', [" << it->second->minCpuNbr << ":" << it->second->maxCpuNbr << "], "
             << "'UserName', '" << it->second->userName << "', "
             << "'Password', '" << it->second->password << "', "
             << "'RemoteDrive', '" << it->second->remoteDrive << "', "
             << "'RemoteDirectory', '" << it->second->remoteDirectory << "', "
             << "'DynarePath', '" << it->second->dynarePath << "', "
             << "'MatlabOctavePath', '" << it->second->matlabOctavePath << "', "
             << "'OperatingSystem', '" << it->second->operatingSystem << "', "
             << "'NodeWeight', '" << (cluster_it->second->member_nodes.find(it->first))->second << "', ";

      if (it->second->singleCompThread)
        output << "'SingleCompThread', 'true');" << endl;
      else
        output << "'SingleCompThread', 'false');" << endl;
    }

  if (parallel_slave_open_mode)
    output << "options_.parallel_info.leaveSlaveOpen = 1;" << endl;

  output << "InitializeComputationalEnvironment();" << endl;
  if (parallel_test)
    output << "ErrorCode = AnalyseComputationalEnvironment(options_.parallel, options_.parallel_info);" << endl
           << "disp(['AnalyseComputationalEnvironment returned with Error Code: ' num2str(ErrorCode)]);" << endl
           << "diary off;" << endl
           << "return;" << endl;
}

void
ConfigFile::writeEndParallel(ostream &output) const
{
  if ((!parallel && !parallel_test) || !parallel_slave_open_mode)
    return;

  output << "if options_.parallel_info.leaveSlaveOpen == 1" << endl
         << "     closeSlave(options_.parallel,options_.parallel_info.RemoteTmpFolder);" << endl
         << "end" << endl;
}
