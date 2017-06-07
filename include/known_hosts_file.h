/**
 * @file known_hosts_file.h
 * @author Mark McConachie
 * @date March 25 2016
 * @brief Handles a known_hosts file
 */

#pragma once

#include <stdio.h>

/**
 * @brief Get the known_hosts file
 *
 * @param mode the mode to open the file with
 */
FILE *known_hosts_file_get(const char *mode);
