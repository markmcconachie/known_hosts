cmake_minimum_required(VERSION 3.4)
project(known_hosts)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c display.c display.h commands.c commands.h utils.c utils.h known_hosts_file.c known_hosts_file.h)
add_executable(known_hosts ${SOURCE_FILES})