// love you how much? 1 billion times
// demonstrates the us of loop with while

#include <stdio.h>

int main(void)
{
    int repeat = 0;
    printf("How Strong is your love 1-10? : ");
    scanf("%d", &repeat);
    printf("\nI love you very");
    while(repeat > 0)
    {
        printf("\n very");
        repeat--;
    }
    printf(" much.\n\n");
    return 0;
}