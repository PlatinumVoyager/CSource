#include <stdio.h>
#include <stdlib.h>

void write_file(FILE *file);
void read_file(FILE *file);

int main(void)
{
    FILE *fp;

    if ((fp = fopen("basics_fio.txt", "r")) == NULL)
    {
        fprintf(stderr, "Failed to open file. No such file exists");

        return -1;
    }

    fclose(fp);

    return 0;
}

void write_file(FILE *file)
{


    return NULL;
}

void read_file(FILE *file)
{


    return NULL;
}