#include <stdlib.h>
#include <string.h>

#include "known_hosts_file.h"

static char* get_file_path() {
    static char localfilename[80];
    strncpy(localfilename,"", sizeof(char));
    strcat(localfilename, getenv("HOME"));
    strcat(localfilename, KNOWN_HOSTS_PATH);
    return localfilename;
}

FILE* known_hosts_file_get(char *mode) {
    return fopen(get_file_path(), mode);
}