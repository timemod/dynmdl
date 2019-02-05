import sys
import re

exit_pattern = "exit\(.*\)"
simple_message_pattern = '(cerr|cout)\s*<<\s*"(.+)"(\s*<<\s*endl)?\s*;'


dyn_error_pattern = "cerr\s*<<\s*([\S\s]+?)(<<\s*endl)\s*;\s*exit\(EXIT_FAILURE\);"

src_file = sys.argv[1]
src_file_new = src_file + ".new"

f = open(src_file)
text_old = f.read()
f.close()

def repl_fun(m):
    message = m.group(1).strip()
    if len(m.group(2)) > 2:
        message = re.sub("\"$", "\\\\n\"", message)
    return("dyn_error(" + message + ");")

text = re.sub(dyn_error_pattern, repl_fun, text_old)

f = open(src_file_new, 'w')
f.write(text)
f.close()

