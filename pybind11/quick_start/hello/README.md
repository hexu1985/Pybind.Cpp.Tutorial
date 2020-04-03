## Hello World

Following C/C++ tradition, let's start with the "hello, world". A C++ Function:

```
char const* greet()
{
    return "hello, world";
}
```

can be exposed to Python by writing a pybind11 wrapper:

```
#include <pybind11/pybind11.h>

PYBIND11_MODULE(hello_ext, m)
{
    m.doc() = "pybind11 example hello_ext";
    m.def("greet", greet, "A function which print \"hello, world\"");
}
```

That's it. We're done. We can now build this as a shared library. The resulting DLL is now visible to Python. Here's a sample Python session:

```
>>> import hello_ext
>>> print hello_ext.greet()
hello, world
```

编译并测试程序
1. 编译hello_ext.so

```
$ make
# 如果想要生成python2的module, 需要修改Makefile中的INCLUDES
```

2. 调用hello_ext

```
$ python
>>> import hello_ext
>>> hello_ext.greet()
'hello, world'
```

3. 通过脚本调用hello_ext

```
$ python test_hello.py
```

4. 通过CMake编译程序

```
mkdir build
cmake -H. -Bbuild
cmake --build build
```

