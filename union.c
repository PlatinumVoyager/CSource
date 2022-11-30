#include <stdio.h>

union shared_tag
{
    char    c;
    int     i;
    long    l;
    float   f;
    double  d;

} shared;

int main(void)
{
    shared.c = '$';

    printf("char c = %c\n", shared.c);
    printf("int i = %d\n", shared.i);
    printf("long l = %ld\n", shared.l);
    printf("float f = %f\n", shared.f);
    printf("double d = %f\n", shared.d);

    shared.d = 123456788;

    printf("char c = %c\n", shared.c);
    printf("int i = %d\n", shared.i);
    printf("long l = %ld\n", shared.l);
    printf("float f = %f\n", shared.f);
    printf("double d = %f\n", shared.d);

    return 0;
}