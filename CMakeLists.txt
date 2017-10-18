#CPP
cmake_minimum_required(VERSION 3.0)
project (Lab3 CXX)

# just for example add some compiler flags
SET(CMAKE_CXX_FLAGS "-O0 -std=c++11 -g -ggdb -Wall -Wfloat-conversion -fno-elide-constructors")
SET(CMAKE_CXX_COMPILER g++)
SET(CMAKE_CXX_COMPILER_ENV_VAR g++)

INCLUDE_DIRECTORIES(src/header)
file(GLOB_RECURSE source "src/main.cpp" "src/implement/*.cpp")
message(${source})
add_executable(Lab3 ${source})
