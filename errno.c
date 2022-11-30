#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

// you wont find anything on this PC worth looking at, I dont know what the fuck im doing honestly

int main(int argc, char *argv[])
{
    FILE *fp;

    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "error reading file: %s\n", strerror(errno));
        exit(1);
    }

    fclose(fp);
    printf("done: shouldn\'t reach this point\n");
    
    return 0;
}
