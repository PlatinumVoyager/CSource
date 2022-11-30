#include <stdio.h>

struct customer
{
    char firm[20];
    char name[25];
};

struct sale 
{
    struct customer buyer;
    char item[27];
    float amount;

} mysale = {{ "Acme Industries", "John Snow" },
              "A gift basket with flowers",
              33.56
};

struct ptr {
    char *name;
    int value;
};

struct data {
    int *value;
    int *rate;

} first;

struct msg {
    char *p1, *p2; // pointer structure members

} myptrs;

int cost, interest;

int main(void)
{
    struct ptr *ptr_struct;
    struct ptr data;

    ptr_struct = &data;
    (*ptr_struct).name = "THIS IS STRING";

    printf("%s\n", ptr_struct->name);

    cost = 10, interest = 20;

    first.value = &cost;
    first.rate = &interest;

    printf("%d (%p)\n", *first.value, first.value);

    myptrs.p1 = "Teach yourself C in one hour a day";
    myptrs.p2 = "By SAMS publishing";

    printf("%s (%p)\n%s (%p)\n", myptrs.p1, &myptrs.p1, myptrs.p2, &myptrs.p2);

    return 0;
}
