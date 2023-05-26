#include <stdio.h>
#include <math.h>

struct quadroots {
    double x1;
    double x2;
};

struct coefficients {
    double a;
    double b;
    double c;
};

struct quadroots roots(struct coefficients cof) {
    struct quadroots ret;

    ret.x1 = (-cof.b + sqrt(cof.b*cof.b - 4*cof.a*cof.c)) / (2*cof.a);
    ret.x2 = (-cof.b - sqrt(cof.b*cof.b - 4*cof.a*cof.c)) / (2*cof.a);
    return ret;
}

int main (void) {
    struct coefficients co;
    printf("Enter coefficients a, b, and c: ");
    scanf("%lf%lf%lf", &co.a, &co.b, &co.c);

    struct quadroots sol = roots(co);

    printf("x1 = %f   x2 = %f\n", sol.x1, sol.x2);
    return 0;
}
