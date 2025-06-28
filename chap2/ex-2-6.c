#include <stdio.h>
void print_binary(unsigned char n) {
    printf("0b");
    for (int i = 7; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
}

unsigned char setbits(unsigned char x, int p, int n, unsigned char y) {
    // 11111111 << 2 (e.g., n = 2) =
    // = ~0b11111100 = (0b00001110 & 0b00000011 ) = 0b00000010
    unsigned char mask = ~(~0 << n);
    return (x & ~(mask << (p + 1 - n))) | ((y & mask) << (p + 1 - n));
}

int main(int argc, char* argv[]) {
    unsigned char a = 0b00010;
    unsigned char b = 0b01110;
    print_binary(setbits(a, 3, 2, b));  // 0b00001010
    return 0;
}
