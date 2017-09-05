#************************************************#
#                                                #
#       this cmakelist build for  ctesting       #
#                                                #
#************************************************#
cmake_minimum_required(VERSION 3.8.0)
set(CMAKE_CXX_STANDARD 14)
#set(TEST_NAME_PERCEPTRON perceptron_test)
include(CheckFunctionExists)
include(CheckCXXSourceCompiles)
include(CheckLibraryExists)
include(CPack)
enable_testing()
# Set Include h file path
#INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include/  ${PROJECT_SOURCE_DIR}/include/OXDeepNN)
set(OXDeepNN_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/source
                        ${PROJECT_SOURCE_DIR}/include
                        ${PROJECT_SOURCE_DIR}/include/OXDeepNN)
INCLUDE_DIRECTORIES(${OXDeepNN_INCLUDE_DIR})
#
# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)

set(EXECUTABLE_OUTPUT_PATH  "${PROJECT_SOURCE_DIR}/bin/demo_bin/perceptron")
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
# Set source file to make executable
#add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp )
add_executable(perceptron_test perceptron.cpp)
# Set QT5 module which we used
qt5_use_modules(perceptron_test Core Widgets Gui OpenGL PrintSupport)

set(EXECUTABLE_OUTPUT_PATH  "${PROJECT_SOURCE_DIR}/bin/ctest_bin")
#message(STATUS "#CTEST#EXECUTABLE_OUTPUT_PATH=${EXECUTABLE_OUTPUT_PATH}")
#message(STATUS "#CTEST#CMAKE_BINARY_DIR=${CMAKE_BINARY_DIR}")
#message(STATUS "#CTEST#CMAKE_RUNTIME_OUTPUT_DIRECTORY=${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
#message(STATUS "#CTEST#PROJECT_BINARY_DIR=${PROJECT_BINARY_DIR}")

add_test(perceptron_test perceptron_test)

