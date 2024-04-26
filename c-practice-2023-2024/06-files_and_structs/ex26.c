#include <stdio.h>
#include <assert.h>
#include <string.h>

// Function to write data to a file
void writeToFile(const char *filename, const char *data) {
    // Your code here
    // Hint: Use fopen to open the file in write mode ("w")
    // Hint: Use fprintf to write data to the file
    // Hint: Use fclose to close the file
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file!\n");
    }
    else {
        fprintf(file, "%s", data);
    }
    fclose(file);
}

// Function to read data from a file
void readFromFile(const char *filename, char *buffer, int bufferSize) {
    // Your code here
    // Hint: Use fopen to open the file in read mode ("r")
    // Hint: Use fgets to read data from the file into the buffer
    // Hint: Use fclose to close the file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
    }
    else {
        fgets(buffer, bufferSize, file);
    }
    fclose(file);
}

// Test function to demonstrate file access
void runFileAccessTest() {
    const char *filename = "example.txt";
    const char *dataToWrite = "Hello, this is a test!";
    char buffer[100];

    // Call the function to write data to the file
    writeToFile(filename, dataToWrite);

    // Call the function to read data from the file
    readFromFile(filename, buffer, sizeof(buffer));

    // Test with assert
    assert(strcmp(buffer, dataToWrite) == 0);
}

int main() {
    // Call the file access test
    runFileAccessTest();
    printf("Test passed!\n");
    return 0;
}

