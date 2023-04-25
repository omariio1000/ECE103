#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void) {
    int seed;
    printf("Enter seed value (-999 for random): ");
    scanf("%d", &seed);
    if (seed == -999) srand(time(NULL));
    else srand(seed);

    int count[13];
    for (int i = 0; i < 13; i++) count[i] = 0;

    for (int i = 0; i < 50000; i++) {
        int d1 = rand() % 6 + 1;
        int d2 = rand() % 6 + 1;
        count[d1 + d2]++;
    }

    printf("\nSum\tCount\tAppear\n");
    for (int i = 2; i < 13; i++)
        printf("%d:\t%d\t%.2lf%%\n", i, count[i], 100 * count[i]/50000.0);

    return EXIT_SUCCESS;
}