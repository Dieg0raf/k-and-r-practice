#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int age;
} Person;

// generic pointer (void*)
void print_int(void* data) {
    // cast before dereferncing (We're telling the compiler: "trust me, I know this is an int*"
    int* ptr = (int*)data;
    // can't be dereferenced directly, because the compiler doesn't know the size or structure of the data it points to
    printf("%d\n", *ptr);
}

int print_person(void* data) {
    Person* p = (Person*)data;
    printf("%s is %d years old\n", p->name, p->age);
    return p->age;
}

// accepts a pointer to a function with one void* arguement
// FYI:
// - int (*func)(void*), says func is a pointer to a function that has 1 void* arguement and it returns an int
// - 'func' is a pointer to a function
// - '*func' is the function
void randomFunc(int (*func)(void*), void* data) {
    Person* p = (Person*)data;

    // calling the function 'func' with '*func' and passing in 'p'
    printf("This is what was returned by the func function: %d\n", (*func)(p));
}

int main(int argc, char* argv[]) {
    // int y = 10;
    // int* x = &y;
    // print_int(x);

    Person* p1 = malloc(sizeof(Person));
    strcpy(p1->name, "Diego");
    p1->age = 23;

    // passing in the function 'print_person' and passing in p1 as an arguement
    randomFunc(print_person, p1);

    return 0;
}
