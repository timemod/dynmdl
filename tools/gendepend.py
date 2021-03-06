# Create dictionaries with dependencies of C files on header files
import sys
import glob
import os
import cPickle
import re

include_pattern = "^#include\s+\"(.+)\""

def gendepend(dict_filename):

    try:
        # check if dictionaries are present
        dict_file = open(dict_filename, 'rb')
        dep_dict = cPickle.load(dict_file)
        src_files = set(new_files)
    except:
        # no dictionaries present
        dep_dict = {}
        print("Analyzing dependencies of c++ files on header files\n")
        src_files = glob.glob(os.path.join(src_dir, '*.c*'))
        src_files = [os.path.basename(file) for file in src_files]
    else:
        # dictionaries present.
        print("Updating dependencies of C++ files on header files")
        for srcfile in src_files:
            sys.stdout.write(srcfile + ' ')
        print('\n')

    update_dep_dict(src_files, dep_dict)
        
    # write dictionary to a file
    dict_file = open(dict_filename, 'wb')
    cPickle.dump(dep_dict, dict_file)
    dict_file.close()

    return None

def update_dep_dict(src_files, dep_dict):
    # update dependency dictionaries dep_dict
    modified = False
    # loop over sourcefiles
    for srcfile in src_files :
        # get list of dependencies for scrfile
        depend = set()
        read_depend(srcfile, srcfile, depend)
        if len(depend) > 0:
            dep_dict[srcfile] = depend

def read_depend(srcfile, filenm, depend) :
    # read dependencies of file srcfile on modules
    for line in open(os.path.join(src_dir, filenm)):
        line = line.strip() # remove trailing blancs
        m = re.search(include_pattern, line)
        if m != None:
            # syntax is "include "mymodule""
            include_name = m.group(1)
            if not include_name in depend:
                ok = False
                is_macro_header = False
                if os.path.isfile(os.path.join(src_dir, include_name)):
                    ok = True
                else:
                    # do not use os.path here, because otherwise
                    # the generated dependency file on Windows
                    # doesn't run on Linux
                    include_name = "macro/" + include_name
                    ok = os.path.isfile(os.path.join(src_dir, include_name))
                    is_macro_header = True
                if ok:
                    depend.add(include_name)
                    if not is_macro_header:
                        # call subroutine recursively
                        read_depend(srcfile, include_name, depend);

# main program
if __name__ == "__main__":
    src_dir = sys.argv[1]
    dict_filename = sys.argv[2]
    new_files = sys.argv[3:] # all files which are newer than the dictionary
    gendepend(dict_filename)
