#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// GOOD
// Order members from highest sizeof() to lowest.
// [ c c c c c c c c i i i i . . . . ]
// padding at the end, the CPU can often grab both fields in a single memory fetch
struct key {
    char* word;
    int count;
};

// BAD
// [ i i i i . . . . c c c c c c c c ]
// padding in the MIDDLE, the CPU has to fetch memory from two regions, possibly crossing a cache line
struct s {
    int c;
    char* w;
};

int main(int argc, char* argv[]) {
    // struct key keywords[2]; -- 'keywords' not a pointer so size is 16*2=32
    // struct key k1 = {"Diego", 1};
    // struct key k2 = {"Sofia", 2};
    // keywords[0] = k1;
    // keywords[1] = k2;
    // printf("First key \'%s\' with key word \'%d\'\n", keywords[0].word, keywords[0].count);

    struct key** keywords = malloc(2 * sizeof(struct key*));
    struct key** start = keywords;
    struct key k1 = {"Diego", 1};
    struct key k2 = {"Sofia", 2};
    *keywords = &k1;
    *(++keywords) = &k2;
    printf("first key: %s with keyword: %d\n", (*keywords)->word, (*keywords)->count);
    printf("second key: %s with keyword: %d\n", (*keywords)->word, (*keywords)->count);

    // struct 's'
    printf("Offset of c: %zu\n", offsetof(struct s, c));
    printf("Offset of w: %zu\n", offsetof(struct s, w));
    printf("Total size : %zu\n\n", sizeof(struct s));

    // struct 'key'
    printf("Offset of word: %zu\n", offsetof(struct key, word));
    printf("Offset of count: %zu\n", offsetof(struct key, count));
    printf("Total size : %zu\n", sizeof(struct key));

    // FYI:
    //  only freed 'keywords' and not inner elements because those were
    //   allocated on the stack and not manually allocated by me
    free(start);

    return 0;
}
