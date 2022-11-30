#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TARGET "192.168.0.1"

struct def_buff {
    char *buffer;
};

char target_str[] = TARGET;

int main(void)
{
    struct def_buff db;
    
    db.buffer = (char *) malloc(strlen(target_str) * sizeof(char));
    strcpy(db.buffer, target_str);

    printf("%s\n%lu\n", db.buffer, strlen("this string"));

    return 0;
}