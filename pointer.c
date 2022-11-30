#include <stdio.h>

int var = 1;
int *ptr;

int main(void)
{
    // initialize ptr to point to var
    ptr = &var; 

    // access var directly and indirectly
    printf("Direct access to var: %d\n", var);
    printf("Indirect access to var: %d\n\n", *ptr);

    // display the address of the two vars
    printf("The address of var = %p\n", &var);
    printf("The address of var = %p\n", ptr);

    return 0;
}