#include <stdio.h>

void print_binary(unsigned char n) {
    printf("0b");
    for (int i = 7; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
}

unsigned char invert(unsigned char x, int p, int n) {
    unsigned char mask = ~(~0 << n);
    unsigned char stoInvert = (mask & ~((x >> (p + 1 - n)) & mask)) << (p + 1 - n);
    return (x & ~(mask << (p + 1 - n))) | stoInvert;
}

int main(int argc, char* argv[]) {
    print_binary(invert(0b11000011, 2, 2));
    return 0;
}
