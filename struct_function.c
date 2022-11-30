#include <stdio.h>

#define SIZE 30

struct data 
{
    float amount;
    char fname[SIZE];
    char lname[SIZE];

} rec;

// WHYYYYYYY :(

// prototype that takes a struct as an argument
void print_rec(struct data entry);

int main(void)
{
    struct data *d_part;
    d_part = &rec;

    printf("Enter the persons first and last name: ");
    scanf("%s %s", d_part->fname, d_part->lname);

    printf("Enter amount to pay: ");
    scanf("%f", &d_part->amount);
    
    print_rec(*d_part);

    return 0;
}

void print_rec(struct data entry)
{
    printf("Person %s %s payed $%.2f\n", entry.fname, entry.lname, entry.amount);

    return;
}