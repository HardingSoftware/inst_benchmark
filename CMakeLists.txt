project(benchmark)
cmake_minimum_required(VERSION 3.11)
ENABLE_LANGUAGE(ASM)

set(val 0)

option(flag ON)

if(SYSTEM.Windows)
    
endif()

add_executable(benchmark main.c)
