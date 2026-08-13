// the distance of a marathon in km

# include <stdio.h>

int main(void)
{
    int miles, yards;
    double kilometers;

    printf("\nEnter the distance of a marathon in miles and yards:");
    scanf("%d %d", &miles, &yards);
    kilometers = 1.609 * (miles + yards / 1760.0);
    printf("\nA marathon is %lf kilometers.\n", kilometers);
    return 0;


}