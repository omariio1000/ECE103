#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 128
#define WHITESPACE ",\n"

//typedef enum {solid, liquid, gas} state;

typedef struct elementStruct {//element struct
    char name[20];
    char mass[20];
    char state[20];
    char density[20];
    int atomicNum;
    char symbol[3];
} element;

void printElement(element *printing) {//function to print an element
    printf("\nAtomic#\t = %d\n", printing -> atomicNum);
    printf("Symbol\t = %s\n", printing -> symbol);
    printf("Name\t = %s\n", printing -> name);
    printf("AtomMass = %s u\n", printing -> mass);
    printf("StdState = %s\n", printing -> state);
    printf("Density = %s g/cm^3\n\n", printing -> density);
}

int findAtomic(int atomNumber, element *list, int rows) {//function to find element by atomic number
    for (int i = 0; i < rows; i++) if (list[i].atomicNum == atomNumber) return i;
    return -1;
}

int findName(char *name, element *list, int rows, int *results) {//function to find element by name 
    for (int i = 0; i < rows; i++) results[i] = -1;
    int resultNum = 0;
    int found = 0;
    
    for (int i = 0; i < BUFFER_SIZE; i++) {//lowercase input name
        if (name[i] == '\0') break;
        else name[i] = tolower(name[i]);
    }
    //printf("%s\n", name);
    
    for (int i = 0; i < rows; i++) {//compare every element
        char elemCopy[BUFFER_SIZE];
        strcpy(elemCopy, list[i].name);

        for (int i = 0; i < BUFFER_SIZE; i++) {//lowercase every element name
            if (elemCopy[i] == '\0') break;
            else elemCopy[i] = tolower(elemCopy[i]);
        }

        if (strstr(elemCopy, name)) {//if substring is in element name
            results[resultNum] = i;
            resultNum++;
            found = 1;
        }
    }

    return found;
}

int main (void) {
    char buff[BUFFER_SIZE];
    element *elements;
    FILE *in = fopen("element_data.txt", "r");
    if (!in) {//file not found
        perror("failed to open file");
        return EXIT_FAILURE;
    }

    fgets(buff, BUFFER_SIZE, in);
    int rows;
    fscanf(in, "%d", &rows);
    fgets(buff, BUFFER_SIZE, in); //throwaway line
    

    elements = (element *) calloc(rows, sizeof(element));
    for (int i = 0; i < rows; i++) {//read in element data
        fgets(buff, BUFFER_SIZE, in);
        char *remain = buff;
        
        remain = strtok(remain, WHITESPACE);
        elements[i].atomicNum = atoi(remain);

        remain = strtok(NULL, WHITESPACE);
        strcpy(elements[i].symbol, remain);

        remain = strtok(NULL, WHITESPACE);
        strcpy(elements[i].name, remain);

        remain = strtok(NULL, WHITESPACE);
        strcpy(elements[i].mass, remain);

        remain = strtok(NULL, WHITESPACE);
        strcpy(elements[i].state, remain);

        remain = strtok(NULL, WHITESPACE);
        strcpy(elements[i].density, remain);
        for (int j = 0; j < 20; j++) //weird way to fix the return error was having
            if (elements[i].density[j] == 13) elements[i].density[j] = 0;

    }

    
    int running = 1;

    while (running) {//while not quit
        int option = -1;

        printf("\nOptions:\n");
        printf(" [1] Display entire element array\n");
        printf(" [2] Search for specific atomic number\n");
        printf(" [3] Search for specific element name\n");
        printf(" [0] Quit\n");
        printf("Choice? ");

        scanf("%d", &option);
        fflush(stdin);

        //print all
        if (option == 1) for (int i = 0; i < rows; i++) printElement(&elements[i]);

        else if (option == 2) {//print by atomic number
            printf("\nEnter atomic number: ");
            scanf("%d", &option);
            fflush(stdin);

            option = findAtomic(option, elements, rows);
            if (option == -1) printf("\nNo element found with that atomic number.\n");
            else printElement(&elements[option]);
        }

        else if (option == 3) {//print by element name
            char name[BUFFER_SIZE];
            int res[rows];
            printf("\nEnter the element name: ");
            scanf("%s", name);
            fflush(stdin);

            int results = findName(name, elements, rows, res);
            if (!results) printf("\nNo element found with that name.\n");
            else for(int i = 0; i < rows; i++) {//look which elements were given in results
                if (res[i] == -1) break;
                else printElement(&elements[res[i]]);
            }
        }
        
        else if (option == 0) running = 0;

        else printf("\nInvalid option. Try again.\n");
    }

    free(elements);
    if (in != NULL) fclose(in);
    return EXIT_SUCCESS;
}