#include <stdio.h>

void print_binary(unsigned char n) {
    printf("0b");
    for (int i = 7; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
}

// grabs the n rightmost bits of x and puts them to the left side, hence rotated
unsigned char rightrot(unsigned char x, int n) {
    unsigned char mask = ~(~0 << n);
    return (x >> n) | ((x & mask) << (8 - n));
}

int main(int argc, char* argv[]) {
    unsigned char x = 0b10110000;
    print_binary(x);
    printf("\n");
    print_binary(rightrot(0b10110000, 3));
    return 0;
}
