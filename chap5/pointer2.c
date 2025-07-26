#include <stdio.h>

int main(int argc, char *argv[]) {
    char *names[] = {"Diego", "Sofia"};  // array of two char* pointers
                                         // compiler stores these strings in a read-only section of memory

    printf("names [0]: %p\n", names[0]);
    printf("names string [0]: %s\n", names[0]);
    printf("names [1]: %p\n", names[1]);
    printf("names string [1]: %s\n", names[1]);
    printf("\n\n");
    printf("names [0]: %p\n", &names[0]);
    printf("names string [0]: %s\n", names[0]);
    printf("names [1]: %p\n", &names[1]);
    printf("names string [1]: %s\n", names[1]);
    // *(names[0]) = 'a'; Throws bus error
    printf("\n\n");

    char *named[4];
    printf("ptr [0]: %p\n", &named[0]);
    printf("ptr string [0]: %s\n", named[0]);
    printf("ptr [1]: %p\n", &named[1]);
    printf("ptr string [1]: %s\n", named[1]);
    printf("\n\n");

    printf("sizeof(char *) = %zu\n", sizeof(size_t *));  // Likely prints 8
    printf("sizeof(names) = %zu\n", sizeof(names));      // Likely prints 16
    printf("sizeof(named) = %zu\n", sizeof(named));      // Likely prints 16
    printf("\n\n");
    // Pointers vs Multi. Dimension Arrays
    char *ptrs[2];
    char *a = "Diegod;jasdfkjasfsadafsfasfsad";
    char *b = "Pablo";
    ptrs[0] = a;
    ptrs[1] = b;
    printf("ptrs string [0]: %s\n", ptrs[0]);
    printf("ptrs string [1]: %s\n", ptrs[1]);
    printf("\n\n");

    // With multi. dimension array, you must have at most 12 char long strings, but with an array of pointers, the
    // string the pointers are pointing to, don't have to be of similar sizes and can either be longer or shorter. This
    // is one of the biggest advantages of using pointers instead of multi. dimension array.
    char ptrs2[][12] = {"Diego l", "Sofiaadfasdf"};

    return 0;
}
