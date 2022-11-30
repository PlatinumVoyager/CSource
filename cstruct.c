#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE 256

char input;
char *buffer;

struct s_struct 
{
    char mychar;
    int x;

} m_struct = {
    'A',
    10
};

int main(void)
{
    struct s_struct *s_ptr;
    struct s_struct data_struct;

    s_ptr = &data_struct;

    (*s_ptr).mychar = 'a';
    (*s_ptr).x = 10;

    printf("%c | %d\n", s_ptr->mychar, s_ptr->x);
    printf("%c | %d\n", m_struct.mychar, m_struct.x);

    buffer = (char *) malloc(BUFF_SIZE * sizeof(char));

    printf("Enter input: ");
    scanf("%s", &input);

    strcpy(buffer, &input);
    printf("%s (%p)\n", buffer, buffer);

    return 0;
}