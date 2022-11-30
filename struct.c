#include <stdio.h>

int main(void)
{
    // c structures
    struct coord { // 1st way to declare and initialize structure
        int x;
        int y;
    };

    struct coord first1, second1;

    struct coord2 { // 2nd way to declare and initialize structure
        int x;
        int y;

    } first, second;

    // set structure variables
    first.x = 50;
    first.y = 100;

    second.x = 150;
    second.y = 200;

    // print variables 
    printf("%d, %d | %d, %d\n", first.x, first.y, second.x, second.y);

    return 0;
}