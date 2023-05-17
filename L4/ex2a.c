#include <stdio.h>
#include <math.h>

double getX1 (double *a, double *b, double *c) {
    double inside = sqrt(pow(*b, 2) - 4 * *a * *c);
    return (-*b + inside) / (2 * *a);
}

double getX2 (double *a, double *b, double *c) {
    double inside = sqrt(pow(*b, 2) - 4 * *a * *c);
    return (-*b - inside) / (2 * *a);
}

int main (void) {
    double a, b, c; // Coefficients of the quadratic equation
    double x1, x2;  // Roots of the quadratic equation
    printf("Enter coefficients a, b, and c: ");
    scanf("%lf%lf%lf", &a, &b, &c);
    // Add code to call your function(s) here
    x1 = getX1(&a, &b, &c);
    x2 = getX2(&a, &b, &c);

    // Add code to print the roots x1 and x2 here
    printf("x1 = %.6lf  x2 = %.6lf\n", x1, x2);
    return 0;
}
