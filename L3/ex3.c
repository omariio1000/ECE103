#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 128

int main(void) {
    char buff[BUFFER_SIZE];
    printf("Greetings, my name is Sarah.\n");
    printf("\nPlease enter your first and last name: ");
    fgets(buff, BUFFER_SIZE, stdin);
    
    if (strstr(buff, ",") != NULL) {

    }
    else {

    }

    return EXIT_SUCCESS;
}