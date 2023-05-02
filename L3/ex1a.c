#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char checkDistance(float xA, float yA, float xB, float yB, float xC, float yC) {
    float dAC = sqrt(pow(xC - xA, 2) + (pow(yC - yA, 2)));
    float dBC = sqrt(pow(xC - xB, 2) + (pow(yC - yB, 2)));
    if (dAC > dBC) return 'B';
    else if (dAC < dBC) return 'A';
    return '=';
}

int main (void) {
    float xA;
    float yA;
    float xB;
    float yB;
    float xC;
    float yC;
    
    printf("Enter (x, y) coordinates of A: ");
    scanf("%f", &xA);
    scanf("%f", &yA);    

    printf("Enter (x, y) coordinates of B: ");
    scanf("%f", &xB);
    scanf("%f", &yB);

    printf("Enter (x, y) coordinates of C: ");
    scanf("%f", &xC);
    scanf("%f", &yC);

    printf("Result: %c\n", checkDistance(xA, yA, xB, yB, xC, yC));

    return EXIT_SUCCESS;
}