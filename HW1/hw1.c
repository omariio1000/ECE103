/* Omar Nassar
 * Portland State University ECE 103
 * Homework 1
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define k 0.0000861735 //Boltzmann's Constant

double getKelvin(double celsius) { //Not using
    return celsius + 273.15;
}

double getBA(int wet, double temp) { //Funciton to get B/A for both wet and dry
    double coefficient;
    double activationEnergy;
    
    if (!wet) {
        coefficient = 1.03 * pow(10, 3);
        activationEnergy = 2.00;
    }
    else {
        coefficient = 2.70 * pow(10, 4);
        activationEnergy = 2.05;
    }

    return coefficient * exp(-(activationEnergy/(k * temp)));
}

double getB(int wet, double temp) {//Function to get B for both wet and dry
    double coefficient;
    double activationEnergy;
    
    if (!wet) {
        coefficient = 0.214;
        activationEnergy = 1.23;
    }
    else {
        coefficient = 0.107;
        activationEnergy = 0.79;
    }

    return coefficient * exp(-(activationEnergy/(k * temp)));
}

double getA(int wet, double temp) {//Function to get A by getting B and B/A
    return getB(wet, temp)/getBA(wet, temp);
}

double getTime(double x0, double x, double A, double B) {//Function to get time
    return ((pow(x, 2) + (A * x)) - (pow(x0, 2) + (A * x0)))/B;
}

void printHMS(double time) {//Converting time in seconds to HH:MM::SS
    int timeH = time/3600;
    double timeRem = (time/3600) - timeH;
    int timeM = timeRem * 60;
    timeRem -= ((double) timeM/60);
    int timeS = round(timeRem * 3600);
    printf("(%dh %dm %ds).\n", timeH, timeM, timeS);
}

int main (void) {//void because no argc or argv being used
    double oxidationTemp;
    double initThickness;
    double totalThickness;

    //Take in temperature and convert to celsius
    printf("What is the temperature (in Celsius)? ");
    scanf("%lf", &oxidationTemp);
    oxidationTemp += 273.15;

    //Input initial oxide thickness and converting nm to micrometers
    printf("What is the initial oxide thickness (in nm)? ");
    scanf("%lf", &initThickness);
    initThickness /= 1000;

    //Input desired thickness and converting nm to micrometers
    printf("What is the desired oxide thickness (in nm)? ");
    scanf("%lf", &totalThickness);
    totalThickness /= 1000;

    //DRY Process
    double dryB = getB(0, oxidationTemp);
    double dryA = getA(0, oxidationTemp);
    double dryTime = getTime(initThickness, totalThickness, dryA, dryB);

    printf("\n[DRY Process]\n");
    printf("Required growth time is about %lf hrs ", dryTime/3600);
    printHMS(dryTime);

    //WET Process
    double wetB = getB(1, oxidationTemp);
    double wetA = getA(1, oxidationTemp);
    double wetTime = getTime(initThickness, totalThickness, wetA, wetB);

    printf("\n[WET Process]\n");
    printf("Required growth time is about %lf hrs ", wetTime/3600);
    printHMS(wetTime);

    return EXIT_SUCCESS;
}