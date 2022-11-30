#include <stdio.h>

struct this_struct 
{
    char *c;
    int x;
};

int main(void)
{
    struct this_struct *struct_one, this_cpy;
    struct_one = &this_cpy;

    (*struct_one).x = 10;

    printf("VALUE: %s\n", (struct_one->c) ? struct_one->c : "N/A");

    return 0;
}