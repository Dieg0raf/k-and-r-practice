#include <stdio.h>

// returns the first location in the string s1 where any character from the string s2 occurs
int any(char s1[], char s2[]) {
    int i, y, match = 0;
    for (i = 0; s1[i] != '\0'; i++) {
        for (y = 0; s2[y] != '\0'; y++) {
            if (s2[y] == s1[i]) {
                match = 1;
                break;
            }
        }
        if (match == 1) {
            return i;
        }
    }
    return -1;
}

int main(int argc, char *argv[]) {
    char s1[] = "";
    char s2[] = "abc";
    int index = any(s1, s2);
    if (index != -1) {
        printf("Characters match at index %d in %s with %s.\n", index, s1, s2);
    } else {
        printf("No characters from %s found in %s.\n", s1, s2);
    }
    return 0;
}
