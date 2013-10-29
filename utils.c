#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

int arg_matches(char* arg, char* command) {
    return strcmp(arg, command) == 0;
}

void extract_host_from_string(char* host, char* line) {
    size_t index = strchr(line, ' ') - line;
    strncpy(host, line, index);
    host[index] = '\0';
}