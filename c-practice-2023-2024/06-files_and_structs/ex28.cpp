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

// Function to write a student record to a file
void writeStudentToFile(const char *filename, const struct Student *student) {
    // Your code here
    // Hint: Use fopen to open the file in append mode ("a")
    // Hint: Use fprintf to write the student record to the file
    // Hint: Use fclose to close the file
    std::ofstream outFile(filename, std::ios_base::app);
    if (!outFile.is_open()) {
        std::cerr << "Error opening the file!\n" << std::endl;
        return;
    }
    else {
        outFile << student->name << "," << student->age << "," << student->gpa << std::endl;
    }
    outFile.close();
}

// Function to read a student record from a file
void readStudentFromFile(const char *filename, struct Student *student) {
    // Your code here
    // Hint: Use fopen to open the file in read mode ("r")
    // Hint: Use fscanf to read the student record from the file
    // Hint: Use fclose to close the file
    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        std::cerr << "Error opening the file!\n" << std::endl;
        return;
    }
    else {
        //read e.g. John Dow 25 3.5 into student->name, student->age, student->gpa
        inFile >> student->name >> student->age >> student->gpa;
    }
    inFile.close();
}

// Test function to demonstrate file operations with structs
void runFileOperationsTest() {
    const char *filename = "students.dat";
    Student myStudent, readStudent;

    // Call the function to initialize the student
    initializeStudent(&myStudent, "John Doe", 20, 3.5);

    // Call the function to write the student record to the file
    writeStudentToFile(filename, &myStudent);

    // Call the function to read the student record from the file
    readStudentFromFile(filename, &readStudent);

    // Test with assert
    std::cout << "Expected name: John Doe" << std::endl;
    std::cout << "Actual name: " << readStudent.name << std::endl;
    assert(std::strcmp(myStudent.name, readStudent.name) == 0);
    assert(myStudent.age == readStudent.age);
    assert(myStudent.gpa == readStudent.gpa);

    // Call the function to print information about the read student
    printStudent(&readStudent);
}

int main() {
    // Call the file operations test
    runFileOperationsTest();
    std::cout << "Success!" << std::endl;
    return 0;
}