#include <stdio.h>

struct memory {
    char *mem_device;
    int serial_id;
};

int main(void)
{
    struct memory *m_ptr;
    struct memory memory_struct;

    m_ptr = &memory_struct;

    (*m_ptr).mem_device = "ITACHI3490_HD2";
    (*m_ptr).serial_id = 109880033298001;

    int i = 0;

    switch (i) {
        case 0:
            printf("0");
        
        case 1:
            printf("1");

        default:
            printf("none");
    }

    return 0;
}