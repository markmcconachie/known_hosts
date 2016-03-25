#include <stdlib.h>
#include <string.h>

#include "known_hosts_file.h"
#include "config.h"

static char* get_file_path() {
    static char localfilename[80];
    strncpy(localfilename,"", sizeof(char));
    strcat(localfilename, getenv("HOME"));
    strcat(localfilename, KnownHosts_FILE_LOCATION);
    return localfilename;
}

FILE* known_hosts_file_get(char *mode) {
    return fopen(get_file_path(), mode);
}