#include <stdio.h>
#include <stdlib.h>

#include "display.h"

void print_error(char *error) {
    printf(ANSI_COLOR_RED "ERROR: %s" ANSI_COLOR_RESET "\n", error);
    exit(1);
}

void print_host(char *host) {
    printf("\t" ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET "\n", host);
}

void show_usage(char *option) {
    if (option != NULL) printf(ANSI_COLOR_RED "Unknown option: %s" ANSI_COLOR_RESET "\n", option);

    printf("\nusage: known_hosts command [host]\n");
    printf("  commands:\n");
    printf("    ls      - List all known hosts\n");
    printf("    rm      - Remove a host [requires host]\n");
    printf("    version - Display current version\n");
    printf("    help    - Show this message\n");
    printf("\n");
    exit(1);
}