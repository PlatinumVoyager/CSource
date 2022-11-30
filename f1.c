#include <stdio.h>

extern int my_var;

int main(void)
{
    my_var = 20;
    print_value();

    return 0;
}