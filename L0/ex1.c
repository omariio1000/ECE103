#include <stdio.h>

int main (void) {
    printf(" x   x^2\n");
    printf("--   ---\n");
    for (int x = 0; x <= 10; x++) printf("%2d   %3d\n", x, x*x);
    return 0;
}