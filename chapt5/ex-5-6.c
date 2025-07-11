#include <stdio.h>

// Read a line into s, return length
int myGetLine(char* s, int lim) {
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        *(s + i) = c;
    }
    if (c == '\n') {
        *(s + i) = c;
        i++;
    }
    *(s + i) = '\0';
    return i;
}

// convert s to integer
int myAtoi(char* s) {
    int i, n;
    n = 0;
    for (i = 0; *(s + i) >= '0' && *(s + i) <= '9' && *(s + i) != '\0'; ++i) {
        n = 10 * n + (*(s + i) - '0');
    }
    return n;
}

void myReverse(char* s) {
    int c, i, j;
    char* p = s;
    for (j = 0; *p != '\0'; p++, j++);  // get length of string 's'
    for (i = 0, j = j - 1; i < j; i++, j--) {
        c = *(s + i);
        *(s + i) = *(s + j);
        *(s + j) = c;
    }
}

// return index of t in s, -1 if none
int myStrindex(char* s, char* t) {
    int i, j, k;
    for (i = 0; *(s + i) != '\0'; i++) {
        for (j = i, k = 0; *(t + k) != '\0' && *(s + j) == *(t + k); j++, k++);
        if (k > 0 && *(t + k) == '\0') {
            return i;
        }
    }
    return -1;
}

int main(int argc, char* argv[]) {
    char s[] = "heworld";
    char t[] = "world";
    printf("index read: %d\n", myStrindex(s, t));
    return 0;
}
