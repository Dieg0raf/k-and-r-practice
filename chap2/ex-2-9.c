#include <stdio.h>
void print_binary(unsigned char n) {
    printf("0b");
    for (int i = 7; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
}

// c & (c - 1) is used to clear the least significant bit set in c
int main(int argc, char* argv[]) {
    signed char c = 0b11111110;  // 8 bits, signed char
    printf("c = %d, ", c);
    print_binary(c);
    printf(" (c - 1) = %d", c - 1);
    c = c & (c - 1);
    printf(" -> ");
    print_binary(c);
    printf(" (c & (c - 1)) = %d", c);
    printf("\n");
    return 0;
}
