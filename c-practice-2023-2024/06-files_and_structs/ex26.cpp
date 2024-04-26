#include <iostream>
#include <fstream>
#include <cassert>
#include <cstring>

// Function to write data to a file
void writeToFile(const char *filename, const char *data) {
    // Your code here
    // Hint: Use fopen to open the file in write mode ("w")
    // Hint: Use fprintf to write data to the file
    // Hint: Use fclose to close the file
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Error opening the file!" << std::endl;
    }
    else {
        outFile << data;
    }
    outFile.close();
}

// Function to read data from a file
void readFromFile(const char *filename, char *buffer, int bufferSize) {
    // Your code here
    // Hint: Use fopen to open the file in read mode ("r")
    // Hint: Use fgets to read data from the file into the buffer
    // Hint: Use fclose to close the file
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        std::cerr << "Error opening the file!" << std::endl;
    }
    else {
        inFile.getline(buffer, bufferSize);
    }
    inFile.close();
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
    assert(std::strcmp(buffer, dataToWrite) == 0);
}

int main() {
    // Call the file access test
    runFileAccessTest();
    std::cout << "Passed!" << std::endl;
    return 0;
}