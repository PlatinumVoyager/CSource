#include <stdio.h>

// struct examples
struct SSN {
    int first_three;
    char dash1;
    int second_two;
    char dash2;
    int last_four;
};

struct date {
    char month[2];
    char day[2];
    char year[4];

} current_date;

struct time {
    int hours;
    int minutes;
    int seconds;

} time_of_birth = {8, 45, 0};

struct coord {
    int x;
    int y;
};

struct rectangle {
    struct coord topleft;
    struct coord bottomright;
};

struct data {
    short x[4];
    char y[10];
};

int main(void)
{
    struct rectangle mybox;

    mybox.topleft.x = 10;
    mybox.bottomright.x = 10;

    mybox.topleft.y = 100;
    mybox.bottomright.y = 100;

    // data struct
    struct data record;

    record.x[2] = 100; // accessing array elements using subscript notation
    record.y[8] = 'M'; // ...

    return 0;
}