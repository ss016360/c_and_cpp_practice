#include <iostream>
#include <cassert>

// Function to check if a number is positive using an if statement
int isPositive(int number) {
    // Your code here
    // Write an if statement to check if the number is positive
    // Hint: Use the greater than (>) operator
    if (number >=0) {
        return 1;
    }
    else {
        return 0;
    }
}

// Test function to verify the if statement
void runIfStatementTest() {
    // Testing with a positive number
    int result1 = isPositive(5);
    assert(result1 == 1);  // Adjust the expected result based on your test case

    // Testing with a non-positive number
    int result2 = isPositive(-3);
    assert(result2 == 0);  // Adjust the expected result based on your test case
}

int main() {
    // Call the if statement test
    runIfStatementTest();
    std::cout << "Check passed successfully!" << std::endl;
    return 0;
}