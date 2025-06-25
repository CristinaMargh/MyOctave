# Project2-PCLP1


This project implements a matrix management system in C, with functionalities for creating, modifying, and performing operations on a dynamic list of matrices.

##  Key Functionalities

### Memory Management
- **Dynamic matrix allocation**: Memory is allocated per row, and if an error occurs, it is safely deallocated to avoid memory leaks.
- **Reading a matrix**: Elements are read individually into a dynamically allocated matrix.
- **Freeing memory**: All matrix rows are traversed and individually freed.

##  Operations Overview

### Main Function Logic
- Uses a character variable to interpret the desired operation.
- Declares a dynamic array `collection` to store multiple matrices.
- For command `L` (load), a matrix is read and appended to `collection` using `malloc` and `realloc`.

### Print & Size
- Retrieves and prints the dimensions or contents of a selected matrix using stored `m` (rows) and `n` (columns) values.

### Resize
- Uses vectors of selected row and column indices to create a new resized matrix.
- The new matrix replaces the original one in memory.

### Sort
- Computes the **sum** of each matrix and stores it in a vector.
- Sorts the matrices in ascending order of these sums using **bubble sort**.
- Swaps matrices and their associated metadata to maintain consistency.

### Multiply
- Implements classic matrix multiplication logic (dot product of rows and columns).
- Appends the resulting product matrix to `collection`.

### Transpose
- Swaps row and column indices and replaces the original matrix with its transpose.
- Updates metadata accordingly.

### Exponentiation
- Uses **logarithmic exponentiation**:
  - If the power is 1 → returns the same matrix.
  - If even → calculates square and recursively raises to half the power.
  - If odd → multiplies the result of the even case with the original matrix.
- Result is stored in a new matrix and added to `collection`.

### Delete Matrix
- For command `F`, a matrix is deleted from `collection`.
- Gaps are removed by shifting all following elements left by one position.

### Exit
- Fully deallocates all memory and gracefully exits the program.

> This project demonstrates efficient memory management, matrix operations, and modular programming techniques in C.
