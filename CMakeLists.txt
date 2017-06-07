cmake_minimum_required(VERSION 3.4)
project(known_hosts)

add_definitions(-DUNICODE -D_UNICODE)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_definitions(-DUNICODE -D_UNICODE)

set(VERSION "1.0.0")
set(KNOWN_HOSTS_FILE_PATH "/.ssh/known_hosts")
set(MAX_LINE_LENGTH 1024)
set(MAX_HOST_LENGTH 128)
set(MAX_LINES 1024)
set(MAX_FILE_PATH_LENGTH 128)

configure_file(
        "include/config.h.in"
        "${PROJECT_BINARY_DIR}/config.h"
)

include_directories(include)
include_directories("${PROJECT_BINARY_DIR}")


set(SOURCES src/main.cpp src/display.cpp src/commands.cpp src/known_hosts_file.cpp)
add_executable(known_hosts ${SOURCES})

install(TARGETS known_hosts DESTINATION bin)
