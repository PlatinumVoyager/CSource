#include <stdio.h>

char input[257];

int main(void)
{
    puts("Enter some text, then press Enter: ");
    gets(input); // has getchar(); functionality

    // gets() -> warning: this program uses gets(), which is unsafe();

    // getchar();
    printf("You entered: %s\n", input);

    return 0;
}
