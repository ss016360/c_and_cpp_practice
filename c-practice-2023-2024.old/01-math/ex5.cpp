#include <iostream>
#include <cassert>

// Function to be completed
float calculateRatio(float a, float b) {
    // Hint: Choose the correct operator to calculate the ratio of 'a' and 'b'
    // Options: '+', '-', '*', '/'
    // Your code here

    // Hint: Don't forget to return the calculated ratio
    // Your code here
    std::cout << "the answer is: " << a / b << std::endl;
    return a / b;
}

// Function to perform tests
void runTests() {
    float result1 = calculateRatio(5.0f, 2.0f);
    assert(result1 == 2.5f);

    float result2 = calculateRatio(-10.0f, 4.0f);
    assert(result2 == -2.5f);

    float result3 = calculateRatio(12.0f, 5.0f);
    assert(result3 > 2.39999f && result3 < 2.40001f); // why is this failing? when I print the result it matches the assertion

    float  result4 = calculateRatio(-9.0f, -6.0f);
    assert(result4 == 1.5f);

    float result5 = calculateRatio(11.0f, -3.0f);
    assert(result5 > -3.6777f && result5 < -3.65999f);

}

int main() {
    // Call the test function
    runTests();

    std::cout << "All tests passed successfully!" << std::endl;

    return 0;
}