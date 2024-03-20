#ifndef HEADER_H
#define HEADER_H

// Include necessary header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <regex.h>

// Define ANSI color codes for highlighting
#define Rd      "\e[1;91m"
#define RESET   "\e[0m"

// Function prototypes
void printHighlighted(const char *line, regex_t *regex, const char *filename);

#endif /* HEADER_H */
