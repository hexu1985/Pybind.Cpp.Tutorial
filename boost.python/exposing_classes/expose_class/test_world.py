import os
import sys
sys.path.append(os.getenv('HELLO_MODULE_PATH')) # for ctest

import hello

planet = hello.World()
planet.set('howdy')
s = planet.greet()
print(s)
