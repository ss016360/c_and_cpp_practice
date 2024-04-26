#include <stdio.h>
#include <assert.h>

// Function to demonstrate casting between different data types
void demonstrateCasting() {
    // Example 1: Casting from int to double
    int intValue = 42;
    double doubleValue = (double)intValue;

    // Test with assert
    assert(doubleValue == 42.0);

    // Example 2: Casting from double to int
    double floatValue = 3.14;
    int intResult = (int)floatValue;

    // Test with assert
    assert(intResult == 3);

    // Example 3: Casting from char to int
    char charValue = 'A';
    int intChar = (int)charValue;

    // Test with assert
    assert(intChar == 65);

    // Example 4: Casting from int to char
    int intCharResult = (char)intChar;

    // Test with assert
    assert(intCharResult == 'A');
}

// Test function to demonstrate casting
void runCastingTest() {
    // Call the function to demonstrate casting
    demonstrateCasting();
}

int main() {
    // Call the casting test
    runCastingTest();

    return 0;
}

