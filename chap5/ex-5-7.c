#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 2
char *lineptr[MAXLINES];

int myReadlines(char *lineptr[], int maxlines, char *buf) {
    int nlines, offset = 0;
    char *p = NULL, *line = NULL;
    size_t len, maxlen = 1000;

    nlines = 0;
    while ((len = getline(&line, &maxlen, stdin)) > 1) {
        if (nlines >= maxlines) {
            return -1;
        } else {
            line[len - 1] = '\0';
            strcpy((buf + offset), line);
            lineptr[nlines++] = buf + offset;
            offset += len;
        }
    }
    return nlines;
}

void writelines(char *lineptr[], int nlines) {
    int i;
    for (i = 0; i < nlines; i++) {
        printf("%s\n", lineptr[i]);
        // free(lineptr[i]);   // freeing allocated memory
        // lineptr[i] = NULL;  // prevent reuse
    }
}

int main(int argc, char *argv[]) {
    int nlines;
    // store lines inside this allocated buffer instead of using malloc
    char buffer[10000];
    if ((nlines = myReadlines(lineptr, MAXLINES, buffer)) >= 0) {
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}
