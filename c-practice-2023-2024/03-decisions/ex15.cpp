#include <iostream>
#include <cassert>

// Function to check if a number is positive and not equal to zero using an if statement
int isPositiveAndNotZero(int number) {
    // Your code here
    // Write an if statement to check if the number is positive and not equal to zero
    // Hint: Use the greater than (>) and not equal (!=) operators
    if (number > 0) {
        return 1;
    }
    else {
        return 0;
    }
}

// Test function to verify the if statement
void runIfStatementTest() {
    // Testing with a positive number not equal to zero
    int result1 = isPositiveAndNotZero(5);
    assert(result1 == 1);  // Adjust the expected result based on your test case

    // Testing with zero
    int result2 = isPositiveAndNotZero(0);
    assert(result2 == 0);  // Adjust the expected result based on your test case

    // Testing with a negative number
    int result3 = isPositiveAndNotZero(-3);
    assert(result3 == 0);  // Adjust the expected result based on your test case
}

int main() {
    // Call the if statement test
    runIfStatementTest();
    std::cout << "Success!" << std::endl;

    return 0;
}