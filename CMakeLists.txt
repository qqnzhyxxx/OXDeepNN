cmake_minimum_required(VERSION 2.8.11)
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
# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Set the path to build projcet
set(EXECUTABLE_OUTPUT_PATH  "${PROJECT_SOURCE_DIR}/bin")
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
INCLUDE_DIRECTORIES(include/)
# Install so file into usr/local/lib
message(STATUS "#CMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX}")

# Set GSL2.3 math lib libgsl.so+libgslcblas.so
# Set qcustomplot2.0 QT 2D plot lib libqcustomplot.so
# In Linux+GunCxx Compiler Environment
# "sudo cp XXXXX.so /usr/local/lib"
# "sudo ldconfig"
MESSAGE(STATUS "#operation system is ${CMAKE_SYSTEM}")
# Set lib in Linux+GunCxx Compiler Environment

IF (CMAKE_SYSTEM_NAME MATCHES "Linux")
    if(CMAKE_COMPILER_IS_GNUCXX)
        MESSAGE(STATUS "#COMPILER_IS_GNUCXX")   
        link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/lib-linux)
        target_link_libraries(${PROJECT_NAME}
            ${CMAKE_INSTALL_PREFIX}/lib/libgsl.so.19
            ${CMAKE_INSTALL_PREFIX}/lib/libgslcblas.so.0
            ${CMAKE_INSTALL_PREFIX}/lib/libqcustomplot.so.2)
    endif()
# Set lib in Windows Compiler Environment
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Windows")
    if(MSVC)
        MESSAGE(STATUS "#COMPILER_IS_MSVC")
        link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/lib-windows)
        target_link_libraries(${PROJECT_NAME}
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/lib-windows/libGSL/libgsl-19.lib
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/lib-windows/libGSL/libgslcblas-0.lib
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/lib-windows/libqcustomplot/qcustomplot2.lib)
        Add_Definitions(-DGSL_DLL)
        file(COPY  ${CMAKE_CURRENT_SOURCE_DIR}/lib/lib-windows/libGSL/libgsl-19.dll
                   ${CMAKE_CURRENT_SOURCE_DIR}/lib/lib-windows/libGSL/libgslcblas-0.dll
                   ${CMAKE_CURRENT_SOURCE_DIR}/lib/lib-windows/libqcustomplot/qcustomplot2.dll
             DESTINATION ${EXECUTABLE_OUTPUT_PATH})
    endif()
ENDIF ()

# Set folder in project dir
add_subdirectory(include)
add_subdirectory(src)
add_subdirectory(lib)
add_subdirectory(test)
#
#message(STATUS "EXECUTABLE_OUTPUT_PATH=${EXECUTABLE_OUTPUT_PATH}")
#message(STATUS "CMAKE_BINARY_DIR=${CMAKE_BINARY_DIR}")
