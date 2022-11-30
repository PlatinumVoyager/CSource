#include <stdio.h>

#define MAX 4

struct part {
    short number;
    char name[12];

} data[MAX] = {{ 1, "Thomas"},
                    { 2, "Stanley"},
                    { 3, "Jason"},
                    { 4, "Marshall"}
};

int i;
struct part *p_part;

int main(void)
{
    p_part = &data[0]; // could be p_part = &data; <- data[0] points to the same memory address

    // loop through array
    for (i = 0; i < MAX; i++)
    {
        printf("At address %p: %d %s\n", p_part, (*p_part).number, p_part->name); // because why not?
        p_part++;
    }

    return 0;
}