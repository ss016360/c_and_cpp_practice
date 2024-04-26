#include <iostream>
#include <cassert>
#include <cmath>

// Function to be completed
float performDivision(float numerator, float denominator) {
    // Your code here for division
    // Example: float result = numerator / denominator;

    // Don't forget to return the calculated result
    // Your code here
    std::cout << "the answer is: " << numerator / denominator << std::endl;
    return numerator / denominator;
}

// Function to perform tests
void runTests() {
    float numerator = 1.0f;
    float denominator = 3.0f;
    float tolerance = 0.0001f; // define a tolerance for floating point comparison

    // Call the function
    float result = performDivision(numerator, denominator);
    assert(std::abs(result - (numerator/denominator)) < tolerance);

    // Your code here
    // Work out how to use a tolerance for testing the result

}

int main() {
    // Call the test function
    runTests();

   std::cout << "All tests passed successfully!" << std::endl;

    return 0;
}