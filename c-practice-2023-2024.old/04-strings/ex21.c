#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

// Function to replace a substring with another string of different length
void substituteSubstring(char mainString[], const char substring[], const char replacement[]) {
    // Your code here
    // Hint: Use strstr to find the substring in the mainString
    // Hint: Calculate the lengths of the substring and replacement using strlen
    // Hint: Allocate memory for three temporary strings using malloc
    // Hint: Copy the parts of the mainString to the temporary strings using strncpy
    // Hint: Concatenate the parts with the replacement using strcat
    // Hint: Free the memory allocated for the temporary strings
    //*ptr points to the place within mainString where substring is found
    char *ptr = strstr(mainString, substring);
    //if ptr is not NULL, then substring is found in mainString
    if (ptr != NULL) {
        //the replacement string, with the length of substring, is copied into mainString
        //starting at the location pointed to by ptr which is in mainString
        //Calculate the lengths of the prefix, suffix, and replacement
        size_t prefixLen = ptr - mainString;
        size_t suffixLen = strlen(mainString) - (prefixLen + strlen(substring));

        // Create temporary strings for prefix, replacement, and suffix
        char *prefix = (char *)malloc(prefixLen);
        char *suffix = (char *)malloc(suffixLen);

        // Copy the prefix from the mainString to the temporary string
        strncpy(prefix, mainString, prefixLen);

        // Copy the suffix from the mainString to the temporary string
        strncpy(suffix, ptr + strlen(substring), suffixLen);

        // Concatenate the prefix, replacement, and suffix
        sprintf(mainString, "%s%s%s", prefix, replacement, suffix);

        // Free the memory allocated for temporary strings
        free(prefix);
        free(suffix);
    }
}

// Test function to verify the substring substitution
void runSubstringSubstitutionTest() {
    char mainString[] = "This is a sample sentence.";
    const char substring[] = "sample";
    const char replacement[] = "much longer";

    // Call the function to substitute the substring
    substituteSubstring(mainString, substring, replacement);
    printf("%s\n", mainString);
    // Testing with assert
    assert(strcmp(mainString, "This is a much longer sentence.") == 0);
    // Adjust the expected result based on your test case
}

int main() {
    // Call the substring substitution test
    runSubstringSubstitutionTest();
    printf("Test passed!");
    return 0;
}

