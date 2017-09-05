cmake_minimum_required(VERSION 3.8.0)

set(DEMO_NAME RosenPerceptron)
#
# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Add Qt module in project
set(OXDeepNN_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/source
                        ${PROJECT_SOURCE_DIR}/include
                        ${PROJECT_SOURCE_DIR}/include/OXDeepNN)
INCLUDE_DIRECTORIES(${OXDeepNN_INCLUDE_DIR})

set(EXECUTABLE_OUTPUT_PATH  "${PROJECT_SOURCE_DIR}/bin/demo_bin/Perceptron")
#message(STATUS "#DEMO#EXECUTABLE_OUTPUT_PATH=${EXECUTABLE_OUTPUT_PATH}")
#message(STATUS "#DEMO#CMAKE_BINARY_DIR=${CMAKE_BINARY_DIR}")
#message(STATUS "#DEMO#CMAKE_RUNTIME_OUTPUT_DIRECTORY=${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
#message(STATUS "#DEMO#PROJECT_BINARY_DIR=${PROJECT_BINARY_DIR}")

find_package(Qt5Core)
find_package(Qt5Widgets)
find_package(Qt5Gui)
find_package(Qt5OpenGL)
find_package(Qt5PrintSupport)
#find_package(Qt5Xml)
if(Qt5_POSITION_INDEPENDENT_CODE)
    set(CMAKE_POSITION_INDEPENDENT_CODE ON)
endif()
message(STATUS "#DEMO#Qt5Widgets_VERSION=${Qt5Widgets_VERSION}")
# Set source file to make executable
#add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp )
add_executable(${DEMO_NAME} RosenPerceptron.cpp
    ${PROJECT_SOURCE_DIR}/source/solver/Perceptronsolver.cpp
    ${PROJECT_SOURCE_DIR}/source/solver/LMSsolver.cpp
    ${PROJECT_SOURCE_DIR}/source/qcustomplot.cpp)
# Set QT5 module which we used
qt5_use_modules(${DEMO_NAME} Core Widgets Gui OpenGL PrintSupport)



