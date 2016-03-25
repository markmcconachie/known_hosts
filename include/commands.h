/**
 * @file commands.h
 * @author Mark McConachie
 * @date March 25 2016
 * @brief Implements the commands exposed to the CLI
 */

#pragma once

/**
 * States for whether a host was found within the known hosts file
 */
enum host_found_states {
    KH_NOT_FOUND, /**< The host was not found. */
    KH_FOUND /**< The host was  found. */
};

/**
 * @brief Outputs a list of hosts
 *
 * Parses the known_hosts file and outputs formatted list of hosts
 */
void commands_ls_hosts();

/**
 * @brief Outputs a list of hosts
 *
 * Removes a host from the known_hosts file
 *
 * @param hostToRm the name of the host to remove
 */
void commands_rm_host(char *hostToRm);