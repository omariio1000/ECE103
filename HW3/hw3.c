/* Omar Nassar
 * Portland State University ECE 103
 * Homework 3
 * May 15, 2023
 * TO RUN ON LINUX: clink -a hw3
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include "dislin.h"

#ifndef  M_PI
#define  M_PI  3.1415926535897932384626433
#endif

#define BUFFER_SIZE 128




float getYVal(float x, float L, int N);
void plot(float x[], float y[], float square[], int num, float xStop, char title1[], char title2[]);

int main(void) {
    char name[BUFFER_SIZE];
    printf("Please enter your name: ");
    fgets(name, BUFFER_SIZE, stdin);
    fflush(stdin);

    float xStop = 0;
    while (xStop <= 0.0 || xStop > 10.0) {
        printf("Enter x range stop (0 to 10): ");
        scanf("%f", &xStop);
        fflush(stdin);
        if (xStop <= 0.0 || xStop > 10.0) fprintf(stderr, "  Error: Out of range. Please try again.\n");
    }
    
    float xStep = 0;
    while (xStep <= 0.0 || xStep > 0.5) {
        printf("Enter x step size (0.01 to 0.5): ");
        scanf("%f", &xStep);
        fflush(stdin);
        if (xStep <= 0.0 || xStep > 0.5) fprintf(stderr, "  Error: Out of range. Please try again.\n");
    }

    float interval = 0;
    while (interval <= 0.0 || interval > xStop/2) {
        printf("Enter interval L (0.5 to %g): ", xStop/2);
        scanf("%f", &interval);
        fflush(stdin);
        if (interval <= 0.0 || interval > xStop/2) fprintf(stderr, "  Error: Out of range. Please try again.\n");
    }

    int order = 0;
    while (order <= 0 || order > 99 || order % 2 == 0) {
        printf("Enter order N (1 to 99, odd only): ");
        scanf("%d", &order);
        fflush(stdin);
        if (order <= 0 || order > 99) fprintf(stderr, "  Error: Out of range. Please try again.\n");
        if (order % 2 == 0) fprintf(stderr, "  Error: N must be odd. Please try again.\n");
    }

    int num = floor(xStop/xStep) + 1;
    float x[num];
    float y[num];
    float square[num];
    float xStart = 0.0;

    for (int i = 0; i < num; i++) {
        x[i] = xStart;
        xStart += xStep;
        y[i] = getYVal(x[i], interval, order);
        //printf("%.2f, %2f\n", x[i], y[i]);

        if (x[i] == 0) square[i] = 0;
        else if (x[i] > 0 && x[i] < interval) square[i] = 1;
        else if (x[i] >= interval && x[i] < (interval * 2) - 0.01) square[i] = -1;
        else square[i] = 0;
    }
    char title1[BUFFER_SIZE];
    strcpy(title, ("Truncated Fourier Series for Square Wave (L = %f, N = %d)", interval, order));

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    char title2[BUFFER_SIZE];
    strcpy(title, ("Programmer: %s\tDate: %d-%02d-%02d %02d:%02d:%02d\n", name, tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec));

    //plot(x, y, square, num, xStop, title1, title2);

    return EXIT_SUCCESS;
}

float getYVal(float x, float L, int N) {
    float temp = 0.0;
    for (float n = 1; n <= N; n += 2.0f) {
        float temp2 = (1.0f / n) * sin((n * M_PI * x) / L);
        //printf("%f: %f\n", n, temp2);
        temp += temp2;
    }
    temp *= (4.0/M_PI);
    return temp;
}

void plot(float x[], float y[], float square[], int num, float xStop, char title1[], char title2[]) {
    // Set up plot
	metafl("XWIN");      // Defines the plot file format
	setpag("da4l");      // Selects a predefined page format
    
    scrmod("REVERS");

	disini();            // Initialize DISLIN
	pagera();            // Plot a page border
	hwfont();            // Set a standard hardware font

	axspos(450, 1800);   // Determine the position of axis system
	axslen(2200, 1200);  // Define axis length for 2-D axis system

	name("X-axis", "x"); // Define x-axis title
	name("Y-axis", "y"); // Define y-axis title

	labdig(-1, "x");     // Set number of decimal places for tick labels
	ticks(10, "xy");     // Set number of tick marks

    /* Plot a 2-D axis system:
       graf(XA, XE, XOR, XSTP, YA, YE, YOR, YSTP);

       XA, XE    - X-axis: lower and upper limits
       XOR, XSTP - X-axis: first major tick to label and the step between major ticks
       YA, YE    - Y-axis: lower and upper limits
       YOR, YSTP - Y-axis: first major tick to label and the step between major ticks
    */
	graf(0.f, xStop + 0.1f, 0.f, 1.0, -1.4f, 1.4f, -1.4f, 0.2f);

	titlin(title1, 1); // Define text lines for title
	titlin(title2, 2);
    title();             // Plot the title over the axis system

	color("red");        // Color for first curve
	curve(x, y, num);     // Plot curve for y1 versus x

    color("blue"); 
    dash();       // Color for first curve
	curve(x, square, num);

	color("fore");       // Reset color to default value
    solid();
	xaxgit();            // Plot the line Y = 0

	disfin();            // Terminates DISLIN

    return;
}