#include <iostream>
#include <cstring>
#include <cassert>

// Function to concatenate two strings
void concatenateStrings(char destination[], const char source[]) {
    // Your code here
    // Use the strcat function or a loop to concatenate the source string to the destination string
    strcat(destination, source);
}

void runStringConcatenationTest() {
    // Test the string concatenation function
    char result[20];  // Adjust the size based on your needs
    const char greeting[] = "Hello, ";
    const char name[] = "John\0";

    // Call the function to concatenate strings
    concatenateStrings(result, greeting);
    concatenateStrings(result, name);

    // Print the result
    assert(strcmp(result, "Hello, John\0") == 0);
}

int main() {

    // Print the result
    runStringConcatenationTest();
    std::cout << "Test passed!" << std::endl;
    return 0;
}