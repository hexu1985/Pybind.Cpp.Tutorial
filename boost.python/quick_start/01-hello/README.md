## Hello World
Following C/C++ tradition, let's start with the "hello, world". A C++ Function:

```
char const* greet()
{
       return "hello, world";
}
```

can be exposed to Python by writing a Boost.Python wrapper:

```
#include <boost/python.hpp>

BOOST_PYTHON_MODULE(hello_ext)
{
        using namespace boost::python;
            def("greet", greet);
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
# 如果想要生成python2的module, 需要修改Makefile中的INCLUDES和LDFLAGS  
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
