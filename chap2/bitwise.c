#include <stdio.h>

unsigned getbits(unsigned x, int p, int n) {
    return (x >> (p + 1 - n)) & ~(~0 << n);
}

void print_binary(unsigned char n) {
    printf("0b");
    for (int i = 5; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
}

int main(int argc, char* argv[]) {
    unsigned char a = 0b010110;
    print_binary(getbits(a, 3, 3));  // should print 0b011 = 3
    printf("\n");
    printf("%d\n", getbits(a, 3, 3));
    printf("\n");
    // unsigned char x = 0b10101010;
    // unsigned char y = 0b1110;
    // unsigned char z = x & y;
    // print_binary(z);
    // printf("\n%u\n", z);
    // printf("\n");

    // flips 0s in x to 1 if bit in y is 1 else bit
    // stays as 1 if already a 1
    // unsigned char x = 0b100101;
    // unsigned char y = 0b011;
    // unsigned char z = x | y;
    // print_binary(z);

    // if bits are the same then bit is set to 0. WLOG if
    //  one bit is 1 and the other is 0, then bit is 1.
    //  (can only have one, not both)
    // unsigned char x = 0b110101;
    // unsigned char y = 0b100110;
    // unsigned char z = x ^ y;
    // print_binary(z);

    // shift x 2 bits to the left (0b110101 --> 0b010100)
    // sets in the right bits that were added to 0
    unsigned char x = 0b110101;
    print_binary(x);
    printf("\n");
    print_binary(x << 2);

    // shifts x, n (n=2 in this example) bits to the right
    // (0b110101 --> 0b001101)
    printf("\n");
    unsigned char y = 0b110101;
    print_binary(y);
    printf("\n");
    print_binary(y >> 2);

    // shifts signed x, n (n=2 in this example) bits to the right
    // (0b111000 --> 0b111110)
    // FYI: sign bit IS conservered, the added bits are converted to 1 not 0s
    // (right shift only on sign bits)
    printf("\n");
    int h = -8;
    print_binary(h);
    printf("\n");
    print_binary(h >> 2);

    // shifts signed x, n (n=5 in this example) bits to the left
    // (0b111110 --> 0b000000)
    // FYI: sign bit IS NOT conservered, its changed to 0 as well
    printf("\n");
    int f = -2;
    print_binary(f);
    printf("\n");
    print_binary(f << 5);

    // converts bits that are 1 to 0 and vise versa
    // (0b110101 --> 0b001010)
    printf("\n");
    unsigned char d = 0b110101;
    print_binary(d);
    printf("\n");
    print_binary(~d);

    printf("\n");
    unsigned char u = 0b110111;
    unsigned char j = 0b1101;  // compiler converts j to 0b00001101
                               // (8 bits because char is 1 byte = 8 bits)
                               // before using the ~ operator
    unsigned char p = u & ~j;
    printf("Something: ");
    print_binary(p);
}
