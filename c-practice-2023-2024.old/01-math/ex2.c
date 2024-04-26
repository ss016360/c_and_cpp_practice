#include <stdio.h>
#include <assert.h>

// Function to be completed
int calculateQuotient(int a, int b) {
    // Hint: Choose the correct operator to calculate the quotient (integer division)
    // Options: '+', '-', '%', '*', '/'
    // Your code here

    // Hint: Don't forget to return the calculated quotient
    // Your code here
    int result = a / b;
    return result;
}

// Function to perform tests
void runTests() {
    int result1 = calculateQuotient(10, 3);
    assert(result1 == 3);

    int result2 = calculateQuotient(-15, 5);
    assert(result2 == -3);

    int result3 = calculateQuotient(0, 5);
    assert(result3 == 0);

    int result4 = calculateQuotient(-6, -2);
    assert(result4 == 3);

    int result5 = calculateQuotient(9, -4);
    assert(result5 == -2);
}

int main() {
    // Call the test function
    runTests();

    printf("All tests passed successfully!\n");

    return 0;
}

