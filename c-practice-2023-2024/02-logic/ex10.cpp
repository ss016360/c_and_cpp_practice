#include <iostream>
#include <cassert>

// Function to be completed
int performBitwiseAND(int operand1, int operand2) {
    // Your code here
    // Use the bitwise AND operator to perform the operation
    std::cout << "the result is: " << (operand1 & operand2) << std::endl;
    return operand1 & operand2;
    // Don't forget to return the result
    // Your code here
}

// Function to perform tests for bitwise AND
void runBitwiseANDTests() {
    int result1 = performBitwiseAND(5, 3);
    assert(result1 == 1);

    int result2 = performBitwiseAND(8, 12);
    assert(result2 == 8);

    // Add more test cases if needed
}

int main() {
    // Call the bitwise AND tests
    runBitwiseANDTests();
    std::cout << "Bitwise AND tests passed successfully!" << std::endl;

    return 0;
}