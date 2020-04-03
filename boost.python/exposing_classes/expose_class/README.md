## Expose Classes

Now let's expose a C++ class to Python.

Consider a C++ class/struct that we want to expose to Python:

```
struct World
{
    void set(std::string msg) { this->msg = msg; }
    std::string greet() { return msg; }
    std::string msg;
};
```

We can expose this to Python by writing a corresponding Boost.Python C++ Wrapper:

```
#include <boost/python.hpp>
using namespace boost::python;

BOOST_PYTHON_MODULE(hello)
{
    class_<World>("World")
        .def("greet", &World::greet)
        .def("set", &World::set)
    ;
}
```

Here, we wrote a C++ class wrapper that exposes the member functions greet and set. Now, after building our module as a shared library, we may use our class World in Python. Here's a sample Python session:

```
>>> import hello
>>> planet = hello.World()
>>> planet.set('howdy')
>>> planet.greet()
'howdy'
```

编译并测试程序
1. 编译hello.so

```
$ make
# 如果想要生成python2的module, 需要修改Makefile中的INCLUDES和LDFLAGS  
```

2. python调用hello模块

```
$ python
>>> import hello
>>> planet = hello.World()
>>> planet.set('howdy')
>>> planet.greet()
'howdy'
```

3. 通过脚本调用hello模块

``$ python test_word.py``

4. 通过CMake编译程序

```
mkdir build
cmake -H. -Bbuild
cmake --build build
```

