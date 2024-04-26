#include <stdio.h>
#include <string.h>
#include <assert.h>

// Function to find a substring in a string
int findSubstring(const char mainString[], const char substring[]) {
    // Your code here
    // Hint: Use the strstr function to find the substring in the mainString
    // Hint: If the substring is found, strstr returns a pointer to the first occurrence of the substring in the mainString
    if (strstr(mainString, substring)) {
        return 1;
    }
    else {
        return 0;
    }
}

// Test function to verify the substring search
void runSubstringSearchTest() {
    const char mainString[] = "This is a sample sentence.";
    const char substring1[] = "sample";
    const char substring2[] = "notfound";

    // Call the function to find the first substring
    int result1 = findSubstring(mainString, substring1);
    assert(result1 == 1);  // Adjust the expected result based on your test case

    // Call the function to find the second substring
    int result2 = findSubstring(mainString, substring2);
    assert(result2 == 0);  // Adjust the expected result based on your test case
}

int main() {
    // Call the substring search test
    runSubstringSearchTest();
    printf("Test passed!");
    return 0;
}

