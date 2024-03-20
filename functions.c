#include "header.h"

extern int lineNumbers;  // Declaration of lineNumbers as an extern variable

// Function to print highlighted occurrences of pattern
void printHighlighted(const char *line, regex_t *regex, const char *filename) {
    regmatch_t match;
    const char *cursor = line;
    int print = 0;
    static int line_number = 0;

    while (regexec(regex, cursor, 1, &match, 0) == 0) {
        if (print == 0) {
            printf("\e[38;5;208m%s: \e[0m", filename);   // Print filename
            if (lineNumbers == 1)
                printf("\e[32m%d:\e[0m", line_number);
            print = 1;
        }

        fwrite(cursor, 1, match.rm_so, stdout);
        fputs(Rd, stdout);
        fwrite(cursor + match.rm_so, 1, match.rm_eo - match.rm_so, stdout);
        fputs(RESET, stdout);

        cursor += match.rm_eo;
    }

    if (print)
        printf("%s", cursor);
    line_number++;
}
