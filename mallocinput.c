#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

char *input;

int main(void)
{
    if ((input = (char *) malloc(30 * sizeof(char))) == NULL) {
        fprintf(stderr, "Failed to allocate %lu bytes of memory for buffer, %s\n",
                    30 * sizeof(char), strerror(errno));
        exit(1); // exit no need to continue further
    }

    printf("Enter 30 chars or less:: ");
    gets(input);

    printf("Value => \"%s\"\n", input);
    free(input);

    return 0;
}
