#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIST_SIZE 100
#define ITEMS_PER_ROW 5

// Struct definition for a node in a singly linked list
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Helper function to create a new node
Node* create_node(int value) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}

// Function to generate a linked list of random integers
Node* generate_random_list(int size) {
    if (size <= 0) return NULL;

    Node *head = create_node(rand() % 1000); // Random numbers between 0 and 999
    Node *current = head;

    for (int i = 1; i < size; i++) {
        current->next = create_node(rand() % 1000);
        current = current->next;
    }
    return head;
}

// Routine to sort the linked list using Bubble Sort by swapping node data
void bubble_sort_list(Node *head) {
    if (head == NULL) return;

    int swapped;
    Node *ptr1;
    Node *lptr = NULL;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                // Swap values of adjacent nodes
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1; // Reduce range as the end gets sorted after each pass
    } while (swapped);
}

// Function to print the linked list formatted in rows of 5
void print_list_formatted(Node *head, int items_per_row) {
    Node *current = head;
    int count = 0;

    while (current != NULL) {
        printf("%5d ", current->data);
        count++;
        
        if (count % items_per_row == 0) {
            printf("\n");
        }
        current = current->next;
    }
    if (count % items_per_row != 0) {
        printf("\n");
    }
}

// Function to free dynamically allocated list memory
void free_list(Node *head) {
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    // Seed random number generator
    srand((unsigned int)time(NULL));

    // 1. Generate list with 100 random integers
    Node *head = generate_random_list(LIST_SIZE);

    printf("--- Original Unsorted Linked List ---\n");
    print_list_formatted(head, ITEMS_PER_ROW);

    // 2. Sort list using Bubble Sort
    bubble_sort_list(head);

    printf("\n--- Sorted Linked List (5 per row) ---\n");
    print_list_formatted(head, ITEMS_PER_ROW);

    // 3. Free memory
    free_list(head);

    return 0;
}