# Tree Implementation Project

## Overview

This project offers a versatile k-ary tree data structure capable of handling diverse data types such as integers, strings, and user-defined classes (e.g., complex numbers). It's designed to facilitate a wide range of operations, including several traversal strategies.

## Class Hierarchy

- **Node<T>**: A generic node capable of storing values and managing a list of child nodes.
- **Tree<T, K=2>**: A generic tree structure that supports multiple traversal methods and can be configured as a k-ary tree.

## Key Features

### Node Operations
- **Constructor**: Initializes a node with a given value.
- **getValue()**: Retrieves the node's value.
- **setValue()**: Sets the node's value.
- **addChild()**: Adds a child to the node.
- **getChildren()**: Returns a list of child nodes.
- **Destructor**: Recursively deletes the node and its children to prevent memory leaks.

### Tree Operations
- **Constructor**: Establishes an empty tree.
- **addRoot()**: Sets the root of the tree.
- **addSubNode()**: Attaches a new node under a specified parent node.
- **find()**: Searches for a node with a specified value starting from a given node.
- **begin/end_pre_order()**: Iterator for Pre-Order traversal.
- **begin/end_post_order()**: Iterator for Post-Order traversal.
- **begin/end_in_order()**: Iterator for In-Order traversal (binary trees only).
- **begin/end_bfs_scan()**: Iterator for Breadth-First Search traversal.
- **begin/end_dfs_scan()**: Iterator for Depth-First Search traversal.
- **myHeap()**: Converts the binary tree to a minimum heap and provides an iterator.
- **Destructor**: Safely deletes all nodes in the tree.

## Additional Components

- **Complex**: A class to handle complex numbers, demonstrating the tree's ability to manage custom objects.

## GUI Representation

The project includes a GUI representation for the tree, using the SFML library to visualize the tree structure dynamically. This is particularly useful for educational purposes and in-depth analysis of tree behaviors.

## Dependencies

- **C++ Standard Library**
- **SFML**: Used for GUI representation of the tree.

## Building and Running

To build and run the main application and tests run:
```bash
make all
./tree
./test
```

### Author
Gidi Rabi - gidirabi111@gmail.com