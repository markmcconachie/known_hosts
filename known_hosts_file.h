#ifndef _known_hosts_file_h
#define _known_hosts_file_h

#define KNOWN_HOSTS_PATH "/.ssh/known_hosts"

#include <stdio.h>

FILE *get_file(char* mode); 

#endif