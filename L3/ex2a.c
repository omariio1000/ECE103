#include <stdio.h>
#include <math.h>

#define MAXSIZE 10 // Maximum size of 1-D array

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
    
    printf("Enter array values: ");
    for (int i = 0; i < n; i++) scanf("%lf", &X[i]);
    
    double A[n];
    double power;
    printf("Enter power: ");
    scanf("%lf", &power);
    
    for (int i = 0; i < n; i++) {
        A[i] = pow(X[i], power);
        printf("%.3lf%s", A[i], i < n - 1 ? " " : "\n");
    }
    

    return 0;
}
