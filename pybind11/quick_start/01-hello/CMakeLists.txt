# define minimum cmake version
cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

# project name and supported language
project(hello LANGUAGES CXX)

# require C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# for testing we will need the python interpreter
find_package(PythonInterp REQUIRED)

add_subdirectory(pybind11)

# create python module
add_library(hello_ext
  MODULE
    hello.cpp
  )

target_link_libraries(hello_ext
  PUBLIC
    pybind11::module
  )

set_target_properties(hello_ext
  PROPERTIES
    PREFIX "${PYTHON_MODULE_PREFIX}"
    SUFFIX "${PYTHON_MODULE_EXTENSION}"
  )

# turn on testing
enable_testing()

# define test
add_test(
  NAME
    python_test
  COMMAND
    ${CMAKE_COMMAND} -E env HELLO_EXT_MODULE_PATH=$<TARGET_FILE_DIR:hello_ext>
    ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/test_hello.py
  )
