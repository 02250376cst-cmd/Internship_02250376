/*
 * elephant_seal_average.c
 *
 * Reads a whitespace-separated list of northern elephant seal
 * (Mirounga angustirostris) weights from a data file into an
 * array, then computes and reports the average weight.
 *
 * Usage:
 *   ./elephant_seal_average elephant_seal_data.txt
 *
 * Author: (your name here)
 */

#include <stdio.h>
#include <stdlib.h>

/* Starting capacity for the weights array; the array doubles in
 * size automatically if more room is needed, so the program is not
 * limited to a fixed number of data points. */
#define INITIAL_CAPACITY 512

/*
 * read_weights
 * -------------
 * Reads integer weights from the given file stream into a
 * dynamically-allocated array.
 *
 * file:  an already-opened, readable file stream of whitespace-
 *        separated integers.
 * count: output parameter; set to the number of weights read.
 *
 * Returns a pointer to a heap-allocated array of `*count` ints.
 * The caller is responsible for calling free() on the returned
 * pointer. Exits the program if memory allocation fails.
 */
int *read_weights(FILE *file, int *count) {
    int capacity = INITIAL_CAPACITY;
    int *weights = malloc(capacity * sizeof(int));
    if (weights == NULL) {
        fprintf(stderr, "Error: unable to allocate memory.\n");
        exit(EXIT_FAILURE);
    }

    int n = 0;
    int value;

    /* fscanf returns the number of items successfully matched;
     * it returns EOF (or 0) once the file is exhausted. */
    while (fscanf(file, "%d", &value) == 1) {
        if (n == capacity) {
            capacity *= 2;
            int *resized = realloc(weights, capacity * sizeof(int));
            if (resized == NULL) {
                fprintf(stderr, "Error: unable to allocate memory.\n");
                free(weights);
                exit(EXIT_FAILURE);
            }
            weights = resized;
        }
        weights[n++] = value;
    }

    *count = n;
    return weights;
}

/*
 * average
 * -------
 * Computes the arithmetic mean of the values in an array.
 *
 * weights: array of integer weights.
 * count:   number of elements in the array (must be > 0).
 *
 * Returns the average as a double.
 */
double average(const int weights[], int count) {
    long sum = 0;  /* long avoids overflow when summing many weights */

    for (int i = 0; i < count; i++) {
        sum += weights[i];
    }

    return (double) sum / count;
}

int main(int argc, char *argv[]) {
    const char *filename = (argc > 1) ? argv[1] : "elephant_seal_data.txt";

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: could not open file \"%s\".\n", filename);
        return EXIT_FAILURE;
    }

    int count;
    int *weights = read_weights(file, &count);
    fclose(file);

    if (count == 0) {
        fprintf(stderr, "Error: no weight data found in \"%s\".\n", filename);
        free(weights);
        return EXIT_FAILURE;
    }

    double avg = average(weights, count);

    printf("Northern Elephant Seal (Mirounga angustirostris) Weights\n");
    printf("----------------------------------------------------------\n");
    printf("Number of seals read : %d\n", count);
    printf("Average weight        : %.2f lbs\n", avg);

    free(weights);
    return EXIT_SUCCESS;
}