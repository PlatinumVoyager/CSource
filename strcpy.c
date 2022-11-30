#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *buffer;
    char string[] = "THIS STRING";

    buffer = (char *) malloc(strlen(string) * sizeof(char));

    strcpy(buffer, string);
    printf("%s (%p) %lu\n", buffer, buffer, buffer);

    return 0;
}
