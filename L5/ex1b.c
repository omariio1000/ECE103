#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct MyStruct {
    char str[50];
    int ivar;
    double dvar;
};

int main(void) {
    struct MyStruct A;
    strcpy(A.str, "Hello");
    A.ivar = 21;
    A.dvar = 3.14;

    struct MyStruct B;
    strcpy(B.str, "Goodbye");
    B.ivar = 36;
    B.dvar = 12.34;

    struct MyStruct *p;
    p = &B;


    printf("Members of A:\n");
    printf("  str = %s\n", A.str);
    printf("  ivar = %d\n", A.ivar);
    printf("  dvar = %lf\n", A.dvar);
    
    printf("Members of B:\n");
    printf("  str = %s\n", p -> str);
    printf("  ivar = %d\n", p -> ivar);
    printf("  dvar = %lf\n", p -> dvar);

}