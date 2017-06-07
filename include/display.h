/**
 * @file display.h
 * @author Mark McConachie
 * @date March 25 2016
 * @brief Displays pretty output on the command line
 */

#pragma once

/**
 * @brief Display an error
 *
 * Print an error to STDOUT in red
 * @warning This will also exit the program as errors are considered fatal!
 */
void display_error(const char *error);

/**
 * @brief Display a host
 *
 * Prints a formatted host to STDOUT
 */
void display_host(const char *host);

/**
 * @brief Display usage
 *
 * Displays usage for the CLI
 */
void display_usage(const char *option);
