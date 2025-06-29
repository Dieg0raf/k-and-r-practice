#include <stdio.h>

void escape(char s[], char t[]) {
    int i, j;
    for (i = j = 0; s[i] != EOF; i++) {
        switch (t[i]) {
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            default:
                s[j++] = t[i];
                break;
        }
    }
    s[j] = '\0';
    printf("%s\n", s);
}

int main(int argc, char* argv[]) {
    char t[] = "Hello\tWorld\nDiego";
    char s[100];
    escape(s, t);
    return 0;
}
