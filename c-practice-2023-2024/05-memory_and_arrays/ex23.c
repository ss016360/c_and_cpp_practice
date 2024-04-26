#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Function to allocate memory for an array using malloc
int *allocateMemoryWithMalloc(int size) {
    // Your code here
    // Hint: Use malloc to allocate memory for an array of integers
    // and return the pointer to the allocated memory
    int *ptr = (int *)malloc(size * sizeof(int));
    return ptr;
}

// Function to allocate memory for an array using calloc
int *allocateMemoryWithCalloc(int size) {
    // Your code here
    // Hint: Use calloc to allocate memory for an array of integers
    // and return the pointer to the allocated memory
    int *ptr = (int *)calloc(size, sizeof(int));
    return ptr;
}

// Function to print the elements of an array
void printArray(const int *array, int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Test function to demonstrate memory allocation
void runMemoryAllocationTest() {
    int size = 5;

    // Call the function to allocate memory with malloc
    int *arrayMalloc = allocateMemoryWithMalloc(size);
    printf("Array allocated with malloc: ");
    printArray(arrayMalloc, size);

    // Test with assert
    for (int i = 0; i < size; ++i) {
        assert(arrayMalloc[i] == 0);  // Verify that elements are initialized to 0
    }

    // Call the function to allocate memory with calloc
    int *arrayCalloc = allocateMemoryWithCalloc(size);
    printf("Array allocated with calloc: ");
    printArray(arrayCalloc, size);

    // Test with assert
    for (int i = 0; i < size; ++i) {
        assert(arrayCalloc[i] == 0);  // Verify that elements are initialized to 0
    }

    // Free the allocated memory
    free(arrayMalloc);
    free(arrayCalloc);
}

int main() {
    // Call the memory allocation test
    runMemoryAllocationTest();

    return 0;
}

