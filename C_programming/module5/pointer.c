// uses of pointers

#include <stdio.h>
#define SIZE 5

int main(void)
{
    int grades[SIZE] = {56, 62, 67, 68, 67};
    double sum = 0.0;
    double *ptr_to_sum = &sum;
    int i;

    printf("\n my grades are:\n");

    for (i = 0; i < SIZE; i++)
        printf("%d\t", grades[i]);
    printf("\n\n");

    for (i = 0; i < SIZE; i++)
        sum = sum + grades[i];
    printf("Sum of grades: %.2f\n", sum/SIZE);

    printf("sum is at %p, or %lu and is %lf\n", ptr_to_sum, (unsigned long)ptr_to_sum, *ptr_to_sum);

    printf("grades are at %lu to %lu\n", (unsigned long)grades, (unsigned long)(grades + 5));
    return 0;
    
}