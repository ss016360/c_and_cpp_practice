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

// Function to write a student record to a specific position in the file
void writeStudentToPosition(const char *filename, int position, const struct Student *student) {
    // Your code here
    // Hint: Use fopen to open the file in read and write mode ("r+")
    // Hint: Use fseek to move to the desired position
    // Hint: Use fwrite to write the student record to the file
    // Hint: Use fclose to close the file
    FILE *fp = fopen(filename, "r+");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    else {
        fseek(fp, position * sizeof(struct Student), SEEK_SET);
        fwrite(student, sizeof(struct Student), 1, fp);
    }
    fclose(fp);
}

// Function to read a student record from a specific position in the file
void readStudentFromPosition(const char *filename, int position, struct Student *student) {
    // Your code here
    // Hint: Use fopen to open the file in read mode ("r")
    // Hint: Use fseek to move to the desired position
    // Hint: Use fread to read the student record from the file
    // Hint: Use fclose to close the file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    else {
        fseek(fp, position * sizeof(struct Student), SEEK_SET);
        fread(student, sizeof(struct Student), 1, fp);
    }
    fclose(fp);
}

// Test function to demonstrate arbitrary record operations
void runArbitraryRecordOperationsTest() {
    const char *filename = "students.dat";
    struct Student myStudent, readStudent;

    // Call the function to initialize the student
    initializeStudent(&myStudent, "Jane Smith", 22, 3.8);

    // Call the function to write the student record to a specific position in the file
    writeStudentToPosition(filename, 1, &myStudent);

    // Call the function to read the student record from a specific position in the file
    readStudentFromPosition(filename, 1, &readStudent);

    // Test with assert
    assert(strcmp(myStudent.name, readStudent.name) == 0);
    assert(myStudent.age == readStudent.age);
    assert(myStudent.gpa == readStudent.gpa);

    // Call the function to print information about the read student
    printStudent(&readStudent);
}

int main() {
    // Call the arbitrary record operations test
    runArbitraryRecordOperationsTest();
    printf("Test passed!");
    return 0;
}

