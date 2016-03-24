#pragma once

#define KNOWN_HOSTS_PATH "/.ssh/known_hosts"

#include <stdio.h>

FILE *get_file(char* mode); 
