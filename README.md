# AVL-Tree-Dendrologist

A C++ implementation of an AVL (self-balancing binary search) tree developed for CSC 3102: Advanced Data Structures & Algorithm Analysis at Louisiana State University.

## Project Overview

Dendrologist is a command-line application that manages a collection of strings using an AVL tree. The program automatically maintains tree balance during insertions and deletions while supporting multiple comparison strategies.

## Features

- **AVL Tree Operations:** Insert and delete strings while maintaining a balanced binary search tree.
- **Custom Ordering:** Support seven comparison modes based on lexicographic order, string length, and tie-breaking rules.
- **In-Order Traversal:** Display stored strings according to the selected ordering.
- **Root-to-Leaf Paths:** Generate and display every path from the root to a leaf node.
- **Tree Statistics:** Calculate the number of nodes, tree height, and number of full nodes.
- **Fibonacci AVL Detection:** Determine whether the tree satisfies specified Fibonacci size, height, and balance-factor conditions.
- **File-Based Commands:** Read and execute operations from an input command file.

## Technologies Used

- C++
- C++11
- Standard Template Library (STL)
- Object-Oriented Programming
- Templates and Recursion

## Compilation

Compile the program using a C++11-compatible compiler:

```bash
g++ -std=c++11 -Wall -Wextra Dendrologist.cpp -o Dendrologist
```

## Usage

```bash
./Dendrologist <order-code> <command-file>
```

The order code selects one of seven supported string comparison strategies, ranging from `-3` to `3`.

The command file supports the following operations:

```text
insert apple
insert banana
insert cherry
stats
traverse
paths
delete banana
stats
```

## Concepts Demonstrated

- Self-balancing binary search trees
- AVL rotations and balance factors
- Recursive tree algorithms
- Function-based comparison strategies
- Template programming
- Breadth-first traversal using queues
- File input and exception handling

## Academic Context

Developed as Programming Project #2 for CSC 3102 at Louisiana State University.

This project demonstrates the implementation and analysis of AVL trees, including dynamic balancing, tree traversal, and structural properties.
