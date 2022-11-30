#include <stdio.h>

struct sale {
    char customer[21];
    char item[20];
    float amount;

} mysale = {
    "Acme Industries",
    "Left-handed widget",
    1000.00
};

struct customer {
    char firm[21];
    char contact[25];
};

struct sales {
    struct customer buyer;
    char item[20];
    float amount;

} gosale = {{ "Acme Industries", "George Adams" },
              "Left-handed widget",
              200.00
};

struct IPAddress {
    char hostname[30];
    char ipversion[4];
    char ipaddress[16];

} target = {
    "Cisco Systems",
    "IPv4",
    "237.56.18.91"
};

struct IPAddress STScanner[10000];

int main(void)
{
    puts(target.hostname);
    printf("%.2f %s %s\n", mysale.amount, mysale.customer, mysale.item);

    return 0;
}