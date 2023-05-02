#include <stdio.h>
#include <math.h>

#define MAXSIZE 10 // Maximum size of 1-D array

void enterElements(double *x, int n) {
    printf("Enter array values: ");
    for (int i = 0; i < n; i++) scanf("%lf", &x[i]);
    return;
}

void raisePower(double *x, double *a, double power, int n) {
    for (int i = 0; i < n; i++) a[i] = pow(x[i], power);
}

void printElements(double *a, int n) {
    for (int i = 0; i < n; i++) printf("%.3lf%s", a[i], i < n - 1 ? " " : "\n");
}

int main (void)
{
    double X[MAXSIZE]; // Array holds user’s input values
    int n; // Actual array size
    printf("Enter size of array: ");
    scanf("%d", &n);

    if (n > MAXSIZE) {
        n = MAXSIZE;
        printf("Size reduced to 10.\n");
    }
    
    enterElements(X, n);
    
    double A[n];
    double power;
    printf("Enter power: ");
    scanf("%lf", &power);
    
    raisePower(X, A, power, n);
    printElements(A, n);

    return 0;
}
