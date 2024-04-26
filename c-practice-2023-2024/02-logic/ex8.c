#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

// Function to be completed
bool performLogicalOperation(bool operand1, bool operand2) {
    // Your code here
    // Choose the correct logical operator to perform the operation
    // Options: '&&', '||', '!'
    printf("answer is, %d\n", (operand1 && operand2));
    return operand1 && operand2;

    // Don't forget to return the result
    // Your code here
}

// Function to perform tests for logical operators
void runLogicalTests() {
    bool trueValue = true;
    bool falseValue = false;

    // Call the function with different test cases
    bool result1 = performLogicalOperation(trueValue, trueValue);
    assert(result1 == true);

    bool result2 = performLogicalOperation(trueValue, falseValue);
    assert(result2 == false);

    // Add more test cases if needed - will add later
}

int main() {
    // Call the logical tests
    runLogicalTests();
    printf("Logical tests passed successfully!\n");

    return 0;
}

