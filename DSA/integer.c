/*
 * =====================================================================================
 * File:         file_array_stats.c
 * Description:  Reads an integer file where the first integer specifies the total count 
 *               of subsequent elements. Computes the average (double) and maximum (int)
 *               values, printing results to the screen and writing to 'answer-hw3'.
 * Course:       C for Everyone, Part 2: Structured Programming
 * Assignment:   Week 4 Assignment: Arrays (Option 1)
 *
 * Compilation:  gcc -O2 file_array_stats.c -o file_array_stats
 * Execution:    ./file_array_stats input.txt
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>

// Function to compute the average of an array as a double
double compute_average(const int data[], int size) {
    if (size <= 0) return 0.0;
    long sum = 0;
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }
    return (double)sum / size;
}

// Function to compute the maximum value of an array as an int
int compute_max(const int data[], int size) {
    if (size <= 0) return 0;
    int max_val = data[0];
    for (int i = 1; i < size; i++) {
        if (data[i] > max_val) {
            max_val = data[i];
        }
    }
    return max_val;
}

int main(int argc, char *argv[]) {
    // Determine input filename (command-line argument or fallback to default 'input.txt')
    const char *input_filename = (argc > 1) ? argv[1] : "input.txt";

    // 1. Open input file for reading
    FILE *ifp = fopen(input_filename, "r");
    if (ifp == NULL) {
        fprintf(stderr, "Error: Could not open input file '%s'.\n", input_filename);
        return EXIT_FAILURE;
    }

    // 2. Read array size from the first integer in the file
    int size = 0;
    if (fscanf(ifp, "%d", &size) != 1 || size <= 0) {
        fprintf(stderr, "Error: Invalid array size specified in file.\n");
        fclose(ifp);
        return EXIT_FAILURE;
    }

    // 3. Dynamically allocate array for the data
    int *data = (int *)malloc(size * sizeof(int));
    if (data == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        fclose(ifp);
        return EXIT_FAILURE;
    }

    // 4. Read the remaining values into the array
    for (int i = 0; i < size; i++) {
        if (fscanf(ifp, "%d", &data[i]) != 1) {
            fprintf(stderr, "Error: File contained fewer elements than specified (%d expected).\n", size);
            free(data);
            fclose(ifp);
            return EXIT_FAILURE;
        }
    }
    fclose(ifp);

    // 5. Compute statistics
    double average = compute_average(data, size);
    int max_value = compute_max(data, size);

    // 6. Output neatly to console
    printf("=== Input Data Summary ===\n");
    printf("Array Size : %d\n", size);
    printf("Data Items : ");
    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    printf("\n--------------------------\n");
    printf("Average    : %.4f\n", average);
    printf("Max Value  : %d\n", max_value);
    printf("==========================\n");

    // 7. Output neatly to 'answer-hw3'
    FILE *ofp = fopen("answer-hw3", "w");
    if (ofp == NULL) {
        fprintf(stderr, "Error: Could not open output file 'answer-hw3' for writing.\n");
        free(data);
        return EXIT_FAILURE;
    }

    fprintf(ofp, "Array Size : %d\n", size);
    fprintf(ofp, "Data Items : ");
    for (int i = 0; i < size; i++) {
        fprintf(ofp, "%d ", data[i]);
    }
    fprintf(ofp, "\nAverage    : %.4f\n", average);
    fprintf(ofp, "Max Value  : %d\n", max_value);

    fclose(ofp);
    free(data);

    printf("\nResults successfully written to 'answer-hw3'.\n");
    return EXIT_SUCCESS;
}