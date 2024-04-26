#include <stdio.h>
#include <string.h>
#include <assert.h>

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
    strcpy(student->name, name);
    student->age = age;
    student->gpa = gpa;
}

// Function to print information about a student
void printStudent(const struct Student *student) {
    // Your code here
    // Hint: Use printf to print the information about the student
    printf("Name: %s\n Age: %d\n GPA: %f\n", student->name, student->age, student->gpa);
}

// Test function to demonstrate struct operations
void runStructLesson() {
    // Create a student
    struct Student myStudent;

    // Call the function to initialize the student
    initializeStudent(&myStudent, "John Doe", 20, 3.5);

    // Test with assert
    assert(strcmp(myStudent.name, "John Doe") == 0);
    assert(myStudent.age == 20);
    assert(myStudent.gpa == 3.5);

    // Call the function to print information about the student
    printStudent(&myStudent);
}

int main() {
    // Call the struct lesson test
    runStructLesson();
    printf("Test passed!\n");
    return 0;
}

