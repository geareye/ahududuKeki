cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(GPIO_Blink)
#set(CMAKE_BUILD_TYPE Release)
set(CMAKE_BUILD_TYPE Debug)


#SET(CMAKE_CXX_FLAGS_DEBUG "-O0")
#SET(CMAKE_C_FLAGS_DEBUG "-O0")


include_directories(../include)

include_directories(/usr/local/lib)


file(GLOB SOURCES "../src/*.cpp")
#file(GLOB_RECURSE SOURCES "../src/*.cpp")
#file(GLOB_RECURSE SOURCES "../src/*.cpp")

add_executable(GPIO_Blink ${SOURCES})


include_directories(../../bcm2835library/bcm2835-1.40/src)

add_library(bcm2835 STATIC IMPORTED)
set_property(TARGET bcm2835 PROPERTY IMPORTED_LOCATION /usr/local/lib/libbcm2835.a)
add_dependencies(bcm2835 libbcm2835)

target_link_libraries(GPIO_Blink bcm2835)

