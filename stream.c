#include <stdio.h>

int main(void)
{
    char buffer[256];

    puts(gets(buffer));

    return 0;
}