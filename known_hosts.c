#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KNOWN_HOSTS_PATH "/.ssh/known_hosts"
#define MAX_LINE_LENGTH 1024
#define MAX_HOST_LENGTH 128

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

static char* getFilePath() {
    static char localfilename[80];
    strcpy(localfilename,"");
    strcat(localfilename, getenv("HOME"));
    strcat(localfilename, KNOWN_HOSTS_PATH);
    return localfilename;
}

static FILE* getFile(char* mode) {
    return fopen(getFilePath(), mode);
}

static void printError(char *error) {
    printf(ANSI_COLOR_RED "ERROR: %s" ANSI_COLOR_RESET "\n", error);
    exit(1);
}

static void printHost(char *host) {
    printf("\t" ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET "\n", host);
}

static void extractHostFromString(char* host, char* line) {
    size_t index = strchr(line, ' ') - line;
    strncpy(host, line, index);
    host[index] = '\0';
}

static void listHosts () {
    FILE *file = getFile("r");
    if (file == NULL) printError("No known_hosts file found.");
    
    puts("Current known hosts:");

    char line [MAX_LINE_LENGTH];
    while (fgets (line, sizeof(line), file) != NULL) {
        char host[MAX_HOST_LENGTH];
        extractHostFromString(host, line);
        printHost(host);
    }

    fclose (file);
}

static void showUsage(char *option) {
    if (option != NULL) printf(ANSI_COLOR_RED "Unknown option: %s" ANSI_COLOR_RESET "\n\n", option);

    printf("usage: known_hosts [command]\n");
    printf("  options:\n");
    printf("      ls  -  List all known hosts\n\n");
}

int main(int argc, char* argv[]) {
    if (argc != 2) showUsage(NULL);

     if (strcmp(argv[1], "ls") == 0) {
        listHosts();
    } else {
        showUsage(argv[1]);
    }

    return 0;
}