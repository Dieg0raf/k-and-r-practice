#include <stdio.h>

typedef double Align;
// double required 8-byte alignment on most systems
// Therefore, union header is aligned to 8 bytes
// Even though the x field is never used, its presence foces the compiler to pad/align the union

// has the size of the it's largest member
union header {
    struct {
        union header* ptr;
        unsigned size;
    } a;
    Align x;
};

// The Align x; field in the union is never used directly, but its existence ensures that every union header and thus
// every memory block handed out is aligned properly for any data type. This is an old-school C trick to get portable
// alignment guarantees across architectures.

int main(int argc, char* argv[]) {
    return 0;
}
