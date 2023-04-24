/* Omar Nassar
 * Portland State University ECE 103
 * Homework 2
 * April 23, 2023
 * Program to calculate activity levels of radiactive isotopes
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double convertToDays(double timeDecay, char timeUnit); //function to convert any unit to days
double activityLevel(double initialActivity, double timeDecay, double halfLife); //funciton to do activity level calculation

int main(void) {//no argc or argv needed
    //half lives of isotopes
    double halfLife[] = {0.0000, 7951.4925, 12.8, 752.415, 0.0941666};
    
    //I/O
    printf("Available isotopes:\n");
    printf("[1] Actinium 227 (Ac-227, half-life = 21.77 y)\n");
    printf("[2] Barium 140\t (Ha-140, half-life = 12.8 d)\n");
    printf("[3] Cesium 134\t (Cs-134, half-life = 2.06 y)\n");
    printf("[4] Iodine 132\t (I-132, half-life = 2.26 h)\n");

    int isotopeIndex = 0;

    while (isotopeIndex < 1 || isotopeIndex > 4) {
        printf("\nEnter the isotope index (1-4): ");
        scanf("\n%d", &isotopeIndex);
        if (isotopeIndex < 1 || isotopeIndex > 4) fprintf(stderr, "ERROR: That is not a valid index.\n");
        fflush(stdin);
    }

    double initialActivity = 0;
    while (initialActivity < 1 || initialActivity > 1000000) {
        printf("\nEnter the initial activity A0 (0 < A0 <= 1e+06 uCi): ");
        scanf("\n%lf", &initialActivity);
        if (initialActivity < 1 || initialActivity > 1000000) fprintf(stderr, "ERROR: That is not a valid initial activity level.\n");
    }

    double timeDecay = 0;
    while (timeDecay <= 0) {
        printf("\nEnter the decay time (t > 0): ");
        scanf("\n%lf", &timeDecay);
        if (timeDecay <= 0) fprintf(stderr, "ERROR: That is not a valid decay time.");
        fflush(stdin);
    }

    char timeUnit = 'a';
    while (timeUnit != 'h' && timeUnit != 'd' && timeUnit != 'y') {
        printf("\nEnter the time unit (h/d/y): ");
        scanf("\n%c", &timeUnit);
        if (timeUnit != 'h' && timeUnit != 'd' && timeUnit != 'y') fprintf(stderr, "ERROR: That is not a valid time unit.\n");
        fflush(stdin);
    }

    timeDecay = convertToDays(timeDecay, timeUnit);
    //printf("Final time: %lfh\n", timeDecay);    

    //calculating times and activities for graphing
    double times[21];
    double activities[21];
    double increment = timeDecay/20;
    for (int i = 0; i < 21; i++) {
        times[i] = increment * i;
        activities[i] = activityLevel(initialActivity, times[i], halfLife[isotopeIndex]);
        //printf("%.3lf, %.2lf\n", times[i], activities[i]);
    }

    printf("\nFinal activity level = %4.4g uCi\n", activities[20]);
    printf("\nGraph of activity A(t) versus tiem t:\n");
    printf("Bar label format: (t in days, A(t) in uCi)\n\n");
    
    //printing graph
    for (int i = 0; i < 21; i++) {
        double percentage = activities[i]/initialActivity;
        int stars = percentage * 60;
        for (int j = 0; j < stars; j++) printf("*");
        printf(" (%.3lf, %.2lf)\n", times[i], activities[i]);
    }

    return EXIT_SUCCESS;
}

double convertToDays(double timeDecay, char timeUnit) {
    if (timeUnit == 'd') return timeDecay;
    else if (timeUnit == 'h') return timeDecay/24;
    else if (timeUnit == 'y') return timeDecay * 365.25;
}

double activityLevel (double initialActivity, double timeDecay, double halfLife) {
    double t = 0.693 * timeDecay;
    double ePower = -t/halfLife;
    double finalA = initialActivity * exp(ePower);
    return finalA;
}


