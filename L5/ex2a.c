#include <stdio.h>
#include <math.h>

struct quadroots {
    double x1;
    double x2;
};

struct quadroots roots(double a, double b, double c) {
    struct quadroots ret;

    ret.x1 = (-b + sqrt(b*b - 4*a*c)) / (2*a);
    ret.x2 = (-b - sqrt(b*b - 4*a*c)) / (2*a);
    return ret;
}

int main (void) {
    double a, b, c; // Coefficients of the quadratic equation
    printf("Enter coefficients a, b, and c: ");
    scanf("%lf%lf%lf", &a, &b, &c);

    struct quadroots sol = roots(a, b, c);

    printf("x1 = %f   x2 = %f\n", sol.x1, sol.x2);
    return 0;
}
