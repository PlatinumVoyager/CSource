#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

char count, *ptr, *p;

int main(void)
{
    // allocate a block of 35 bytes
    // ptr = (char *) malloc(35 * sizeof(char)); // is typecasting to a char pointer necessary?
    // if (ptr == NULL) {
    //     puts("Memory allocation failed...");
    //     exit(1);
    // }

    if ((ptr = (char *) malloc(35 * sizeof(char))) == NULL) {
        fprintf(stderr, "** Memory allocation of %lu bytes failed, error: %s\n", 35 * sizeof(char), strerror(errno));
        exit(1);
    }

    // fill in the string with values 65 through 90
    // ascii codes for A-Z

    // p is a pointer used to step through the string
    // you want the ptr to remain pointed at the start of the string
    p = ptr;


    for (count = 65; count < 91; count++)
    {
        /*
            p = ptr; <- assign the address of ptr to p (ptr is the memory block allocated by malloc starting at the first
            lowest byte in the alloted address space)

        */

        *p++ = count; // *p++ means assign the value of the count to the current address of p, then go up by n bytes, count + 1
        // value of count is assigned to the address pointed to by p
        // count and p are incremented through each iteration of the for loop
    }

    // add NULL character return
    *p = '\0'; // '\0' = ASCII code for 0, 0 = end of string

    // display the string on the screen
    puts(ptr);
    free(ptr);

    return 0;
}
