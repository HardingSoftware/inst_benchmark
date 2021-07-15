project(benchmark)
cmake_minimum_required(VERSION 3.11)
ENABLE_LANGUAGE(ASM)

set(val 0)

option(flag ON)

if(SYSTEM.Windows)
    
endif()

#set(CMAKE_C_COMPILER "gcc")
#set(CMAKE_CXX_COMPILER "g++")
#set(CMAKE_C_FLAGS "-mfma")
add_executable(benchmark main.c)
