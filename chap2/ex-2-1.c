// #include <float.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    printf("size of int: %zu\n", sizeof(int));
    printf("min int %d - max int %d\n", INT_MIN, INT_MAX);
    printf("calculated min int %.0f - max int %.0f\n\n", -(pow(2, ((sizeof(int) * 8) - 1))),
           (pow(2, ((sizeof(int) * 8) - 1)) - 1));

    printf("size of unsigned int: %zu\n", sizeof(unsigned int));
    printf("min unsigned int 0 - max unsigned int %u\n\n", UINT_MAX);
    printf("calculated min unsigned int 0 - max unsigned int %.0f\n\n", (pow(2, (sizeof(unsigned int) * 8)) - 1));

    printf("size of short int: %zu\n", sizeof(short int));
    printf("min short int %d - max short int %d\n", SHRT_MIN, SHRT_MAX);
    printf("calculated min short int %.0f - max short int %.0f\n\n", -(pow(2, ((sizeof(short int) * 8) - 1))),
           (pow(2, ((sizeof(short int) * 8) - 1)) - 1));

    printf("size of unsigned short int: %zu\n", sizeof(unsigned short int));
    printf("min unsigned short int 0 - max unsigned short int %u\n", USHRT_MAX);
    printf("calculated min unsigned short int 0 - max unsigned short int %.0f\n\n",
           (pow(2, (sizeof(unsigned short int) * 8)) - 1));

    printf("size of long int: %zu\n", sizeof(long int));
    printf("min long int %ld - max long int %ld\n", LONG_MIN, LONG_MAX);
    printf("calculated min long int %.0f - max long int %.0f\n\n", -(pow(2, ((sizeof(long int) * 8) - 1))),
           (pow(2, ((sizeof(long int) * 8) - 1)) - 1));

    printf("size of unsigned long int: %zu\n", sizeof(unsigned long int));
    printf("min unsigned long int 0 - max unsigned long int %lu\n", ULONG_MAX);
    printf("calculated min unsigned long int 0 - max unsigned long int %.0f\n\n",
           (pow(2, (sizeof(unsigned long int) * 8)) - 1));

    printf("size of char: %zu\n", sizeof(char));
    printf("min char %d - max char %d\n", CHAR_MIN, CHAR_MAX);
    printf("calculated min char %.0f - max char %.0f\n\n", -(pow(2, ((sizeof(char) * 8) - 1))),
           (pow(2, ((sizeof(char) * 8) - 1)) - 1));

    printf("size of unsigned char: %zu\n", sizeof(unsigned char));
    printf("min char 0 - max char %d\n", UCHAR_MAX);
    printf("calculated min unsigned char 0 - max unsigned char %.0f\n\n", (pow(2, (sizeof(unsigned char) * 8)) - 1));

    return 0;
}
