#include <stdio.h>
#include <stdlib.h>

int checkSmallest(int vals[], int size) {
    int smallest = vals[0];
    for (int i = 0; i < size; i++) if (vals[i] < smallest) smallest = vals[i];
    return smallest;
}

int main (void) {
    int size = 5;
    int vals[size];

    printf("Enter %d values: ", size);
    for (int i = 0; i < size; i++) scanf("%d", &vals[i]);

    printf("Smallest = %d\n", checkSmallest(vals, size));

    return EXIT_SUCCESS;
}