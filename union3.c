#include <stdio.h>

struct generic 
{
    char type;
    union shared_generic
    {
        int i;
        char c;
        float f;

    } shared;
};

struct tag_f
{
    union tag_u
    {
        char c;
        int x;

    } u;
};

int main(void)
{
    struct generic var;
    struct tag_f generic;

    var.type = 'c';
    var.shared.f = 2.2;


    return 0;
}