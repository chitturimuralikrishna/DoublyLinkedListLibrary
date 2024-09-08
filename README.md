# DLL Doubly Linked List Library

This repository contains a simple and efficient implementation of a doubly linked list (DLL) in C. The library includes initialization, insertion, and deletion operations, all tested with a sample program. The library is built as a shared object that can be linked to any C project.

## Features
- Basic operations: initialization, insertion, and deletion of nodes
- Shared library for use in any C application
- Built with strict security, debugging, and error-checking flags
- Example test file provided for usage demonstration

## How to Build

### Requirements
- GCC
- Make

### Building the Library and Example
1. Clone the repository:
    ```bash
    git clone https://github.com/yourusername/dll-doubly-linked-list-lib.git
    cd dll-doubly-linked-list-lib
    ```

2. Build the shared library and test program:
    ```bash
    make
    ```

3. To clean up the generated files:
    ```bash
    make clean
    ```

## How to Use

1. **Include the Library in Your Project:**

   In your C program, include the header file `dll.h`:
   ```c
   #include "dll.h"

