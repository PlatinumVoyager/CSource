#include <stdio.h>

struct struct_c
{
    char a;
    int b;
};

int main(void)
{
    int x;
    x = 10;

    printf("%d\n", x);

    int *ptr_x = &x;
    int **ptr_to_ptr_x = &ptr_x; // pointer to pointer = multiple indirection

    **ptr_to_ptr_x = 12; // x = 12

    printf("%d\n", **ptr_to_ptr_x);

    struct struct_c c_cpy, *c_ptr;
    c_ptr = &c_cpy;

    return 0;
}