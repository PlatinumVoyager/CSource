#include <stdio.h>
#include <stdlib.h>

#define FILE_HANDLE "new_file_c.txt"

int main(void)
{
    char c;
    FILE *fp;

    if ((fopen(FILE_HANDLE, "r+")) == NULL)
    {
        fprintf(stderr, "failed to open file: %s\n", FILE_HANDLE);
        return -1;
    }

    while ((c = fgetc(fp)) != EOF)
    {
        if (c == '.') 
        {
            c = '!';
        }

        fputc(c, fp);
    }

    fclose(fp);

    return 0;
}