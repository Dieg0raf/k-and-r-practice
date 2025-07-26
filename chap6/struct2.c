#include <stdio.h>

struct point {
    int x;
    int y;
};

struct rect {
    struct point pt1;
    struct point pt2;
};

// make a point from x and y components
struct point makepoint(int x, int y) {
    struct point pt;
    pt.x = x;
    pt.y = y;
    return pt;
}

// add two points
struct point addpoint(struct point pt1, struct point pt2) {
    pt1.x += pt2.x;
    pt1.y += pt2.y;
    return pt1;
}

int main(int argc, char* argv[]) {
    struct point pt = {320, 200};
    printf("%d, %d\n", pt.x, pt.y);

    struct rect screen1;
    screen1.pt1.x = 10;
    screen1.pt1.y = 10;
    screen1.pt2.x = 15;
    screen1.pt2.y = 23;
    printf("first point: %d, %d\n", screen1.pt1.x, screen1.pt1.y);
    printf("second point: %d, %d\n", screen1.pt2.x, screen1.pt2.y);

    struct rect screen2;
    screen2.pt1 = makepoint(10, 10);
    screen2.pt2 = makepoint(15, 23);
    printf("first point: %d, %d\n", screen2.pt1.x, screen2.pt1.y);
    printf("second point: %d, %d\n", screen2.pt2.x, screen2.pt2.y);

    // a pointer to a structure of type struct point
    struct point pt1;
    struct point* pp;
    printf("Before changing x: %d\n", pt1.x);
    printf("Before changing y: %d\n", pt1.y);
    pp = &pt1;     // set pointer to point to pt1
    (*pp).x = 10;  // *pp is the structure
    (*pp).y = 25;
    printf("After 1st changing x: %d\n", pt1.x);
    printf("After 1st changing y: %d\n", pt1.y);
    pp->x = pp->x += 1;  // pp->x == (*pp).x
    pp->y = pp->y += 1;
    printf("After 1st changing x: %d\n", pt1.x);
    printf("After 1st changing y: %d\n", pt1.y);
    return 0;
}
