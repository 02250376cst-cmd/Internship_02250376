//char in c
// a fundamental data type in c

#include  <stdio.h>

int main(void)
{
    char c = 'A'; // declare and initialize a char variable
    printf("c in ASCII is %d\n", c);
    printf("c the character is %c\n", c);
    printf("Three consecutive chars are : %c%c%C \n", c, c+1, c+2);
    printf("Three bell rings are : %c%c%c \n ", '\a', '\a', '\a');
    return 0;

}