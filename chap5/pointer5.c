#include <stdio.h>
int foo() {
    return 1;
}
int bar() {
    return 2;
}

int main(int argc, char* argv[]) {
    int arr[2] = {1, 10};
    int (*ptr1)[2] = &arr;  // ptr2 is a pointer to an array of 2 ints
    int* ptr2[2];           // ptr2 is an array of 2 pointers to int

    // FYI:
    //   - x() "x is a function taking no arguments"
    //   - (*x())[] "the function returns a pointer to an array
    //    - (*(*x())[]) "The array holds pointers to functions taking no arguments
    //    - char (*(*x())[])() "and those functions return char"
    char (*(*x())[])();

    int (*pfa[])() = {bar, foo};  // an array of pointers that point to functions
    printf("%d\n", pfa[0]());     // call bar() - prints 2

    return 0;
}
