#include <stdio.h>

#define swap(t, x, y) \
    int t_temp = x;   \
    x = y;            \
    y = t_temp;

int main(int argc, char* charv[]) {
    int x = 5, y = 10;
    printf("Before swap: x = %d, y = %d\n", x, y);
    swap(int, x, y);
    printf("After swap: x = %d, y = %d\n", x, y);
    return 0;
}
