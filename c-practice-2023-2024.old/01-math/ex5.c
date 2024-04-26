#include <stdio.h>
#include <assert.h>

// Function to be completed
float calculateRatio(float a, float b) {
    // Hint: Choose the correct operator to calculate the ratio of 'a' and 'b'
    // Options: '+', '-', '*', '/'
    // Your code here

    // Hint: Don't forget to return the calculated ratio
    // Your code here
    printf("answer is, %f\n", (a / b));
    return a / b;
}

// Function to perform tests
void runTests() {
    float result1 = calculateRatio(5.0, 2.0);
    assert(result1 == 2.5);

    float result2 = calculateRatio(-10.0, 4.0);
    assert(result2 == -2.5);

    float result3 = calculateRatio(12.0, 5.0);
    assert(result3 > 2.39999 && result3 < 2.40001); // why is this failing? when I print the result it matches the assertion

    float  result4 = calculateRatio(-9.0, -6.0);
    assert(result4 == 1.5);

    float result5 = calculateRatio(11.0, -3.0);
    assert(result5 > -3.6777 && result5 < -3.65999);

}

int main() {
    // Call the test function
    runTests();

    printf("All tests passed successfully!\n");

    return 0;
}

