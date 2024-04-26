#include <iostream>
#include <cassert>
#include <cstring>
#include <fstream>

// Define a simple struct
struct Student {
    char name[50];
    int age;
    double gpa;
};

// Function to initialize a student
void initializeStudent(struct Student *student, const char *name, int age, double gpa) {
    // Your code here
    // Hint: Use strcpy to copy the name into the struct
    // Hint: Assign values to age and gpa
    std::strcpy(student->name, name);
    student->age = age;
    student->gpa = gpa;
}

// Function to print information about a student
void printStudent(const struct Student *student) {
    // Your code here
    // Hint: Use printf to print the information about the student
    std::cout << "Name: " << student->name << "\nAge: " << student->age << "\nGPA: " << student->gpa << std::endl;
}

// Function to write a student record to a specific position in the file
void writeStudentToPosition(const char *filename, int position, const struct Student *student) {
    // Your code here
    // Hint: Use fopen to open the file in read and write mode ("r+")
    // Hint: Use fseek to move to the desired position
    // Hint: Use fwrite to write the student record to the file
    // Hint: Use fclose to close the file
    std::ofstream outFile(filename, std::ios_base::app);
    if (!outFile.is_open()) {
        std::cerr << "Error opening the file!\n" << std::endl;
        return;
    }
    else {
        outFile.seekp(position * sizeof(Student));
        outFile.write(reinterpret_cast<const char *>(student), sizeof(student));
    }
    outFile.close();
}

// Function to read a student record from a specific position in the file
void readStudentFromPosition(const char *filename, int position, struct Student *student) {
    // Your code here
    // Hint: Use fopen to open the file in read mode ("r")
    // Hint: Use fseek to move to the desired position
    // Hint: Use fread to read the student record from the file
    // Hint: Use fclose to close the file
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        std::cerr << "Error opening the file!\n" << std::endl;
        return;
    }
    else {
        inFile.seekg(position * sizeof(Student));
        inFile.read(reinterpret_cast<char *>(student), sizeof(student));
    }
    inFile.close();
}

// Test function to demonstrate arbitrary record operations
void runArbitraryRecordOperationsTest() {
    const char *filename = "students.dat";
    Student myStudent, readStudent;

    // Call the function to initialize the student
    initializeStudent(&myStudent, "Jane Smith", 22, 3.8);

    // Call the function to write the student record to a specific position in the file
    writeStudentToPosition(filename, 1, &myStudent);

    // Call the function to read the student record from a specific position in the file
    readStudentFromPosition(filename, 1, &readStudent);

    // Test with assert
    assert(std::strcmp(myStudent.name, readStudent.name) == 0);
    assert(myStudent.age == readStudent.age);
    assert(myStudent.gpa == readStudent.gpa);

    // Call the function to print information about the read student
    printStudent(&readStudent);
}

int main() {
    // Call the arbitrary record operations test
    runArbitraryRecordOperationsTest();
    std::cout << "Test passed!\n" << std::endl;
    return 0;
}