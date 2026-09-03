// use of simple array

#include<stdio.h>
#define SIZE 5

int main(void)
{

    int grades[SIZE] = {56, 62, 67, 68, 67};
    double sum = 0.0;
    int i;

    printf("\n my grades are:\n");

    for (i = 0; i < SIZE; i++)
        printf("%d\t", grades[i]);

    printf("\n\n");

    for (i = 0; i < SIZE; i++)
        sum = sum + grades[i];

    printf("my average is %.2f \n\n", sum/SIZE);
    return 0;

}