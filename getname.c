#include <stdio.h>
#include <stdlib.h>

char *str;

int main(void)
{
    str = (char *) malloc(20 * sizeof(char));
    if (str == NULL) {
        puts("memalloc failed");
        return 1;
    }

    printf("Enter name: ");
    scanf("%s", str);

    printf("Your name is: %s\n", str);
    free(str);

    return 0;
}