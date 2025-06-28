#include <stdio.h>

const int LIM = 10;

int main(int argc, char *argv[]) {
    int i = 0, c;
    char s[LIM];
    while (i < LIM - 1) {
        if ((c = getchar()) == '\n') {
            break;
        }

        if (c == EOF) {
            break;
        }
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    printf("%s\n", s);
    return 0;
}
