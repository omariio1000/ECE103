#include <stdlib.h>
#include <stdio.h>

int main (void) {
    int x[] = {-5, -1,  2,  8, 13, 15, 20, 45, 66, 70};
    int y[] = {9,  5,  7, 12,  5, -4,  0,  3, 10,  8};

    double slope[9];

    for (int i = 1; i < 10; i++) slope[i - 1] = (double) (y[i] - y[i - 1]) / (double) (x[i] - x[i - 1]);
    for (int i = 0; i < 9; i++) printf("%.3lf%s", slope[i], i < 8 ? ", " : "\n");
}