#include <iostream>
#include <cassert>

// Function using a while loop to count from 1 to n and return the final count
int countWithWhileLoop(int n) {
    // Your code here
    // Use a while loop to count from 1 to n
    // Hint: Initialize a count variable, use a while loop, and return the count
    int count = 1;
    while (count < n) {
        count++;
    }
    return count;  // Placeholder, remove this line when implementing
}

// Function using a for loop to count from 1 to n and return the final count
int countWithForLoop(int n) {
    // Your code here
    // Use a for loop to count from 1 to n
    // Hint: Initialize a count variable, use a for loop, and return the count
    int count = 1;
    for (int i = 1; i < n; i++) {
        count++;
    }
    std::cout << "count is: " << count << std::endl;
    return count;  // Placeholder, remove this line when implementing
}

// Test function to verify the loop functions
void runLoopTests() {
    // Testing counting from 1 to 5 using a while loop
    int result1 = countWithWhileLoop(5);
    assert(result1 == 5);  // Adjust the expected result based on your test case

    // Testing counting from 1 to 5 using a for loop
    int result2 = countWithForLoop(5);
    assert(result2 == 5);  // Adjust the expected result based on your test case
}

int main() {
    // Call the loop tests
    runLoopTests();

    std::cout << "Success!" << std::endl;
    return 0;
}