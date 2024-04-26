#include <stdio.h>
#include <assert.h>

// Function to be completed
float multiplyFloats(float a, float b) {
    // Hint: Choose the correct operator to multiply 'a' and 'b'
    // Options: '+', '-', '*', '/'
    // Your code here

    // Hint: Don't forget to return the calculated product
    // Your code here
    printf("answer is, %f\n", (a * b));
    return a * b;
}

// Function to perform tests
void runTests() {
    float result1 = multiplyFloats(2.5, 3.0);
    assert(result1 == 7.5);

    float result2 = multiplyFloats(-1.5, 4.0);
    assert(result2 == -6.0);

    float result3 = multiplyFloats(13.8, 5.9);
    assert(result3 > 81.41999 && result3 < 81.42001); // this and the asserts below are not being printed, I am worried that they are not being run

    float  result4 = multiplyFloats(-9.6, -6.0);
    assert(result4 > 57.5999 && result4 < 57.60001);

    float result5 = multiplyFloats(11.2, -3.3);
    assert(result5 > -36.961 && result5 < -36.959);
}

int main() {
    // Call the test function
    runTests();

    printf("All tests passed successfully!\n");

    return 0;
}

