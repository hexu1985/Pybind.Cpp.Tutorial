#include <pybind11/pybind11.h>

namespace py = pybind11;

char const* greet()     // greet函数定义
{
   return "hello, world";
}

PYBIND11_MODULE(hello_ext, m)  // 指示要扩展的python模块名为"hello_ext"
{
    m.doc() = "pybind11 example hello_ext";

    m.def("greet", greet, "A function which print \"hello, world\"");        // 将greet函数导出到python, 并且在python中函数名也叫"greet"
}
