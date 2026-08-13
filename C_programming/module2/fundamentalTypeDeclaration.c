#include <stdio.h>

int main(void)
{
    int a = 5, b = 7, c = 6; //declare and initialize values
    double average = 0.0; // good practice)

    printf("a = %d, b = %d, c = %d\n", a, b, c);
    average = (a + b + c) / 3.0; // calculate the average
    printf("average = %lf\n", average);
    return 0;
}