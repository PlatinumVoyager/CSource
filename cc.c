#include <stdio.h>
#include <libssh/libssh.h>

#define MAX_SIZE 100

struct this_struct 
{
    char c;
    int x;
};

int main(void)
{
    struct this_struct *p_struct, t_struct;
    p_struct = &t_struct;

    (*p_struct).c = 'A';
    (*p_struct).x = 10;

    printf("%c : %d\n", p_struct->c, p_struct->x);

    return 0;
}