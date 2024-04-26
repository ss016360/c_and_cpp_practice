#include <iostream>
#include <cassert>

// Function to be completed
bool performLogicalOperation(bool operand1, bool operand2) {
    // Your code here
    // Choose the correct logical operator to perform the operation
    // Options: '&&', '||', '!'
    std::cout << "answer is, " << (operand1 && operand2) << std::endl;
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
    std::cout << "Logical tests passed successfully!" << std::endl;
    return 0;
}