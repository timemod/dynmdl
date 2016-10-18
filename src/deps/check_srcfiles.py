#
# This python script checks if source files have been deleted. If so, the object files, 
# library files and dependency dictionary files are deleted.
#
import glob
import os
import cPickle

# extension for object files:
OBJ_EXT = 'o'
LIB_EXT = 'so'

def remove_file(filename):
    if os.path.exists(filename):
        print("Deleting file " + filename)
        os.remove(filename)
        return True
    else:
        return False

'''get_name returns the name of a file without path and extension '''
def get_name(filename):
    return os.path.splitext(os.path.basename(filename))[0]

''' get the names of the source files, without path and extension as set '''
def get_src_names():
    src_files   = glob.glob("*.c*")
    src_files = [get_name(src_file) for src_file in src_files]
    return src_files

''' checks object files, deletes obsolete files and returns the
    number of deleted files'''
def check_compiled_files(ext, src_names):
    delete_count = 0
    compiled_files = glob.glob("*." + ext)
    for compiled_file in compiled_files:
        if not get_name(compiled_file) in src_names:
            if remove_file(compiled_file):
                delete_count = delete_count + 1
    return delete_count

''' checks dictionaries and delete obsolete dictionaries '''
def check_dictionary(src_names):
    dict_filename = "deps/deps.pkl"
    if os.path.exists(dict_filename):
        dict_file = open(dict_filename, 'rb')
        dep_dict = cPickle.load(dict_file)
        dict_file.close()
        src_files = list(dep_dict.keys())
        for src_file in src_files:
            if not get_name(src_file) in src_names:
                remove_file(dict_filename)
                return

# main script
src_names = get_src_names()

# object files
if check_compiled_files(OBJ_EXT, src_names) > 0:
    libfile = glob.glob("*." + LIB_EXT)
    if len(libfile) > 0:
        remove_file(libfile[0])

# dictionaries
check_dictionary(src_names)
