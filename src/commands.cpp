#include <stdio.h>
#include <string.h>
#ifdef __APPLE__
#include <MacTypes.h>
#else
#define false 0
#endif

#include "commands.h"
#include "known_hosts_file.h"
#include "config.h"
#include "display.h"

int extract_host_from_string(char *host, char *line) {
    size_t index = strchr(line, ' ') - line;
    if (index > 128) {
            printf("Index out of bounds for host: %s - Skipping\n", host);
            return 128;
    }
    strncpy(host, line, index);
    host[index] = '\0';
    return 0;
}

void commands_ls_hosts() {
    FILE *file = known_hosts_file_get("r");
    if (file == NULL)
        display_error("No known_hosts file found.");

    puts("Current known hosts:");

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file) != NULL) {
        char host[MAX_HOST_LENGTH];
        extract_host_from_string(host, line);
        display_host(host);
    }

    fclose(file);
}

int hostOrIpMatches(char *host, char *hostToRm) {
    const char separator[2] = ",";

    char *hostname = strtok(host, separator);
    char *ip = strtok(NULL, separator);

    int hostnameMatched = (strcmp(hostname, hostToRm) == 0);

    int ipMatched = false;
    if (ip != NULL)
        ipMatched = (strcmp(ip, hostToRm) == 0);

    return (hostnameMatched || ipMatched);
}

void commands_rm_host(char *hostToRm) {
    FILE *file = known_hosts_file_get("r");
    if (file == NULL)
        display_error("No known_hosts file found.");

    char lines[MAX_LINES][MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];

    int line_number = 0;
    int i;

    int found = KH_NOT_FOUND;

    while (fgets(line, sizeof(line), file) != NULL) {
        char host[MAX_HOST_LENGTH];
        extract_host_from_string(host, line);

        if (hostOrIpMatches(host, hostToRm)) {
            printf(ANSI_COLOR_GREEN "Removing host: %s" ANSI_COLOR_RESET "\n", host);
            found = KH_FOUND;
        } else {
            strncpy(lines[line_number], line, sizeof(line));
            line_number++;
        }
    }
    fclose(file);

    if (found == KH_NOT_FOUND)
        display_error("Specified host is not already known.");

    file = known_hosts_file_get("w+");
    if (file == NULL)
        display_error("Can't open known_hosts file.");

    for (i = 0; i <= line_number; i++) {
        fprintf(file, "%s", lines[i]);
    }
    fclose(file);
}
