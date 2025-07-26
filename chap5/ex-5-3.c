#include <stdio.h>

void mystrcat(char* s, char* t) {
    // puts pointer 's' to point to the end of string 's'
    for (; *s != '\0'; s++) {
    }

    // Puts the whole 't' string into 's', starting at the end of 's' ('\0' of s)
    for (; *t != '\0'; t++, s++) {
        *s = *t;
    }
}

int main(int argc, char* argv[]) {
    char s[50] = "Diego-";
    char t[50] = "Sofia";
    mystrcat(s, t);
    printf("output after mystrcat: %s\n", s);
    return 0;
}
