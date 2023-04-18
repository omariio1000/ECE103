#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141592654

double cylinderVolume(double d, double h) {//get cylinder volume
    double r = d/2;
    return PI * pow(r, 2) * h;
}

double coneVolume(double d, double h) {//get cone volume
    double r = d/2;
    return (PI * pow(r, 2) * h)/3;
}

double objectVolume(double d, double cylinder, double cone) {//add cyclinder and cone volume using user input
    return cylinderVolume(d, cylinder) + coneVolume(d, cone);
}

int main(void) {

    // I/O
    double diameter;
    double cyclinderHeight;
    double coneHeight;

    printf("Enter diameter d (cm): ");
    scanf("%lf", &diameter);

    printf("Enter cylinder height (cm): ");
    scanf("%lf", &cyclinderHeight);

    printf("Enter cone height (cm): ");
    scanf("%lf", &coneHeight);

    //error
    if (diameter == 0 || cyclinderHeight == 0 || coneHeight == 0) {
        printf("Invalid input!\n");
       return EXIT_FAILURE; 
    }

    printf("Object volume = %.2lf cm^3\n", objectVolume(diameter, cyclinderHeight, coneHeight));

    return EXIT_SUCCESS;
}