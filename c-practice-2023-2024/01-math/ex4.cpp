#include <iostream>
#include <cassert>
#include <cmath>
#include <limits>

//You will need an extra include here to define INT_MAX


// Function to be completed
int multiplyIntegers(int a, int b) {
    // Choose the correct operator to multiply 'a' and 'b'
    // Options: '+', '-', '*', '/'
    // Your code here

    // Don't forget to return the calculated product
    // Your code here
    int answer = a * b;
    if (a < (std::numeric_limits<int>::max() / b) && a > (std::numeric_limits<int>::min() / b)) {
        std::cout << "the answer is," << answer << std::endl;
        return a * b;
    }
    else {
        std::cout << "the answer is, 0" << std::endl;
        return 0;
    }
}

// Function to perform tests
void runTests() {
    int result1 = multiplyIntegers(5, 10);
    assert(result1 == 50);

    int result2 = multiplyIntegers(-7, 8);
    assert(result2 == -56);

    // Test with values that may lead to overflow
    int value1 = std::numeric_limits<int>::max() / 2;  // Half of INT_MAX
    int value2 = 3;            // A small value to increase the product
    int result3 = multiplyIntegers(value1, value2);
    assert(result3 == 0);

    int value3 = std::numeric_limits<int>::min() / 2;  // Half of INT_MIN
    int result4 = multiplyIntegers(value3, value2);
    assert(result4 == 0);

    // Hint: When creating a test, consider the potential for overflow without results less than the operands
    // Your code here to create a suitable test case

    // Add more test cases if needed
}

int main() {
    // Call the test function
    runTests();

    std::cout << "All tests passed!" << std::endl;

    return 0;
}