#include <stdio.h>
#include <string.h>

struct s1 {
    int i;
    char str[30];
} s2;

int main(void)
{
    strcpy(s2.str, "this text");
    printf("%s\n", s2.str);

    return 0;
}