#include <iostream>
#include <cassert>
#include <cstring>

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

// Test function to demonstrate struct operations
void runStructLesson() {
    // Create a student
    Student myStudent;

    // Call the function to initialize the student
    initializeStudent(&myStudent, "John Doe", 20, 3.5);

    // Test with assert
    assert(std::strcmp(myStudent.name, "John Doe") == 0);
    assert(myStudent.age == 20);
    assert(myStudent.gpa == 3.5);

    // Call the function to print information about the student
    printStudent(&myStudent);
}

int main() {
    // Call the struct lesson test
    runStructLesson();
    std::cout << "Success!\n" << std::endl;
    return 0;
}
