#include <stdio.h>

char lname[257], fname[257];
int count, id_num;

int main(void)
{
    puts("Enter last name, first name, id number sep = <space>");

    count = scanf("%s%s%d", lname, fname, &id_num); // array names are pointers to the lowest (first) byte address
    printf("%d items entered: %s %s %d\n", count, lname, fname, id_num);

    return 0;
}