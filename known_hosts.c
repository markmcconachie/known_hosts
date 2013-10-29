#include <stdlib.h>

#include "commands.h"
#include "display.h"
#include "utils.h"

int main(int argc, char* argv[]) {
    if (argc < 2) show_usage(NULL);

    if (arg_matches(argv[1], "ls")) {
        list_hosts();
    } else if(arg_matches(argv[1], "rm")) {
        if (argc != 3) show_usage("Host required");
        rm_host(argv[2]);
    } else if(arg_matches(argv[1], "help")) {
        show_usage(argv[1]);
    } else {
        show_usage(argv[1]);
    }

    return 0;
}