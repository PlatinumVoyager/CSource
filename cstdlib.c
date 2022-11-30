#include <stdio.h>
#include <ctype.h>

struct stdlib {
    int a;
    char c;
    int hex;
};

int main(void)
{
    struct stdlib *s_ptr;
    struct stdlib s_struct;

    s_ptr = &s_struct;

    (*s_ptr).a = 10;
    (*s_ptr).c = 'c';
    (*s_ptr).hex = 30;

    printf("%d (%p) | %d (%p)\n", isalnum(s_ptr->a), &s_ptr->a,
                                  isalpha(s_ptr->c), &s_ptr->c);
                                  
    printf("%d\n", isxdigit(s_ptr->hex));

    return 0;
}
