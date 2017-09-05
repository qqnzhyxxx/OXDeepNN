#************************************************#
#                                                #
# Copyright (C) 2017  Niu Zhiyong (China)        #
# <tbnzhyxxx@163.com>                            #
# Update:2017.04.08 1:53                                               #
#************************************************#
cmake_minimum_required(VERSION 3.8.0)
message(STATUS "#CMAKE_VERSION=${CMAKE_VERSION}")
#
# Set project name
project(OXDeepNN)
#
# Set  C++ standard version
set(CMAKE_CXX_STANDARD 14)
#
# Set src file list
aux_source_directory (${PROJECT_SOURCE_DIR}/source/ SRC_LIST)
#
# Set Include h file path
set(OXDeepNN_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/source
                        ${PROJECT_SOURCE_DIR}/include
                        ${PROJECT_SOURCE_DIR}/include/OXDeepNN)
#INCLUDE_DIRECTORIES(include/ include/OXDeepNN)
INCLUDE_DIRECTORIES(${OXDeepNN_INCLUDE_DIR})
#message(STATUS "#OXDeepNN_INCLUDE_DIR=${OXDeepNN_INCLUDE_DIR}")
#message(STATUS "#CMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX}")
#
#
# Set if build test file or not
option(BUILD_TESTS "Build tests." TRUE)
if (BUILD_TESTS)
    enable_testing()
    add_subdirectory(ctest ctest_bin)
endif()
#
# Set folder in project dir
add_subdirectory(include)
add_subdirectory(source)
add_subdirectory(demo demo_bin)
add_subdirectory(python python)
add_subdirectory(pybind11)
#
# Set the path to build projcet
set(CMAKE_BINARY_DIR "${PROJECT_SOURCE_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")
set(EXECUTABLE_OUTPUT_PATH  "${PROJECT_SOURCE_DIR}/bin")
set(PROJECT_BINARY_DIR  "${PROJECT_SOURCE_DIR}/bin")
#message(STATUS "#EXECUTABLE_OUTPUT_PATH=${EXECUTABLE_OUTPUT_PATH}")
#message(STATUS "#CMAKE_BINARY_DIR=${CMAKE_BINARY_DIR}")
#message(STATUS "#CMAKE_RUNTIME_OUTPUT_DIRECTORY=${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
#message(STATUS "#PROJECT_BINARY_DIR=${PROJECT_BINARY_DIR}")
#
# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Add Qt module in project
find_package(Qt5Core)
find_package(Qt5Widgets)
find_package(Qt5Gui)
find_package(Qt5OpenGL)
find_package(Qt5PrintSupport)
#find_package(Qt5Xml)
if(Qt5_POSITION_INDEPENDENT_CODE)
    set(CMAKE_POSITION_INDEPENDENT_CODE ON)
endif()
message(STATUS "#Qt5Widgets_VERSION=${Qt5Widgets_VERSION}")
# Set source file to make executable
#add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/source/main.cpp )
add_executable(${PROJECT_NAME} ${SRC_LIST})
#
# Set QT5 module which we used
qt5_use_modules(${PROJECT_NAME} Core Widgets Gui OpenGL PrintSupport)


