/*
 * sine_calculator.c
 *
 * Reads a single floating-point value x from standard input, where
 * 0 < x < 1 (radians), and prints an approximation of sin(x).
 *
 * The approximation is computed with a Taylor series expansion:
 *
 *     sin(x) = x - x^3/3! + x^5/5! - x^7/7! + ...
 *
 * Because 0 < x < 1, the series converges quickly, so only a handful
 * of terms are needed to reach double-precision accuracy. Summing the
 * terms until they become negligibly small (rather than using a fixed
 * term count) keeps the result accurate without wasted computation.
 *
 */

#include <stdio.h>
#include <math.h>

/* Smallest term magnitude at which the series is considered to have
 * converged. Terms smaller than this contribute nothing measurable
 * to a double-precision result. */
#define CONVERGENCE_THRESHOLD 1e-15

/* Upper bound on the number of terms to sum, as a safety net against
 * an infinite loop in case convergence is never detected. */
#define MAX_TERMS 100

/*
 * compute_sine
 *
 * Approximates sin(x) using the Taylor series expansion described
 * above. Assumes x is small enough (here, 0 < x < 1) for the series
 * to converge in relatively few terms.
 *
 * Parameters:
 *   x - the input value, in radians.
 *
 * Returns:
 *   The approximate value of sin(x).
 */
double compute_sine(double x)
{
    double term = x;   /* current term in the series, starting with x itself */
    double sum = x;     /* running total of the series                        */
    int n;

    for (n = 1; n < MAX_TERMS; n++)
    {
        /* Each successive term is derived from the previous one:
         *   term_n = -term_(n-1) * x^2 / ((2n)(2n+1))
         * This avoids recomputing factorials and powers from scratch. */
        term *= -x * x / ((2.0 * n) * (2.0 * n + 1.0));
        sum += term;

        if (fabs(term) < CONVERGENCE_THRESHOLD)
        {
            break;
        }
    }

    return sum;
}

/*
 * read_input_value
 *
 * Prompts the user for a value and validates that it lies strictly
 * between 0 and 1. Re-prompts on invalid input.
 *
 * Parameters:
 *   value - pointer to a double where the validated input is stored.
 *
 * Returns:
 *   1 on success, 0 if input could not be read (e.g. end of stream).
 */
int read_input_value(double *value)
{
    int valid = 0;

    while (!valid)
    {
        printf("Enter a value strictly between 0 and 1: ");

        if (scanf("%lf", value) != 1)
        {
            return 0;
        }

        if (*value > 0.0 && *value < 1.0)
        {
            valid = 1;
        }
        else
        {
            printf("Value must be strictly between 0 and 1. Please try again.\n");
        }
    }

    return 1;
}

/*
 * main
 *
 * Reads a valid input value and prints its sine, computed both by
 * the Taylor series approximation and by the standard library for
 * comparison.
 */
int main(void)
{
    double x;
    double result;

    if (!read_input_value(&x))
    {
        fprintf(stderr, "Error: failed to read a valid input value.\n");
        return 1;
    }

    result = compute_sine(x);

    printf("sin(%.10f) approx = %.10f\n", x, result);
    printf("(standard library value: %.10f)\n", sin(x));

    return 0;
}