#include <stdio.h>
#include <stdlib.h>

// Structure for Binary Tree Node
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Function to create a new tree node
Node* createNode(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed for tree node.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the Binary Search Tree
Node* insert(Node *root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

// Function to perform inorder traversal and print values to the screen
void printInorder(Node *root) {
    if (root != NULL) {
        printInorder(root->left);
        printf("%d ", root->data);
        printInorder(root->right);
    }
}

// Function to free memory allocated for the tree
void freeTree(Node *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main(void) {
    FILE *inputFile = fopen("data.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input file 'data.txt'.\n");
        return 1;
    }

    int size;
    // Read the first integer which specifies the size of the array
    if (fscanf(inputFile, "%d", &size) != 1 || size <= 0) {
        printf("Error: Invalid or missing size specifier in file.\n");
        fclose(inputFile);
        return 1;
    }

    // Dynamically allocate array for the data
    int *data = (int *)malloc(size * sizeof(int));
    if (data == NULL) {
        printf("Error: Dynamic memory allocation for array failed.\n");
        fclose(inputFile);
        return 1;
    }

    // Read values into data[]
    for (int i = 0; i < size; i++) {
        if (fscanf(inputFile, "%d", &data[i]) != 1) {
            printf("Error: Failed to read integer at index %d.\n", i);
            free(data);
            fclose(inputFile);
            return 1;
        }
    }
    fclose(inputFile);

    // Build the Binary Search Tree from the array
    Node *root = NULL;
    for (int i = 0; i < size; i++) {
        root = insert(root, data[i]);
    }

    // Walk the tree inorder and print values to screen
    printf("Inorder Traversal of Binary Tree:\n");
    printInorder(root);
    printf("\n");

    // Free dynamically allocated memory
    free(data);
    freeTree(root);

    return 0;
}