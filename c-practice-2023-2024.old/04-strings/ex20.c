#include <stdio.h>
#include <string.h>
#include <assert.h>

// Function to replace a substring with another string of the same length
void replaceSubstring(char mainString[], const char substring[], const char replacement[]) {
    // Your code here
    // Hint: Use the strstr function to find the substring in the mainString
    // Hint: If the substring is found, strstr returns a pointer to the first occurrence of the substring in the mainString
    // Hint: Use the strncpy function to copy the replacement string into the mainString

    //*ptr points to the place within mainString where substring is found
    char *ptr = strstr(mainString, substring);
    //if ptr is not NULL, then substring is found in mainString
    if (ptr != NULL) {
        //the replacement string, with the length of substring, is copied into mainString
        //starting at the location pointed to by ptr which is in mainString
        strncpy(ptr, replacement, strlen(substring));
    }
    printf("%s\n", mainString);
}

// Test function to verify the substring replacement
void runSubstringReplacementTest() {
    char mainString[] = "This is a sample sentence.";
    const char substring[]   = "a sample";
    const char replacement[] = "a purple";

    // Call the function to replace the substring, given the replacement string is same length as substring
    replaceSubstring(mainString, substring, replacement);

    // Testing with assert
    assert(strcmp(mainString, "This is a purple sentence.") == 0);
    // Adjust the expected result based on your test case
}

int main() {
    // Call the substring replacement test
    runSubstringReplacementTest();
    printf("Test passed!");
    return 0;
}

