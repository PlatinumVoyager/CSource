#include <stdio.h>
#include <string.h>

int main(void)
{   
    // memset test
    char str[50] = "This is just a string to use memset on";
    printf("Before memset() -> %s\n", str);

    memset(str + 13, '.', 8 * sizeof(char));
    printf("After memset() -> %s\n", str);

    return 0;
}