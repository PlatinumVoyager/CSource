#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct get_addr
{
    int x;
    char c;
};

struct get_struct
{
    int a;
    char c;

    union shared_u
    {
        int a;
        char c;
    } shared;
};

int main(void)
{
    struct get_struct *struct1;
    struct get_struct struct_cpy;

    struct1 = &struct_cpy;

    (*struct1).a = 1;
    (*struct1).shared.a = 2;

    printf("%d | %d\n", struct1->a, struct1->shared.a);

    char *buffer;
    char string[] = "THIS STRING";

    buffer = (char *) malloc(strlen(string) * sizeof(char));

    strcpy(buffer, string);
    puts(buffer);

    return 0;
}
