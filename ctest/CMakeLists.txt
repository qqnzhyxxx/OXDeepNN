#************************************************#
#                                                #
#       this cmakelist build for  ctesting       #
#                                                #
#************************************************#
cmake_minimum_required(VERSION 2.8.11)
set(CMAKE_CXX_STANDARD 14)

include(CheckFunctionExists)
include(CheckCXXSourceCompiles)
include(CheckLibraryExists)
include(CPack)
enable_testing()

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
# Set source file to make executable
#add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp )
add_executable(perceptron_test perceptron.cpp)
# Set QT5 module which we used
qt5_use_modules(perceptron_test Core Widgets Gui OpenGL PrintSupport)

# Set Include h file path
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include/  ${PROJECT_SOURCE_DIR}/include/OXDeepNN)

IF (CMAKE_SYSTEM_NAME MATCHES "Linux")
    if(CMAKE_COMPILER_IS_GNUCXX)
        MESSAGE(STATUS "#COMPILER_IS_GNUCXX")
        link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/lib-linux)
        target_link_libraries(perceptron_test
            ${CMAKE_INSTALL_PREFIX}/lib/libgsl.so.19
            ${CMAKE_INSTALL_PREFIX}/lib/libgslcblas.so.0
            ${CMAKE_INSTALL_PREFIX}/lib/libqcustomplot.so.2)
    endif()
# Set lib in Windows Compiler Environment
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Windows")
    if(MSVC)
        MESSAGE(STATUS "#COMPILER_IS_MSVC")
        link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/lib-windows)
        target_link_libraries(perceptron_test
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/lib-windows/libGSL/libgsl-19.lib
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/lib-windows/libGSL/libgslcblas-0.lib
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/lib-windows/libqcustomplot/qcustomplot2.lib)
        Add_Definitions(-DGSL_DLL)
        file(COPY  ${CMAKE_CURRENT_SOURCE_DIR}/lib/lib-windows/libGSL/libgsl-19.dll
                   ${CMAKE_CURRENT_SOURCE_DIR}/lib/lib-windows/libGSL/libgslcblas-0.dll
                   ${CMAKE_CURRENT_SOURCE_DIR}/lib/lib-windows/libqcustomplot/qcustomplot2.dll
             DESTINATION ${EXECUTABLE_OUTPUT_PATH}/ctest_bin/)
    endif()
ENDIF ()


add_test(perceptron_test perceptron_test)

