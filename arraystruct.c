#include <stdio.h>

#define NAMESIZE 30

struct data {
    float amount;
    char fname[NAMESIZE];
    char lname[NAMESIZE];

} record;

int main(void)
{
    printf("Enter the singers first and last name: ");
    scanf("%s %s", record.fname, record.lname);

    printf("Enter the ticket cost per person: ");
    scanf("%f", &record.amount);

    printf("The cost per ticket for singer %s %s = $%.2f\n", record.fname, record.lname, record.amount);

    return 0;
}