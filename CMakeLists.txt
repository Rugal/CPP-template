#C
cmake_minimum_required(VERSION 2.8.7)
PROJECT(Rugal C)
SET(CMAKE_C_FLAGS "-O0 -ggdb -w -std=c99")
SET(CMAKE_C_COMPILER gcc)

INCLUDE_DIRECTORIES(
    ${CMAKE_CURRENT_SOURCE_DIR}/src/include
)

SET(SOURCE
    ${SOURCE}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/implement/Point.c
)
#SET(LIBRARIES libm.so)

FIND_PACKAGE(Curses REQUIRED)
ADD_EXECUTABLE(Rugal ${SOURCE})
TARGET_LINK_LIBRARIES(Rugal ${CURSES_LIBRARIES})

#CPP
cmake_minimum_required(VERSION 3.0)
project (Lab3 CXX)

# just for example add some compiler flags
SET(CMAKE_CXX_FLAGS "-O0 -std=c++11 -g -ggdb -Wall -Wfloat-conversion")
SET(CMAKE_CXX_COMPILER g++)
SET(CMAKE_CXX_COMPILER_ENV_VAR g++)

file(GLOB_RECURSE source src/main.cpp src/header/*.h src/implement/*.cpp)
message(${source})
add_executable(Lab3 ${source})
