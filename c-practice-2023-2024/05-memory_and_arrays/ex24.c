#include <stdio.h>
#include <assert.h>

// Function to define an array of integers
void defineIntArray(int array[], int size) {
    // Your code here
    // Hint: Use a loop to set values in the array
    for (int i = 0; i < size; ++i) {
        array[i] = i + 1;
    }
}

// Function to find the sum of elements in an array
int sumArrayElements(const int array[], int size) {
    // Your code here
    // Hint: Use a loop to iterate through the array and calculate the sum
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += array[i];
    }
    return sum;
}

// Function to find the maximum element in an array
int findMaxArrayElement(const int array[], int size) {
    // Your code here
    // Hint: Use a loop to iterate through the array and find the maximum element
    int max = array[0];
    for (int i = 0; i < size; ++i) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

// Test function to demonstrate array manipulations
void runArrayManipulationTest() {
    int size = 5;
    int array[size];

    // Call the function to define the array
    defineIntArray(array, size);

    // Test with assert
    for (int i = 0; i < size; ++i) {
        assert(array[i] == i + 1);  // Adjust the expected values based on your implementation
    }

    // Call the function to find the sum of elements in the array
    int sumResult = sumArrayElements(array, size);

    // Test with assert
    assert(sumResult == (1 + 2 + 3 + 4 + 5));

    // Call the function to find the maximum element in the array
    int maxResult = findMaxArrayElement(array, size);

    // Test with assert
    assert(maxResult == 5);  // Adjust the expected value based on your implementation
}

int main() {
    // Call the array manipulation test
    runArrayManipulationTest();
    printf("Test passed!");
    return 0;
}

