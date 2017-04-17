#************************************************#
#                                                #
#       this cmakelist build for  ctesting       #
#                                                #
#************************************************#
cmake_minimum_required(VERSION 2.8.11)
set(CMAKE_CXX_STANDARD 14)
#set(TEST_NAME_PERCEPTRON perceptron_test)

include(CheckFunctionExists)
include(CheckCXXSourceCompiles)
include(CheckLibraryExists)
include(CPack)
enable_testing()
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
# Set Include h file path
#INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include/  ${PROJECT_SOURCE_DIR}/include/OXDeepNN)
set(OXDeepNN_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/include/OXDeepNN)
INCLUDE_DIRECTORIES(${OXDeepNN_INCLUDE_DIR})
# Set lib_dir in Environment
# Set GSL2.3 math lib <libgsl.so+libgslcblas.so>
# Set qcustomplot2.0 QT 2D plot lib <libqcustomplot.so>
# In Linux+GunCxx Compiler Environment
# "sudo cp /lib/lib-linux/../*.so  /usr/local/lib"
# "sudo ldconfig"
set(OXDeepNN_LINK_LINUX_GXX
    ${CMAKE_INSTALL_PREFIX}/lib/libgsl.so.19
    ${CMAKE_INSTALL_PREFIX}/lib/libgslcblas.so.0
    ${CMAKE_INSTALL_PREFIX}/lib/libqcustomplot.so.2)
# Set GSL2.3 math lib <libgsl.dylib+libgslcblas.dylib>
# Set qcustomplot2.0 QT 2D plot lib <libqcustomplot.dylib>
# In Mac os+GunCxx Compiler Environment
# "sudo cp /lib/lib-mac/../*.dylib  /usr/local/lib"
# "  export DYLD_LIBRARY_PATH="$DYLD_LIBRARY_PATH:/usr/local/lib/"   "
set(OXDeepNN_LINK_MAC_GXX
    ${CMAKE_INSTALL_PREFIX}/lib/libgsl.19.dylib
    ${CMAKE_INSTALL_PREFIX}/lib/libgslcblas.0.dylib
    ${CMAKE_INSTALL_PREFIX}/lib/libqcustomplot.2.0.0.dylib)
set(OXDeepNN_LINK_MSVCLIB_RELEASE
    ${PROJECT_SOURCE_DIR}/lib/lib-windows/libGSL/libgsl-19.lib
    ${PROJECT_SOURCE_DIR}/lib/lib-windows/libGSL/libgslcblas-0.lib
    ${PROJECT_SOURCE_DIR}/lib/lib-windows/libqcustomplot/qcustomplot2.lib)
set(OXDeepNN_LINK_MSVCDLL_RELEASE
    ${PROJECT_SOURCE_DIR}/lib/lib-windows/libGSL/libgsl-19.dll
    ${PROJECT_SOURCE_DIR}/lib/lib-windows/libGSL/libgslcblas-0.dll
    ${PROJECT_SOURCE_DIR}/lib/lib-windows/libqcustomplot/qcustomplot2.dll)
set(OXDeepNN_LINK_MSVCLIB_DEBUG
    ${PROJECT_SOURCE_DIR}/lib/lib-windows/libGSL/libgsl-19.lib
    ${PROJECT_SOURCE_DIR}/lib/lib-windows/libGSL/libgslcblas-0.lib
    ${PROJECT_SOURCE_DIR}/lib/lib-windows/libqcustomplot/qcustomplotd2.lib)
set(OXDeepNN_LINK_MSVCDLL_DEBUG
    ${PROJECT_SOURCE_DIR}/lib/lib-windows/libGSL/libgsl-19.dll
    ${PROJECT_SOURCE_DIR}/lib/lib-windows/libGSL/libgslcblas-0.dll
    ${PROJECT_SOURCE_DIR}/lib/lib-windows/libqcustomplot/qcustomplotd2.dll)
# Set lib in Linux+GunCxx Compiler Environment
IF (CMAKE_SYSTEM_NAME MATCHES "Linux")
    if(CMAKE_COMPILER_IS_GNUCXX)
        MESSAGE(STATUS "#COMPILER_IS_LINUX_GNUCXX")
        target_link_libraries(perceptron_test ${OXDeepNN_LINK_LINUX_GXX})
    endif()
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Darwin")
        MESSAGE(STATUS "#SYSTEM_NAME_IS_MAC_Darwin")
        target_link_libraries(perceptron_test ${OXDeepNN_LINK_MAC_GXX})
# Set lib in Windows Compiler Environment
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Windows")
    if(MSVC)
        MESSAGE(STATUS "#CTEST#COMPILER_IS_MSVC")
        target_link_libraries(perceptron_test debug ${OXDeepNN_LINK_MSVCLIB_DEBUG})
        target_link_libraries(perceptron_test optimized ${OXDeepNN_LINK_MSVCLIB_RELEASE})
        file(COPY ${OXDeepNN_LINK_MSVCDLL_RELEASE} DESTINATION ${EXECUTABLE_OUTPUT_PATH})
        file(COPY ${OXDeepNN_LINK_MSVCDLL_DEBUG} DESTINATION ${EXECUTABLE_OUTPUT_PATH})
        Add_Definitions(-DGSL_DLL) 
    endif()
ENDIF ()


add_test(perceptron_test perceptron_test)

