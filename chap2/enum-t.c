#include <stdio.h>

enum Colors { RED, GREEN, BLUE };  // integer constants for colors 0, 1, 2, respectively

int main(int argc, char* argv[]) {
    enum Colors randomColor = GREEN;  // example usage of enum (you can change this to RED or BLUE)

    if (randomColor == GREEN) {
        printf("The color is GREEN.\n");
    } else {
        printf("The color is not GREEN.\n");
    }

    printf("RED: %d\n", RED);
    printf("GREEN: %d\n", GREEN);
    printf("BLUE: %d\n", BLUE);

    return 0;
}
