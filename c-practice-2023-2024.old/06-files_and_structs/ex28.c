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

// Function to write a student record to a file
void writeStudentToFile(const char *filename, const struct Student *student) {
    // Your code here
    // Hint: Use fopen to open the file in append mode ("a")
    // Hint: Use fprintf to write the student record to the file
    // Hint: Use fclose to close the file
    FILE *fp = fopen(filename, "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    else {
        fprintf(fp, "%s,%d,%lf\n", student->name, student->age, student->gpa);
    }
    fclose(fp);
}

// Function to read a student record from a file
void readStudentFromFile(const char *filename, struct Student *student) {
    // Your code here
    // Hint: Use fopen to open the file in read mode ("r")
    // Hint: Use fscanf to read the student record from the file
    // Hint: Use fclose to close the file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    else {
        //read e.g. John Dow 25 3.5 into student->name, student->age, student->gpa
        fscanf(fp, "%[^,],%d,%lf\n", student->name, &student->age, &student->gpa);
    }
    fclose(fp);
}

// Test function to demonstrate file operations with structs
void runFileOperationsTest() {
    const char *filename = "students.dat";
    struct Student myStudent, readStudent;

    // Call the function to initialize the student
    initializeStudent(&myStudent, "John Doe", 20, 3.5);

    // Call the function to write the student record to the file
    writeStudentToFile(filename, &myStudent);

    // Call the function to read the student record from the file
    readStudentFromFile(filename, &readStudent);

    // Test with assert
    printf("Expected Name: %s\n, Actual", myStudent.name);
    printf("read student : %s\n", readStudent.name);
    assert(strcmp(myStudent.name, readStudent.name) == 0);
    assert(myStudent.age == readStudent.age);
    assert(myStudent.gpa == readStudent.gpa);

    // Call the function to print information about the read student
    printStudent(&readStudent);
}

int main() {
    // Call the file operations test
    runFileOperationsTest();

    return 0;
}

