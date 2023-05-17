#include <stdio.h>
#include <math.h>

void quadraticRoots(double *a, double *b, double *c, double *x1, double *x2) {
    double inside = sqrt(pow(*b, 2) - 4 * *a * *c);
    *x1 = (-*b + inside) / (2 * *a);
    *x2 = (-*b - inside) / (2 * *a);
    return;
}

int main (void) {
    double a, b, c; // Coefficients of the quadratic equation
    double x1, x2;  // Roots of the quadratic equation
    printf("Enter coefficients a, b, and c: ");
    scanf("%lf%lf%lf", &a, &b, &c);
    // Add code to call your function(s) here
    quadraticRoots(&a, &b, &c, &x1, &x2);
    // Add code to print the roots x1 and x2 here
    printf("x1 = %.6lf  x2 = %.6lf\n", x1, x2);
    return 0;
}
