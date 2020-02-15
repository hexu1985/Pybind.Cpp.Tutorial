import os
import sys
sys.path.append(os.getenv('HELLO_EXT_MODULE_PATH'))

import hello_ext

s = hello_ext.greet()
assert s == "hello, world"
print(s)

