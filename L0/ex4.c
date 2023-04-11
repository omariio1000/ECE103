#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    double r1;
    double r2;
    double v;

    printf("Enter R1 (ohms): ");
    scanf("%lf", &r1);
    
    printf("Enter R2 (ohms): ");
    scanf("%lf", &r2);

    printf("Enter V (volts): ");
    scanf("%lf", &v);

    double rEQ = 1/(1/r1 + 1/r2);
    double p = pow(v, 2)/rEQ;

    printf("Req = %lf ohms and P = %lf watts\n", rEQ, p);

    return EXIT_SUCCESS;
}