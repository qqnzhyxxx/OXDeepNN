#************************************************#
#                                                #
# Copyright (C) 2017  Niu Zhiyong (China)        #
# <tbnzhyxxx@163.com>                            #
#                                                #
#************************************************#
cmake_minimum_required(VERSION 2.8.11)
message(STATUS "#CMAKE_VERSION=${CMAKE_VERSION}")
# Set project name
project(OXDeepNN)
# Set  C++ standard version
set(CMAKE_CXX_STANDARD 14)
# Let cpp and h file show in project without do noting
FILE(GLOB_RECURSE SrcFiles "*.cpp")
add_custom_target(SrcFilesShow SOURCES ${SrcFiles})
FILE(GLOB_RECURSE HeadFiles "*.h")
add_custom_target(HeadFilesShow SOURCES ${HeadFiles})
# Set src file list
aux_source_directory (${CMAKE_CURRENT_SOURCE_DIR}/src SRC_LIST)
aux_source_directory (${CMAKE_CURRENT_SOURCE_DIR}/src/QTsrc QTSRC_LIST)
#message(STATUS "#QTSRC_LIST=${QTSRC_LIST}")
#
# Set if build test file or not
option(BUILD_TESTS "Build tests." TRUE)
if (BUILD_TESTS)
    enable_testing()
    add_subdirectory(ctest ctest_bin)
endif()
# Set folder in project dir
add_subdirectory(include)
add_subdirectory(src)
add_subdirectory(lib)
add_subdirectory(demo demo_bin)

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
#add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp )
add_executable(${PROJECT_NAME} ${SRC_LIST} ${QTSRC_LIST})
# Set QT5 module which we used
qt5_use_modules(${PROJECT_NAME} Core Widgets Gui OpenGL PrintSupport)
#
# Set Include h file path
set(OXDeepNN_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/include/OXDeepNN)
#INCLUDE_DIRECTORIES(include/ include/OXDeepNN)
INCLUDE_DIRECTORIES(${OXDeepNN_INCLUDE_DIR})
message(STATUS "#OXDeepNN_INCLUDE_DIR=${OXDeepNN_INCLUDE_DIR}")
# Install so file into usr/local/lib
message(STATUS "#CMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX}")

# Set GSL2.3 math lib <libgsl.so+libgslcblas.so>
# Set qcustomplot2.0 QT 2D plot lib <libqcustomplot.so>
# In Linux+GunCxx Compiler Environment
# "sudo cp XXXXX.so /usr/local/lib"
# "sudo ldconfig"
MESSAGE(STATUS "#operation system is ${CMAKE_SYSTEM}")
# Set lib_dir in Environment
set(OXDeepNN_LINK_GXX
    ${CMAKE_INSTALL_PREFIX}/lib/libgsl.so.19
    ${CMAKE_INSTALL_PREFIX}/lib/libgslcblas.so.0
    ${CMAKE_INSTALL_PREFIX}/lib/libqcustomplot.so.2)
set(OXDeepNN_LINK_MSVCLIB
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/lib-windows/libGSL/libgsl-19.lib
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/lib-windows/libGSL/libgslcblas-0.lib
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/lib-windows/libqcustomplot/qcustomplot2.lib)
set(OXDeepNN_LINK_MSVCDLL
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/lib-windows/libGSL/libgsl-19.dll
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/lib-windows/libGSL/libgslcblas-0.dll
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/lib-windows/libqcustomplot/qcustomplot2.dll)
# Set lib in Linux+GunCxx Compiler Environment
IF (CMAKE_SYSTEM_NAME MATCHES "Linux")
    if(CMAKE_COMPILER_IS_GNUCXX)
        MESSAGE(STATUS "#COMPILER_IS_GNUCXX")   
        link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/lib-linux)
        target_link_libraries(${PROJECT_NAME} ${OXDeepNN_LINK_GXX})
    endif()
# Set lib in Windows Compiler Environment
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Windows")
    if(MSVC)
        MESSAGE(STATUS "#COMPILER_IS_MSVC")
        link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/lib-windows)
        target_link_libraries(${PROJECT_NAME} ${OXDeepNN_LINK_MSVCLIB})
        Add_Definitions(-DGSL_DLL)
        file(COPY ${OXDeepNN_LINK_MSVCDLL} DESTINATION ${EXECUTABLE_OUTPUT_PATH})
    endif()
ENDIF ()

#
#message(STATUS "EXECUTABLE_OUTPUT_PATH=${EXECUTABLE_OUTPUT_PATH}")
#message(STATUS "CMAKE_BINARY_DIR=${CMAKE_BINARY_DIR}")
