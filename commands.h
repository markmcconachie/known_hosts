#ifndef _commands_h
#define _commands_h

#define MAX_LINE_LENGTH 1024
#define MAX_HOST_LENGTH 128
#define MAX_LINES 1024

#define KH_NOT_FOUND 0
#define KH_FOUND 1

void list_hosts();
void rm_host(char *hostToRm);

#endif