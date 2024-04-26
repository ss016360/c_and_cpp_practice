#include <stdio.h>
#include <assert.h>

// Function to be completed
int performBitwiseOR(int operand1, int operand2) {
    // Your code here
    // Use the bitwise OR operator to perform the operation
    printf("answer is, %d\n", (operand1 | operand2));
    return operand1 | operand2;
    // Don't forget to return the result
    // Your code here
}

// Function to perform tests for bitwise OR
void runBitwiseORTests() {
    int result1 = performBitwiseOR(5, 3);
    assert(result1 == 7);

    int result2 = performBitwiseOR(8, 12);
    assert(result2 == 12);

    // Add more test cases if needed
}

int main() {
    // Call the bitwise OR tests
    runBitwiseORTests();
    printf("Bitwise OR tests passed successfully!\n");

    return 0;
}

