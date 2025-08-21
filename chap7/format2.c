#include <stdio.h>

void printName(void* data) {
    char* name = (char*)data;  // practicing my casting
    printf("Your name is: %s\n", name);
}

void askName() {
    char name[5];
    printf("What is your name: ");
    scanf("%s", name);
    printName(name);
}

int main(int argc, char* argv[]) {
    int day, month;
    printf("Enter today's date (day and month): ");
    scanf("%d %d", &day, &month);
    printf("Date passed in: %d / %d\n", day, month);
    askName();
    return 0;
}
