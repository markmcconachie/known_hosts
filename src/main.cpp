#include <stdio.h>
#include <string.h>
#include <iostream>

#include "config.h"
#include "commands.h"
#include "display.h"

int arg_matches(char *arg,const char *command) {
    return strcmp(arg, command) == 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) display_usage(NULL);

    if (arg_matches(argv[1], "ls")) {
        commands_ls_hosts();
    } else if (arg_matches(argv[1], "rm")) {
        if (argc != 3) display_usage("Host required");
        commands_rm_host(argv[2]);
    } else if (arg_matches(argv[1], "version")) {
        /* printf("Version "VERSION "\n"); */
        std::cout << "Version " << VERSION << std::endl;

    } else if (arg_matches(argv[1], "help")) {
        display_usage(NULL);
    } else {
        display_usage(argv[1]);
    }

    return 0;
}
