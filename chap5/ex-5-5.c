#include <stdio.h>

// Append at most n chars of t to s
void myStrncpy(char* s, char* t, int n) {
    for (int i = 0; i < n && (*s = *t) != '\0'; i++, t++, s++) {
    }
    *s = '\0';  // null terminate
}

// Appends at most n chars of t to the end of string s
void myStrncat(char* s, char* t, int n) {
    for (; *s != '\0'; s++) {
    }

    for (int i = 0; i < n && (*s = *t) != '\0'; i++, t++, s++) {
    }
    *s = '\0';  // null terminate
}

// compares at most the first n characters of strings s1 and s2
int myStrncmp(char* s1, char* s2, int n) {
    int i;
    for (i = 0; i < n && *s1 == *s2; i++, s1++, s2++) {
    }

    if (i != n && *s1 != *s2) {
        return *s1 - *s2;
    }

    if (i == n && *--s1 != *--s2) {
        return *s1 - *s2;
    }

    return 0;
}

int main(int argc, char* argv[]) {
    char s1[] = "a";
    char s2[] = "a";
    printf("outputed final: %d\n", myStrncmp(s1, s2, 0));
    return 0;
}
