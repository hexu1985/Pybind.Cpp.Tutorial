#include <pybind11/pybind11.h>
#include "world.h"

namespace py = pybind11;

PYBIND11_MODULE(hello, m)
{
    m.doc() = "pybind11 example for expose class";

    py::class_<World>(m, "World")
        .def(py::init<>())
        .def("greet", &World::greet)
        .def("set", &World::set)
    ;
}
