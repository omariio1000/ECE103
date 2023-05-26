#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 100

void copy_norep(char dst[], char src[]) {
    int srcIdx = 0;
    int destIdx = 0;
    char rep = '\0';

    while (src[srcIdx] != '\0') {
        if (src[srcIdx] == rep) {
            srcIdx++;
            continue;
        }
        else {
            rep = src[srcIdx];
            dst[destIdx] = rep;
            srcIdx++;
            destIdx++;
        }
    }
    dst[destIdx] = '\0';
    return;
}

int main (void) {
	char src[BUFFER_SIZE];
    char dst[BUFFER_SIZE];

    printf("Enter src: ");
    fgets(src, BUFFER_SIZE, stdin);
    
    copy_norep(dst, src);
    printf("dst holds: %s", dst);

	return EXIT_SUCCESS;
}