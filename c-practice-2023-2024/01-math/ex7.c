#include <stdio.h>
#include <assert.h>

// Function to be completed
float performDivision(float numerator, float denominator) {
    // Your code here for division
    // Example: float result = numerator / denominator;

    // Don't forget to return the calculated result
    // Your code here
    printf("answer is, %f\n", numerator/denominator);
    return numerator / denominator;
}

// Function to perform tests
void runTests() {
    float numerator = 1.0;
    float denominator = 3.0;

    // Call the function
    float result = performDivision(numerator, denominator);
    assert(result > 0.333 && result < 0.334);

    // Your code here
    // Work out how to use a tolerance for testing the result

}

int main() {
    // Call the test function
    runTests();

    printf("All tests passed successfully!\n");

    return 0;
}

