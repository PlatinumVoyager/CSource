#include <stdio.h>

struct entry {
    char fname[20];
    char lname[20];
    char phone[13];
};

int i;
struct entry list[4];

int main(void) 
{
    for (i = 0; i < 4; i++)
    {
        printf("#Entry listing: %d\n", i);

        printf("Enter first name: ");
        scanf("%s", list[i].fname);

        printf("Enter last name: ");
        scanf("%s", list[i].lname);

        printf("Enter phone: ");
        scanf("%s", list[i].phone);    
    
    }

    for (i = 0; i < 4; i++)
    {
        printf("Name: %s %s\nNumber: %s\n", list[i].fname, list[i].lname, list[i].phone);
    }

    return 0;
}