#include <stdio.h>

struct ptr_struct 
{
    char *system_id;
};

int main(void)
{
    struct ptr_struct *p_part;
    struct ptr_struct ptr_cpy;

    p_part = &ptr_cpy;

    // set system_id char (ptr of type 'char')
    (*p_part).system_id = "SYSTEM ID IS NULL";
    printf("%s\n", p_part->system_id);

    p_part->system_id = "SYSTEM ID IS NOT NULL";
    printf("%s\n", (*p_part).system_id);

    return 0;
}