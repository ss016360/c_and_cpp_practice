#include <iostream>
#include <cassert>

// Function to check if two numbers are equal using an if statement
int areEqual(int num1, int num2) {
    // Your code here
    // Write an if statement to check if num1 is equal to num2
    // Hint: Use the equality (==) operator
    if (num1 == num2) {
        return 1;
    }
    else {
        return 0;
    }
}

// Test function to verify the if statement
void runIfStatementTest() {
    // Testing with equal numbers
    int result1 = areEqual(5, 5);
    assert(result1 == 1);  // Adjust the expected result based on your test case

    // Testing with non-equal numbers
    int result2 = areEqual(3, 8);
    assert(result2 == 0);  // Adjust the expected result based on your test case
}

int main() {
    // Call the if statement test
    runIfStatementTest();
    std::cout << "Success!" << std::endl;

    return 0;
}