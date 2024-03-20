#include "header.h"

// Global variables
int matches = 0;            // Counter for printing number of matched lines
int lineNumbers = 0;        // Flag to indicate whether to print line numbers

int main(int argc, char *argv[]) {
    // Check if minimum arguments are provided
    if (argc < 3) {
        printf("Usage: %s <Pattern> <-option><File1> [<File2> ...] <-option>\n", argv[0]);
        return 1;
    }

    // Define command line option flags
    int ignoreCase = 0;     // -i
    int countMatches = 0;   // -c
    int exactWord = 0;      // -w

    // Make a mutable copy of the search pattern
    char *pattern = strdup(argv[1]);
    regex_t regex;

    // Compile the regex pattern
    if (regcomp(&regex, pattern, REG_EXTENDED | REG_ICASE) != 0) {
        printf("Error: Invalid regular expression\n");
        return 1;
    }

    // Use mutable copy for strtok
    char *word = pattern;

    // Parsing command line arguments
    int i = 2;
    while (i < argc) {
        if (strcmp(argv[i], "-i") == 0) {
            ignoreCase = 1;
        } else if (strcmp(argv[i], "-c") == 0) {
            countMatches = 1;
        } else if (strcmp(argv[i], "-n") == 0) {
            lineNumbers = 1;
        } else if (strcmp(argv[i], "-w") == 0) {
            exactWord = 1;
        } else {
            break;  // Found the search pattern, exit loop
        }
        i++;
    }

    i = 2;  // Reset the argument counter
    while (i < argc) {
        FILE *file = fopen(argv[i], "r");
        if (file != NULL) {
            char buffer[1024];
            while (fgets(buffer, sizeof(buffer), file) != NULL) {
                printHighlighted(buffer, &regex, argv[i]);
            }
            fclose(file);
            // Print number of matched lines if -c option is provided
            if (countMatches) {
                printf("\033[038;5;206mNo. of matched Lines:%d\033[0m\n", matches);
                matches = 0;
            }
        }
        i++;
    }

    // Free memory
    free(pattern);  // Free allocated memory for mutable copy of search pattern
    regfree(&regex); // Free regex structure
    return 0;
}
