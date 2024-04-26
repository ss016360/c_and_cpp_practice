#include <stdio.h>
#include <assert.h>

// Function to define a two-dimensional array
void define2DArray(int array[][3], int rows, int cols) {
    // Your code here
    // Hint: Use nested loops to set values in the 2D array
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; j++) {
            array[i][j] = i * cols + j + 1;
        }
    }
}

// Function to find the sum of elements in a two-dimensional array
int sum2DArrayElements(const int array[][3], int rows, int cols) {
    // Your code here
    // Hint: Use nested loops to iterate through the 2D array and calculate the sum
    int sum = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j =0; j < cols; ++j) {
            sum += array[i][j];
        }
    }
    return sum;
}

// Function to find the maximum element in a two-dimensional array
int findMax2DArrayElement(const int array[][3], int rows, int cols) { 
    // Your code here
    // Hint: Use nested loops to iterate through the 2D array and find the maximum element
    int max = array[0][0];
    for (int i = 0; i < rows; ++i) {
        for (int j =0; j < cols; ++j) {
            if (array[i][j] > max) {
                max = array[i][j];
            }
        }
    }
    return max;
}

// Test function to demonstrate 2D array manipulations
void run2DArrayManipulationTest() {
    int rows = 3;
    int cols = 3;
    int array[3][3];

    // Call the function to define the 2D array
    define2DArray(array, rows, cols);

    // Test with assert
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            assert(array[i][j] == i * cols + j + 1);  // Adjust the expected values based on your implementation
        }
    }

    // Call the function to find the sum of elements in the 2D array
    int sumResult = sum2DArrayElements(array, rows, cols);

    // Test with assert
    assert(sumResult == (1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9));

    // Call the function to find the maximum element in the 2D array
    int maxResult = findMax2DArrayElement(array, rows, cols);

    // Test with assert
    assert(maxResult == 9);  // Adjust the expected value based on your implementation
}

int main() {
    // Call the 2D array manipulation test
    run2DArrayManipulationTest();
    printf("Test passed!");
    return 0;
}

