#include <ctype.h>
#include <stdio.h>

int getint(int* pn) {
    int c, sign;

    // Skip whitespace
    while (isspace(c = getchar())) {
    }

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetc(c, stdin);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        c = getchar();
        if (!isdigit(c)) {
            ungetc(c, stdin);
            return 0;
        }
    }
    for (*pn = 0; isdigit(c); c = getchar()) {
        *pn = *pn * 10 + (c - '0');
    }
    *pn *= sign;
    if (c != EOF) {
        ungetc(c, stdin);
    }
    return c;
}

int main(int argc, char* argv[]) {
    int n, array[10];
    for (n = 0; n < 10 && getint(&array[n]) != EOF; n++) {
    }

    printf("\nValues entered:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", array[i]);
    }
    return 0;
}
