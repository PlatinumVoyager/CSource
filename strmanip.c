#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *orignal, *token;

int main(void)
{
    orignal = strdup("Cats,Dogs,Mice,,,Dwarves,Elves:High,Elves:Wood");
    while ((token = strsep(&orignal, ",:")) != NULL) {
        fprintf(stdout, "token: %s\n", token);
    }

    return 0;
}