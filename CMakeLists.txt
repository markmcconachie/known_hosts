cmake_minimum_required(VERSION 3.4)
project(known_hosts)

add_definitions(-DUNICODE -D_UNICODE)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_definitions(-DUNICODE -D_UNICODE)
set(KnownHosts_VERSION "1.0.0")
set(KnownHosts_FILE_LOCATION "/.ssh/known_hosts")

configure_file (
        "include/config.h.in"
        "${PROJECT_BINARY_DIR}/config.h"
)

include_directories(include)
include_directories("${PROJECT_BINARY_DIR}")


set(SOURCES src/main.c src/display.c  src/commands.c src/known_hosts_file.c)
add_executable(known_hosts ${SOURCES})

install (TARGETS known_hosts DESTINATION bin)