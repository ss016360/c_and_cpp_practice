#include <stdio.h>
#include <string.h>
#include <assert.h>

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
    printf("Expected String: Hello, John\n");
    printf("Concatenated String: {%s}\n", result);
    const char expected[]="Hello, John\0";
    printf("comparison gives %d\n", strcmp(expected, result));
    assert(strcmp(result, "Hello, John\0") == 0);
}

int main() {
    // Test the string concatenation function
    char result[20];  // Adjust the size based on your needs
    const char greeting[] = "Hello, ";
    const char name[] = "John\0";

    // Call the function to concatenate strings
    concatenateStrings(result, greeting);
    concatenateStrings(result, name);

    // Print the result
    runStringConcatenationTest();
    printf("Test passed!");
    return 0;
}

