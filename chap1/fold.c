#include <stdio.h>

#define N 5

// 0123456789 11 12 13 14
// abc def gh i  j  k  l  kl

int main(int argc, char* argv[]) {
    int c, charCol = 0;
    char buf[N];

    while ((c = getchar()) != EOF) {
        // printf("charCol %d for character %c\n", charCol, c);
        if (charCol >= N) {
            int lastIndex;
            // printf("Made it here\n");
            for (int i = N; i > 0; i--) {
                // printf("Character %c in index %d\n", buf[i], i);
                if (buf[i] == '\n' || buf[i] == '\t' || buf[i] == ' ') {
                    lastIndex = i;
                    // printf("last index: %d\n", lastIndex);
                    break;
                }
            }
            for (int j = 0; j < lastIndex; j++) {
                printf("%c", buf[j]);
                buf[j] = 0;
            }
            charCol = 0;
        } else {
            buf[charCol] = c;
            charCol++;
        }
    }

    return 0;
}
