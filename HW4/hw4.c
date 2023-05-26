#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 128
#define WHITESPACE ", \n"

//typedef enum {solid, liquid, gas} state;

typedef struct elementStruct {
    char name[20];
    char mass[20];
    char state[20];
    char density[20];
    int atomicNum;
    char symbol[3];
} element;

void printElement(element *printing) {
    printf("Atomic#\t= %d\n", printing -> atomicNum);
    printf("Symbol\t= %s\n", printing -> symbol);
    printf("Name\t= %s\n", printing -> name);
    printf("AtomMass\t= %s u\n", printing -> mass);
    printf("StdState\t= %s\n", printing -> state);
    printf("Density\t= %s g/cm^3\n\n", printing -> density);
}

int main (void) {
    char buff[BUFFER_SIZE];
    element *elements;
    FILE *in = fopen("element_data.txt", "r");
    if (!in) {
        perror("failed to open file");
        return EXIT_FAILURE;
    }

    fgets(buff, BUFFER_SIZE, in);
    int rows;
    fscanf(in, "%d", &rows);
    

    elements = (element *) calloc(rows, sizeof(element));
    for (int i = 0; i < rows; i++) {
        fscanf(in, "%d", &elements[i].atomicNum);
        fscanf(in, "%3[^,]", elements[i].symbol);
        fscanf(in, "%20[^,]", elements[i].name);
        fscanf(in, "%20[^,]", elements[i].mass);
        fscanf(in, "%20[^,]", elements[i].state);
        fscanf(in, "%20[^,]", elements[i].density);
        printElement(&elements[i]);
    }

    free(elements);
    return EXIT_SUCCESS;
}