#include "Tree.hpp"
#include "Node.hpp"
#include "Iterators.hpp"
#include <iostream>

Tree::Tree() : root(nullptr) {}

Tree::~Tree() {
    delete root;
}

void Tree::add_root(Node<std::string>& node) {
    if (root) {
        delete root;
    }
    root = new Node<std::string>(node);
}

void Tree::add_sub_node(Node<std::string>& parent, Node<int>& child) {
    parent.children.push_back(new Node<int>(child));
}

void Tree::add_sub_node(Node<std::string>& parent, Node<std::string>& child) {
    parent.children.push_back(new Node<std::string>(child));
}

void Tree::add_sub_node(Node<std::string>& parent, Node<double>& child) {
    parent.children.push_back(new Node<double>(child));
}

// Pre-order iterator methods
PreOrderIterator<std::string> Tree::begin_pre_order() {
    return PreOrderIterator<std::string>(root);
}

PreOrderIterator<std::string> Tree::end_pre_order() {
    return PreOrderIterator<std::string>(nullptr);
}

// Post-order iterator methods
PostOrderIterator<std::string> Tree::begin_post_order() {
    return PostOrderIterator<std::string>(root);
}

PostOrderIterator<std::string> Tree::end_post_order() {
    return PostOrderIterator<std::string>(nullptr);
}

// In-order iterator methods
InOrderIterator<std::string> Tree::begin_in_order() {
    return InOrderIterator<std::string>(root);
}

InOrderIterator<std::string> Tree::end_in_order() {
    return InOrderIterator<std::string>(nullptr);
}

// BFS iterator methods
BFSIterator<std::string> Tree::begin_bfs_scan() {
    return BFSIterator<std::string>(root);
}

BFSIterator<std::string> Tree::end_bfs_scan() {
    return BFSIterator<std::string>(nullptr);
}

// Print method
std::ostream& operator<<(std::ostream& os, const Tree& tree) {
    // Implement a way to print the tree using a GUI or any other method
    return os;
}
