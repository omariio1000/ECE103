#include <stdlib.h>
#include <stdio.h>

int main (void) {
    double start;
    double end;
    double step;

    printf("Enter the start value (F): ");
    scanf("%lf", &start);

    printf("Enter the end value (F): ");
    scanf("%lf", &end);

    printf("Enter the step value (F): ");
    scanf("%lf", &step);

    printf("\nF\tC\tK\tR\n");
    while (start <= end) {
        double celsius = (start - 32.0) * (5.0/9.0);
        double kelvin = celsius + 273.15;
        double rankine = start + 459.67;
        printf("%.2lf:\t%.2lf\t%.2lf\t%.2lf\n", start, celsius, kelvin, rankine);
        start += step;
    }
}