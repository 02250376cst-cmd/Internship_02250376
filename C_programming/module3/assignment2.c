/*
 * trig_table.c
 *
 * Prints a table of sine and cosine values for arguments
 * spanning the open interval (0, 1) radians.
 */

#include <stdio.h>
#include <math.h>

/* Number of interior points to sample between 0 and 1 (exclusive). */
#define NUM_STEPS 9

/*
 * print_trig_table
 * -----------------
 * Prints a formatted table of sine and cosine values for arguments
 * evenly spaced across the open interval (0, 1).
 *
 * The interval is divided into (NUM_STEPS + 1) equal segments so
 * that the endpoints 0 and 1 themselves are never printed, only the
 * interior sample points (e.g. 0.1, 0.2, ..., 0.9 when NUM_STEPS
 * is 9).
 *
 * Parameters: none
 * Returns:    nothing (void)
 */
void print_trig_table(void)
{
    int i;
    double x;
    double step = 1.0 / (NUM_STEPS + 1);  /* spacing between sample points */

    printf("%10s %15s %15s\n", "x", "sin(x)", "cos(x)");
    printf("---------------------------------------------\n");

    for (i = 1; i <= NUM_STEPS; i++)
    {
        x = i * step;
        printf("%10.4f %15.6f %15.6f\n", x, sin(x), cos(x));
    }
}

/*
 * main
 * ----
 * Entry point. Calls print_trig_table() to display the sine and
 * cosine values, then exits.
 */
int main(void)
{
    print_trig_table();
    return 0;
}