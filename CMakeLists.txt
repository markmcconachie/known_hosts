cmake_minimum_required(VERSION 3.4)
project(known_hosts)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(KnownHosts_VERSION "1.0.0")
set(KnownHosts_FILE_LOCATION" "/.ssh/known_hosts"")

configure_file (
        "${PROJECT_SOURCE_DIR}/KnownHostsConfig.h.in"
        "${PROJECT_BINARY_DIR}/KnownHostsConfig.h"
)

include_directories("${PROJECT_BINARY_DIR}")

set(SOURCE_FILES main.c display.c display.h commands.c commands.h known_hosts_file.c known_hosts_file.h)
add_executable(known_hosts ${SOURCE_FILES})