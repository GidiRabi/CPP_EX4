# Tree Implementation

This project implements a generic tree class in C++ that can handle keys of any type (e.g., numbers, strings, and classes). The tree supports various traversal methods, including Pre-Order, Post-Order, In-Order, BFS, and DFS.

## Class Hierarchy

- `Node<T>`: Represents a node in the tree.
- `Tree<T>`: Represents the tree structure and provides methods for adding nodes and traversing the tree.

## Methods

### Node Class
- `Node(T val)`: Constructor to initialize a node with a value.
- `T get_value() const`: Returns the value of the node.
- `void set_value(T val)`: Sets the value of the node.
- `std::vector<Node<T>*> get_children() const`: Returns the children of the node.
- `void add_child(Node<T>* child)`: Adds a child to the node.
- `~Node()`: Destructor to delete all child nodes.

### Tree Class
- `Tree()`: Constructor to initialize the tree.
- `void add_root(T value)`: Adds the root node to the tree.
- `void add_sub_node(T parent_value, T child_value)`: Adds a child node to a parent node.
- `Node<T>* find(Node<T>* node, T value)`: Finds a node with the given value.
- `std::vector<Node<T>*> begin_pre_order() const`: Returns nodes in Pre-Order traversal.
- `std::vector<Node<T>*> begin_post_order() const`: Returns nodes in Post-Order traversal.
- `std::vector<Node<T>*> begin_in_order() const`: Returns nodes in In-Order traversal.
- `std::vector<Node<T>*> begin_bfs_scan() const`: Returns nodes in BFS traversal.
- `std::vector<Node<T>*> begin_dfs_scan() const`: Returns nodes in DFS traversal.
- `~Tree()`: Destructor to delete the tree.

## Libraries Used
- C++ Standard Library

## Compilation
To compile the project, run the following command:

## Author
Gidi Rabi