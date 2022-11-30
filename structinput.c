#include <stdio.h>

int length, width;
long area;

struct xyz {
    int x, y, z;
};

struct coord {
    int x;
    int y;
};

struct rectangle {
    struct coord topleft;
    struct coord bottomright;
    
} mybox;

int main(void)
{
    printf("Enter the top left x coordinate: ");
    scanf("%d", &mybox.topleft.x);

    printf("Enter the top left y coordinate: ");
    scanf("%d", &mybox.topleft.y);

    printf("Enter the bottom right x coordinate: ");
    scanf("%d", &mybox.bottomright.x);

    printf("Enter the bottom right y coordinate: ");
    scanf("%d", &mybox.bottomright.y);

    width = mybox.bottomright.x - mybox.topleft.x;
    length = mybox.topleft.y - mybox.bottomright.y;

    area = width * length;
    printf("\n\nThe area is %ld units.\n", area);

    return 0;
}