#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

int main (void) {
    FILE *out = NULL;
    out = fopen("data.txt", "w");
    if (!out) {
        perror("failed to open file");
        return EXIT_FAILURE;
    }

    int N;
    printf("Enter the desired size of the dynamic array: ");
    scanf("%d", &N);
    if (N < 1) N = 1;
    else if (N > 100) N = 100;

    int *arr;
    arr = (int*) calloc(N, sizeof(int));

    srandom(time(NULL));
    for (int i = 0; i < N; i++) {
        arr[i] = floor(random() % 201) - 100;
        fprintf(out, "%d\n", arr[i]);
    }
    

    free(arr);
    fclose(out);
    return EXIT_SUCCESS;
}