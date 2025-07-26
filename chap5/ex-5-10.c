#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXINTALLOWED 12

int main(int argc, char* argv[])
{
    if (argc < 2) {
        fprintf(stderr, "Need more arguments passed in\n");
        return 1;
    }

    if (argc > 25) {
        fprintf(stderr, "To many arguments passed in\n");
        return 1;
    }

    char** stack = malloc(sizeof(char*) * (argc - 1));
    char **start, **base;
    start = base = stack; // setting start and base to point to the start of the stack
    for (int i = 0; i < argc - 1; i++) {
        stack[i] = NULL;
    }

    char *value, *buf;
    int val1, val2, result;
    while (--argc > 0) {
        value = *(++argv);
        switch (*value) {
        case '+':
            val2 = atoi(*--stack);
            val1 = atoi(*--stack);
            result = val1 + val2;
            buf = malloc(strlen(result) + 1); // allocating memory for the result string
            sprintf(buf, "%d", result);
            *stack++ = buf;
            break;
        case '-':
            val2 = atoi(*--stack);
            val1 = atoi(*--stack);
            result = val1 - val2;
            buf = malloc(strlen(result) + 1);
            sprintf(buf, "%d", result);
            *stack++ = buf;
            break;
        case '*':
            val2 = atoi(*--stack);
            val1 = atoi(*--stack);
            result = val1 * val2;
            buf = malloc(strlen(result) + 1);
            sprintf(buf, "%d", result);
            *stack++ = buf;
            break;
        default:
            buf = malloc(strlen(value) + 1);
            strcpy(buf, value); // copying over string into buffer, then pointing *stack pointer to point to this newly allocated memory
            *stack++ = buf;
            break;
        }
    }
    printf("Final output: %s\n", *--stack);

    while (*base != NULL) {
        free(*base++); // freeing allocated memory for strings
    }
    free(start); // freeing allocated memory of pointers

    return 0;
}
