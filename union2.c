#include <stdio.h>

#define FLOAT     'F'
#define INTEGER   'I'
#define CHARACTER 'c'

struct generic_tag {
    char type;
    union shared_tag 
    {
        char c;
        int i;
        float f;

    } shared; // we can use this once we initialize it
};

typedef struct {
    int x;
    char c;
} coord;

coord topleft, bottomright;

void print_function(struct generic_tag generic);

int main(void)
{
    struct generic_tag var;

    var.type = CHARACTER; // value = 'c'
    var.shared.c = '$';
    
    print_function(var);

    var.type = FLOAT;
    var.shared.f = (float) 12345.67890;

    print_function(var);

    var.type = 'x';
    var.shared.i = 111;

    print_function(var);

    return 0;
}

void print_function(struct generic_tag generic)
{
    printf("The generic value is...");
    switch (generic.type)
    {
        case CHARACTER:
            printf("%c\n", generic.shared.c);
            break;
        
        case INTEGER:
            printf("%i\n", generic.shared.i);
            break;
        
        case FLOAT:
            printf("%f\n", generic.shared.f);
            break;

        default:
            printf("unknown type: %c\n", generic.type);
            break;
    }

    return;
}