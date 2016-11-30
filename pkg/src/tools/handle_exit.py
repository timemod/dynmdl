import sys
import re

exit_pattern = "exit\(.*\)"
simple_message_pattern = '(cerr|cout)\s*<<\s*"(.+)"(\s*<<\s*endl)?\s*;'

src_file = sys.argv[1]
src_file_old = src_file + ".old"

f = open(src_file_old)
lines = f.readlines()
f.close()

# a list of lines to delete
delete = [False] * len(lines)

for line_no in range(len(lines)):
    if re.search(exit_pattern, lines[line_no]) != None:
        print lines[line_no-1].strip()
        (s, count) = re.subn(simple_message_pattern, 
                'dyn_error("\\2");', lines[line_no - 1])
        if (count == 1):
            print "Simple message pattern"
            lines[line_no] = s
            delete[line_no - 1] = True



f = open(src_file, 'w')
for line_no in range(len(lines)):
    if not delete[line_no]:
        f.write(lines[line_no])
f.close()

