#pragma once

#define MAX_LINE_LENGTH 1024
#define MAX_HOST_LENGTH 128
#define MAX_LINES 1024

enum found_states {
    KH_NOT_FOUND,
    KH_FOUND
};

void commands_ls_hosts();
void commands_rm_host(char *hostToRm);