#include <iostream>
#include <cassert>

// Function to be completed
float multiplyFloats(float a, float b) {
    // Hint: Choose the correct operator to multiply 'a' and 'b'
    // Options: '+', '-', '*', '/'
    // Your code here

    // Hint: Don't forget to return the calculated product
    // Your code here
    std::cout<< "the answer is: " << a * b << std::endl;
    return a * b;
}

// Function to perform tests
void runTests() {
    float result1 = multiplyFloats(2.5f, 3.0f);
    assert(result1 == 7.5f);

    float result2 = multiplyFloats(-1.5f, 4.0f);
    assert(result2 == -6.0f);

    float result3 = multiplyFloats(13.8f, 5.9f);
    assert(result3 > 81.41999f && result3 < 81.42001f); // this and the asserts below are not being printed, I am worried that they are not being run

    float  result4 = multiplyFloats(-9.6f, -6.0f);
    assert(result4 > 57.5999f && result4 < 57.60001f);

    float result5 = multiplyFloats(11.2f, -3.3f);
    assert(result5 > -36.961f && result5 < -36.959f);
}

int main() {
    // Call the test function
    runTests();

    std::cout << "All tests passed successfully!" << std::endl;

    return 0;
}