# Second Semester Project: Student Attendance

### Introduction

This C program is a student attendance management system, developed as part of my first-year college in 2nd semester assignment. It showcases advanced programming concepts such as binary search trees, dynamic memory allocation, and time functions in C.

### Program Overview

1. **Data Structure**:
   - A `struct st` (renamed to `student` for clarity) is defined to store student details: ID, name, and attendance time.
   - The structure includes pointers to left and right nodes, indicating that it's designed for a binary search tree implementation.

2. **Global Variables and Functions**:
   - `root`: A global pointer of type `student` initialized to `NULL`, acting as the root of the binary search tree.
   - Functions for operations like `insert`, `search`, `show`, and `check`.

3. **Functionality**:
   - `insert()`: Adds a new student record to the binary search tree.
   - `search()`: Searches for a student record by ID.
   - `show()`: In-order traversal of the tree to display student records.
   - `check()`: Compares two strings and returns an integer based on the comparison.

4. **Main Menu**:
   - The main function provides a menu-driven interface for the user to interact with the system.

### Key Functionalities and Analysis

1. **Inserting Records (`insert`)**:
   - Inserts new student records into the binary search tree, maintaining order based on student ID.

2. **Searching for Records (`search`)**:
   - Implements a binary search on the tree structure to find a student record by ID.

3. **Displaying Records (`show`)**:
   - Displays all student records in the binary search tree using in-order traversal, ensuring records are shown in sorted order.

4. **String Comparison (`check`)**:
   - Custom string comparison function used in binary search and insertion operations.

### Improvements

1. **Error Handling**: Implement better error handling for edge cases, such as inserting duplicate records or searching in an empty tree.
2. **Memory Management**: Ensure proper free-ing of memory to avoid memory leaks, especially when dealing with dynamic memory allocation.
3. **User Interface**: Enhance the user interface for better usability, potentially adding more options and clearer instructions.
4. **Data Validation**: Add checks to ensure that user inputs (especially IDs and names) are valid and adhere to expected formats.
5. **Function Naming**: Rename functions more descriptively to clearly indicate their purpose (e.g., `insertStudent`, `searchStudent`).

### Conclusion

This program demonstrates a significant advancement in my programming skills compared to my first-year assignments. It shows my ability to handle complex data structures like binary search trees and implement a more sophisticated program that could potentially be used in real-world applications. With continuous learning and improvement, these skills can be further enhanced to develop more complex and robust applications.
