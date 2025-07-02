#include <stdio.h>
#include <string.h>

void expand(char s1[], char s2[]) {
    char f, b;
    int i, j, c, length = strlen(s1);
    for (i = j = c = 0; i < length; i = j, i++) {
        if (i == 0 && s1[i] == '-') {
            s2[c++] = '-';
            continue;
        }
        for (j = i + 1; j < length; j++) {
            if (s1[j] != '-') {
                b = s1[j];
                break;
            }
        }

        if (i + 1 == length - 1 && s1[i + 1] == '-' || i == length - 1 && s1[i] == '-') {
            s2[c++] = '-';
        } else {
            if (s1[i] == '-') {
                i++;
            }
            f = s1[i];
            for (int x = f; x <= b; x++, c++) {
                s2[c] = x;
            }
        }
        i = j;
    }
    s2[c] = '\0';
    printf("s2 = %s\n", s2);
}

int main(int argc, char* argv[]) {
    // char s1[] = "-a-z0-9";
    char s1[] = "-0-9a-z-";
    char s2[100];
    expand(s1, s2);
    return 0;
}
