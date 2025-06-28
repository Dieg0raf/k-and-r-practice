#include <stdio.h>

// deletes character in s1 that matches any character in s2
void squeeze(char s1[], char s2[]) {
    int i, j, y, match = 0;
    for (i = j = 0; s1[i] != '\0'; i++) {
        for (y = 0; s2[y] != '\0'; y++) {
            if (s2[y] == s1[i]) {
                match = 1;
                break;
            }
        }
        if (match == 0) {
            s1[j++] = s1[i];
        } else {
            match = 0;
        }
    }
    s1[j] = '\0';
    printf("%s\n", s1);
}

int main(int argc, char* argv[]) {
    char s1[] = "banana";
    char s2[] = "apple";
    squeeze(s1, s2);
    return 0;
}
