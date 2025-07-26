#include <ctype.h>
#include <stdio.h>

const int SIZE = 5;

double getfloat(double* pn) {
    int c, sign;
    double frac;

    // Skip whitespace
    while (isspace(c = getchar())) {
    }

    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
        ungetc(c, stdin);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        c = getchar();
        if (!isdigit(c) && c != '.') {
            ungetc(c, stdin);
            return 0;
        }
    }
    if (c == '.') {
        int prevChar = c;
        c = getchar();
        if (!isdigit(c)) {
            ungetc(c, stdin);
            return 0;
        }
        ungetc(c, stdin);
        c = prevChar;
    }

    for (*pn = 0.0, frac = 10; isdigit(c) || c == '.'; c = getchar()) {
        if (c == '.') {
            frac = 1;
            continue;
        }
        if (frac <= 1) {
            frac *= 0.1;
            *pn = *pn + (frac * (c - '0'));
        } else {
            *pn = *pn * frac + (c - '0');
        }
    }
    *pn *= sign;
    if (c != EOF) {
        ungetc(c, stdin);
    }
    return c;
}

int main(int argc, char* argv[]) {
    int n;
    double array[SIZE];
    for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++) {
    }

    printf("\nValues entered:\n");
    for (int i = 0; i < n; i++) {
        printf("%f\n", array[i]);
    }
    return 0;
}
