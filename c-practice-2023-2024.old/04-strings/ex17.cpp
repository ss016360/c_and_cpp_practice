#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;

// Function to assign a value to a string
void assignStringValue(char myString[]) {
    // Your code here
    // Hint: Use the strcpy function to assign a value to the string
    // mystring <- "Hello, World!"
    //strcpy -> str cpy -> string copy
    strcpy(myString, "Hello, World!");
}

// Test function to verify the string assignment
void runStringAssignmentTest() {
    char result[20];  // Adjust the size based on your needs

    // Call the function to assign a value to the string
    assignStringValue(result);

    // Testing with assert
    assert(strcmp(result, "Hello, World!") == 0);
    // Adjust the expected string based on your test case
}

int main() {
    // Call the string assignment test
    runStringAssignmentTest();
    cout << "Test passed!" << endl;

    return 0;
}