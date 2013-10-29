#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KNOWN_HOSTS_PATH "/.ssh/known_hosts"
#define MAX_LINE_LENGTH 1024
#define MAX_HOST_LENGTH 128
#define MAX_LINES 1024

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

static int argMatches(char* arg, char* command) {
    return strcmp(arg, command) == 0;
}

static void rmHost(char *hostToRm) {
    FILE *file = getFile("r");
    if (file == NULL) printError("No known_hosts file found.");


    char lines[MAX_LINES][MAX_LINE_LENGTH];
    char line [MAX_LINE_LENGTH];
    int lineNumber = 0;
    int found = 0;

    while (fgets (line, sizeof(line), file) != NULL) {
        char host[MAX_HOST_LENGTH];
        extractHostFromString(host, line);

        if (strcmp(host, hostToRm) == 0) {
            printf(ANSI_COLOR_GREEN "Removing host: %s" ANSI_COLOR_RESET "\n", host);
            found = 1;
        } else {
            strncpy(lines[lineNumber], line, sizeof(line));
            lineNumber++;
        }    
    }
    fclose (file);

    if (!found) printError("Specified host is not already known.");

    file = getFile("w+");
    if (file == NULL) printError("No opening known_hosts file.");

    for (int i = 0; i <= lineNumber; i++) {
        fprintf(file, "%s", lines[i]);
    }
    fclose (file);

}

static void showUsage(char *option) {
    if (option != NULL) printf(ANSI_COLOR_RED "Unknown option: %s" ANSI_COLOR_RESET "\n", option);

    printf("\nusage: known_hosts command [host]\n");
    printf("  commands:\n");
    printf("      ls - List all known hosts\n");
    printf("      rm - Remove a host [requires host]\n");
    printf("\n");
    exit(1);
}

int main(int argc, char* argv[]) {
    if (argc < 2) showUsage(NULL);

    if (argMatches(argv[1], "ls")) {
        listHosts();
    } else if(argMatches(argv[1], "rm")) {
        if (argc != 3) showUsage("Host required");
        rmHost(argv[2]);
    } else {
        showUsage(argv[1]);
    }

    return 0;
}