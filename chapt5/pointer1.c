#include <stdio.h>

int main(int argc, char* argv[]) {
    // char amessage[] = "Hello, world!";  // array of characters - can be modified (stored in stack)
    char* pmessage = "Hello, world!";  // pointer to string constant - cannot be modified (stored in read-only
    // section) amessage[0] = 'h';                  // This will NOT cause a segmentation fault (accessing stack memory)
    // pmessage[0] = 'h';                  // This will cause a segmentation fault (accessing read-only memory)

    printf("%c\n", *pmessage++);  // derefernces pointer, then move onto next character
    // This means: *(pmessage++)
    // 1.	Apply ++ to pmessage, because it has higher precedence.
    // 2.	The ++ is post-increment, so it returns the value before incrementing.
    // 3.	Then dereference that returned value.

    printf("%c\n", *--pmessage);  // decrements pmessage first, then derefernces
    // This means: *(--pmessage)
    // 1. Apply -- to pmessage, because it has higher precedence.
    // 2. The -- is pre-decrement, so it returns the value after decrementing.
    // 3. Then dereference that returned value.

    int stack[10];
    int *p = stack, *c;  // p points to the start of the stack
    int val = 10;

    printf("\nAfter updating 1st\n");
    *p++ = val;  // pushes val onto stack
    for (c = stack; *c != '\0'; c++) {
        printf("%d\n", *c);
    }

    printf("\nAfter updating 2nd\n");
    *p++ = val += 15;
    for (c = stack; *c != '\0'; c++) {
        printf("%d\n", *c);
    }

    printf("\nAfter poping 1st from top into val\n");
    val = *--p;
    printf("%p\n", p);
    printf("%d\n", val);
    printf("\nAfter poping 2nd from top into val\n");
    val = *--p;  // 1. still updates p to point to the previous element in the stack (e.g, p before: 0x7ffeefbff5c8,
                 // after: 0x7ffeefbff5c4)
    printf("%p\n", p);
    printf("%d\n", val);
    printf("\nAfter poping 3rd from top into val\n");
    val = *--p;  // 2. still updates p to point to the previous element in the stack (e.g, p before: 0x7ffeefbff5c4,
                 // after: 0x7ffeefbff5c0)

    printf("%p\n", p);
    printf("%d\n", val);

    return 0;
}
