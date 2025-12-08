#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159

typedef struct _crcl {
    double radius;
    double (*area)(struct _crcl*);
} Circle;

double circle_area(Circle* this) {
    return PI * this->radius * this->radius;
}

Circle* new_circle(double r) {
    Circle* c = (Circle*) malloc(sizeof(Circle));
    c->radius = r;
    c->area = circle_area;
    return c;
}

int main() {
    Circle* c1 = new_circle(1.0);
    Circle* c2 = new_circle(2.0);

    printf("The area of c1 is %f\n", c1->area(c1));
    printf("The area of c2 is %f\n", c2->area(c2));
}
