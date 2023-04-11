#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char a, b;
    a = 127;
    unsigned char c;
    b = a * 2;
    c = a * 2;

    printf("a: %d, b: %d, c: %d\n", a, b, c);
    int d = 7697264;
    printf("d with %%d: %d, d with %%f: %f\n", d, d);
    printf("&d with %%s: %s\n", &d);

    return EXIT_SUCCESS;
}