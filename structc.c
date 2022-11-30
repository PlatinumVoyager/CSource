#include <stdio.h>

struct c_struct
{
    char x, a;
    int i;
};

int main(void)
{
    struct c_struct *c_ptr, c_cpy;
    c_ptr = &c_cpy;

    (*c_ptr).x = 'a';
    (*c_ptr).a = 'b';
    (*c_ptr).i = 10;

    printf("%c %c %d\n", c_ptr->x, c_ptr->a, c_ptr->i);

    return 0;
}