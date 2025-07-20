#include <stdio.h>
#include <stdlib.h>

// reading patterns
int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("No pattern matching need\n");
        return 1;
    }
    char c;
    int number = 0;
    while (--argc > 0 && (*++argv)[0] == '-') {  // looping through argument vector
        while ((c = *++(argv[0]))) {  // iterating through the string (e.g., -n, reading through the whole string
                                      // consisting of '-' and 'n' and skipping '-')
            switch (c) {
                case 'm':
                    printf("This is an \'m\' character ");
                    number = 1;
                    break;
                case 'n':
                    printf("This is an \'n\' character ");
                    number = 1;
                    break;
                default:
                    break;
            }
        }
        if (number) {
            printf("with value: %d\n", atoi(*(++argv)));
            number = 0;
            argc--;
        }
    }
    return 0;
}
