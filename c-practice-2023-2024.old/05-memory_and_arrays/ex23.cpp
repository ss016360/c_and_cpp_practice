#include <iostream>
#include <cassert>
#include <cstdlib>

// Function to allocate memory for an array using malloc
int *allocateMemoryWithMalloc(int size) {
    // Your code here
    // Hint: Use malloc to allocate memory for an array of integers
    // and return the pointer to the allocated memory
    int *ptr = new int[size];
    return ptr;
}

// Function to allocate memory for an array using calloc
int *allocateMemoryWithCalloc(int size) {
    // Your code here
    // Hint: Use calloc to allocate memory for an array of integers
    // and return the pointer to the allocated memory
    int *ptr = new int[size]();
    return ptr;
}

// Function to print the elements of an array
void printArray(const int *array, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

// Test function to demonstrate memory allocation
void runMemoryAllocationTest() {
    int size = 5;

    // Call the function to allocate memory with malloc
    int *arrayMalloc = allocateMemoryWithMalloc(size);
    std::cout << "Array allocated with Malloc: " << std::endl;
    printArray(arrayMalloc, size);

    // Test with assert
    for (int i = 0; i < size; ++i) {
        assert(arrayMalloc[i] == 0);  // Verify that elements are initialized to 0
    }

    // Call the function to allocate memory with calloc
    int *arrayCalloc = allocateMemoryWithCalloc(size);
    std::cout << "Array allocated with Calloc: " << std::endl;
    printArray(arrayCalloc, size);

    // Test with assert
    for (int i = 0; i < size; ++i) {
        assert(arrayCalloc[i] == 0);  // Verify that elements are initialized to 0
    }

    // Free the allocated memory
    delete[] arrayMalloc;
    delete[] arrayCalloc;
}

int main() {
    // Call the memory allocation test
    runMemoryAllocationTest();

    return 0;
}