#include <stdio.h>

struct part
{
    short number;
    char *company;
};

struct agenda
{
    int agenda_id;
};

int main(void)
{   
    struct part *p_part; // need to declare another struct to point to the first lowest byte
    struct part gizmo;
    
    struct agenda *a_part;
    struct agenda agenda_struct;

    a_part = &agenda_struct;

    (*a_part).agenda_id = 10;
    printf("(*a_part).agenda_id = %d\n", agenda_struct.agenda_id);

    agenda_struct.agenda_id = 100;
    printf("agenda_struct.agenda_id = %d\n", a_part->agenda_id);

    a_part->agenda_id = 1000;
    printf("a_part->agenda_id = %d\n", (*a_part).agenda_id);

    p_part = &gizmo;

    (*p_part).number = 2100; // (*p_part) because (.) has high precedence over (*p_part)
    (*p_part).company = "THIS IS A STRING COMPANY";

    printf("%s (%p)\n", p_part->company, &p_part);

    // ways to get the value of number
    printf("%d\n%d\n%d\n", (*p_part).number, gizmo.number, p_part->number);

    return 0;
}