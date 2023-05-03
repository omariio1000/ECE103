#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 128
#define WHITESPACE ", \n"

int main(void) {
    char buff[BUFFER_SIZE];
    printf("Greetings, my name is Sarah.\n");
    printf("\nPlease enter your first and last name: ");
    fgets(buff, BUFFER_SIZE, stdin);
    

    //doesn't have to be dynamic, can just be normal char array
    char *first;
    char *last;

    first = (char*) calloc(strlen(buff) + 1, sizeof(char));
    last = (char*) calloc(strlen(buff) + 1, sizeof(char));

    if (strstr(buff, ",") != NULL) {
        char *remain = buff;
        remain = strtok(remain, WHITESPACE);
        strcpy(last, remain);
        remain = strtok(NULL, WHITESPACE);
        strcpy(first, remain);
    }
    else sscanf(buff, "%s %s", first, last);

    printf("\nHello, %s %s.\n", first, last);

    printf("\nYour first name has %d characters.\n", (int) strlen(first));
    printf("Your last name has %d characters.\n", (int) strlen(last));

    if (!strcmp(first, "Sarah") || !strcmp(first, "sarah")) printf("\nYou and I have the same first name!\n");
    else printf("\nYou and I have different first names.\n");

    printf("\nI will call you %s \"Viking\" %s from now on!\n", first, last);

    if (first) free(first);
    if (last) free(last);

    return EXIT_SUCCESS;
}