#include <stdio.h>
#include <assert.h>

// Function to check if a number is even using if statements and modulus arithmetic
int isEven(int number) {
    // Your code here
    // Write an if statement to check if the number is even using modulus arithmetic
    // Hint: Use the modulus operator (%) to check for divisibility by 2
    if (number % 2 == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

// Test function to verify the if statement
void runIfStatementTest() {
    // Testing with an even number
    int result1 = isEven(4);
    assert(result1 == 1);  // Adjust the expected result based on your test case

    // Testing with an odd number
    int result2 = isEven(7);
    assert(result2 == 0);  // Adjust the expected result based on your test case
}

int main() {
    // Call the if statement test
    runIfStatementTest();
    printf("Success!\n");
    return 0;
}

