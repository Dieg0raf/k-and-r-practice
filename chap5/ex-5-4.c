#include <stdio.h>
#include <string.h>

int strend(char* s, char* t) {
    // early check to see if 't' is greater than 's'
    if (strlen(t) > strlen(s)) {
        return 0;
    }
    char* start = t;

    // move pointer to end of string
    for (; *s != '\0'; s++) {
    }
    for (; *t != '\0'; t++) {
    }

    // compare from the end
    while (*--t == *--s) {
    }

    // check if 'start' address is the same as where 't' is at
    if (t == --start) {
        return 1;
    }
    return 0;
}

int main(int argc, char* argv[]) {
    char s[] = "helloworld";
    char t[] = "rld";
    printf("Strend result: %d\n", strend(s, t));
    return 0;
}
