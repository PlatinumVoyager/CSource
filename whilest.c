#include <stdio.h>

#define MAXCOUNT 20

int count;

int main(void)
{
    int count = 1;

    while (count <= MAXCOUNT) {
        printf("%d\n", count++);
    }

    /* for statement (construct) equivalent to while
    for (; condition ;)
    
    */

    return 0;
}