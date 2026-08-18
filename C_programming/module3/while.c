#include <stdio.h>

int main(void)
{
    int blanks = 0, digits = 0, letters = 0, others = 0;
    int c; // variable to hold the character input
    while ((c = getchar()) != EOF) // read characters until EOF
    {
        if (c == ' ')
            ++blanks; // count blanks
        else if (c >= '0' && c <='9')
            ++digits; // count digits
        else if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
            ++letters; // count letters
        else
            ++others; // count other characters
    }
    printf(" blanks = %d, digits =%d, letters = %d,", blanks, digits, letters);
    printf("others = %d\n\n", others);
    return 0;

}
