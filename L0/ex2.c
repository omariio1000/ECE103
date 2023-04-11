// This is a demo program

#include <stdio.h>
#include <math.h>

#define PI 3.141592654

int main (void) {
    double angle; // Input angle (type is double) in degrees

    printf("Enter an angle in degrees: ");
    scanf("%lf", &angle);

    double newAngle = angle * (PI/180);

    double x = (3.0/4.0) * cos(newAngle) * sin(newAngle);

    printf("x = %lf\n", x);

    return 0;
}

