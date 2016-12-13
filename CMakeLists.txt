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


#cmake_minimum_required(VERSION 2.6)
#PROJECT(Rugal CXX)
#SET(SRC_LIST src/main.c src/implmentation/sort.c src/implmentation/stack.c)
#SET(SRC_LIST src/main.cpp)
#INCLUDE_DIRECTORIES(src/header)
#message(${PROJECT_SOURCE_DIR})
#ADD_EXECUTABLE(Rugal ${SRC_LIST})
#SET(CMAKE_CPP_FLAGS "-O0 -g -ggdb -Wall")
#SET(CMAKE_C_COMPILER gcc)
#SET(CMAKE_CPP_COMPILER g++)
#SET(CMAKE_CPP_COMPILER_ENV_VAR g++)
