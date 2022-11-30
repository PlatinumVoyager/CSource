#include <stdio.h>

unsigned char ascii;

int main(void)
{
    for (ascii = 180; ascii < 204; ascii++)
    {
        printf("ASCII code %d is character %c\n", ascii, ascii);
    }

    return 0;
}