#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100

int tail(int nLines) {
    char *line = NULL, *walk = NULL;
    size_t linecap = MAX_LENGTH;
    ssize_t length;
    char* p = NULL;
    int i, s;
    while ((length = getline(&line, &linecap, stdin)) > 1) {
        printf("Lenght of new line: %lu\n", length);
        if (length < nLines || (p = malloc(MAX_LENGTH)) == NULL) {
            fprintf(stderr, "Line length is too long");
            return 1;
        }
        walk = line;  // setting 'walk' to 'line' since getline() can't have 'line' not be in the initial spot it points
                      // to (causes Undefined Behavior)
        for (; *walk != '\0'; walk++) {
        }

        for (i = 1, s = 0; i < length && i <= nLines; i++, s++) {
            *(p + s) = *(walk - i);
        }

        *(p + s) = '\0';
        printf("String backwards: %s\n", p);
        free(p);
        p = NULL;
    }
    return 0;
}

int main(int argc, char* argv[]) {
    int nlines = 10, hasNumber = 0;
    char c;
    while (--argc > 0 && (*++argv)[0] == '-') {
        while ((c = *++argv[0])) {
            switch (c) {
                case 'n':
                    hasNumber = 1;
                    break;
                default:
                    fprintf(stderr, "illegal option %c\n", c);
                    break;
            }
        }
        if (hasNumber) {
            nlines = atoi(*++argv);
            hasNumber = 0;
            argc--;
        }
    }
    return tail(nlines);
}
