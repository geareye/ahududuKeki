cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(GPIOBlinkTestLibrary)
#set(CMAKE_BUILD_TYPE Release)
set(CMAKE_BUILD_TYPE Debug)


#SET(CMAKE_CXX_FLAGS_DEBUG "-O0")
#SET(CMAKE_C_FLAGS_DEBUG "-O0")


include_directories(include)
#include_directories(includeCopy)

file(GLOB SOURCES "src/*.cpp")
#file(GLOB_RECURSE SOURCES "src/*.cpp")
#file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(GPIO_Blink ${SOURCES})

