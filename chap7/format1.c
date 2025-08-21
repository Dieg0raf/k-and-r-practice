#include <stdio.h>

int main(int argc, char* argv[]) {
    char s[50];
    sprintf(s, "%s is %d years old", "Diego", 23);
    printf("This was the output: %s\n", s);

    char* frmt = "Diego";
    for (char* p = frmt; *p; p++) {
        printf("%c ", *p);
    }
    printf("\n");
    return 0;
}
