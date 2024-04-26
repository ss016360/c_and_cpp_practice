#include <stdio.h>
#include <assert.h>

// Function to be completed
int calculateSum(int a, int b) {
    // Hint: Choose the correct operator to calculate the sum
    // Options: '+', '-', '*', '/'
    // Your code here
    return a + b;

    // Hint: Don't forget to return the calculated sum
    // Your code here
}

// Function to perform tests
void runTests() {
    int result1 = calculateSum(5, 3);
    assert(result1 == 8);

    int result2 = calculateSum(-2, 8);
    assert(result2 == 6);

    int result3 = calculateSum(0, 0);
    assert(result3 == 0);

    int result4 = calculateSum(-3, -5);
    assert(result4 == -8);

}

int main() {
    // Call the test function
    runTests();

    printf("All tests passed successfully!\n");

    return 0;
}

