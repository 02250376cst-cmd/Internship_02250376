// use of simple bubble sort algorithm to sort an array of integers in ascending order

#include <stdio.h>
#define SIZE 5

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_array(int how_many, int data[], char *str)
{
    int i;
    printf("%s\n", str);

    for (i = 0; i < how_many; i++)
        printf("%d\t", data[i]);

}

void bubble_sort(int data[], int how_many)

{
    int i, j;
    int go_on;

    for (i = 0; i < how_many; i++)
    {
        print_array(how_many, data, "\ninside bubble\n");
        printf("i = %d, input any int to continue: ", i);
        scanf("%d", &go_on);
        for (j = how_many - 1; j > i; j--)
        {
            if (data[j - 1] > data[j])
                swap(&data[j - 1], &data[j]);
        }
    }
}

int main(void)
{
    int grades[SIZE] = {56, 62, 67, 68, 67};

    printf("\n my grades are:\n");
    print_array(SIZE, grades, "before bubble sort");

    bubble_sort(grades, SIZE);

    print_array(SIZE, grades, "\nafter bubble sort");
    return 0;
}