cmake_minimum_required(VERSION 2.8.11)

PROJECT(PythonAPI)
set(OXDeepNN_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/include/OXDeepNN
    ${PROJECT_SOURCE_DIR}/pybind11)
set(OXDeepNN_SOURCR_DIR ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR}/src/layers
    ${PROJECT_SOURCE_DIR}/src/solver)
INCLUDE_DIRECTORIES(${OXDeepNN_INCLUDE_DIR})
#pybind11_add_module(Parent src/parent.cpp)
