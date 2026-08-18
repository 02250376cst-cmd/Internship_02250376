// IF and ELSE statements in C
#include <stdio.h>

int main()
{
    int speed;
    printf("\nEmter your speed as an integer:");
    scanf("%d", &speed);
    if (speed < 65)
        printf("\nno speeding ticket\n\n");
    else
        printf("\nspeeding ticket\n\n");
    return 0;
}