#include <stdio.h>

struct {         // defining an unnamed struct
    char* name;  // 8 bytes, needs to start at a multiple of 8
    int age;     // 8 bytes, needs to start at a multiple of 8

} a, b, c;  // declaring three variables of this struct type

int main(int argc, char* argv[]) {
    a.name = "Sofia";
    a.age = 23;

    printf("%s is %d year(s) old\n", a.name, a.age);
    printf("Size of unnamed struct: %lu\n", sizeof(a.age));
    printf("Size of unnamed struct: %lu\n", sizeof(a.name));
    printf("Size of unnamed struct: %lu\n", sizeof(a));  // 16 bytes because of alignment padding
    return 0;
}
