/* Conversion of Fahrenheit to Celsius

C = (F - 32)/ 1.8
*/

# include <stdio.h>

int main(void)
{
    int fahrenheit, celsius;

    printf("please enter the temperature in Fahrenheit;");
    scanf("%d", &fahrenheit);
    celsius = (fahrenheit - 32)/ 1.8;
    printf("\n %d fahrenheit is %d celsius.\n", fahrenheit, celsius);
    return 0;


}
