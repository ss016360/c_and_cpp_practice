#include <iostream>
#include <cassert>

// Function to be completed
int calculateRemainder(const int a, const int b) {
    // Hint: Choose the correct operator to calculate the remainder
    // Options: '+', '-', '%', '*', '/'
    // Your code here

    // Hint: Don't forget to return the calculated remainder
    // Your code here
    return a % b;
}

// Function to perform tests
void runTests() {
    int result1 = calculateRemainder(10, 3);
    assert(result1 == 1);

    int result2 = calculateRemainder(-15, 5);
    assert(result2 == 0);

    int result3 = calculateRemainder(14, 5);
    assert(result3 == 4);

    int result4 = calculateRemainder(-6, -2);
    assert(result4 == 0);

    int result5 = calculateRemainder(9, -4);
    assert(result5 == 1);
}

int main() {
    // Call the test function
    runTests();

    printf("All tests passed successfully!\n");
    std::cout << "All tests passed successfully!\n" << std::endl;

    return 0;
}