#include <stdio.h>

int length, width;
long area;

struct coord {
    int x;
    int y;

} mypoint;


int main(void) 
{
    mypoint.x = 12;
    mypoint.y = 14;

    printf("The coords are (%d,%d)...\n", mypoint.x, mypoint.y);

    return 0;
}