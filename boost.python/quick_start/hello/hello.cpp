//  Software License, Version 1.0. (See accompanying file LICENSE_1_0.txt
//  or copy at http://www.boost.org/LICENSE_1_0.txt)
//  Hello World Example from the tutorial
//  [Joel de Guzman 10/9/2002]

#include <boost/python/module.hpp>
#include <boost/python/def.hpp>

char const* greet()     // greet函数定义
{
   return "hello, world";
}

BOOST_PYTHON_MODULE(hello_ext)  // 指示要扩展的python模块名为"hello_ext"
{
    using namespace boost::python;
    def("greet", greet);        // 将greet函数导出到python, 并且在python中函数名也叫"greet"
}
