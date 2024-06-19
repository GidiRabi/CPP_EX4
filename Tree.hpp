#ifndef TREE_HPP
#define TREE_HPP

#include "Node.hpp"
#include <string>
#include <iostream>

class Tree {
private:
    Node<std::string>* root;

public:
    Tree();
    ~Tree();

    void add_root(Node<std::string>& node);
    void add_sub_node(Node<std::string>& parent, Node<int>& child);
    void add_sub_node(Node<std::string>& parent, Node<std::string>& child);
    void add_sub_node(Node<std::string>& parent, Node<double>& child);

    PreOrderIterator<std::string> begin_pre_order();
    PreOrderIterator<std::string> end_pre_order();
    PostOrderIterator<std::string> begin_post_order();
    PostOrderIterator<std::string> end_post_order();
    InOrderIterator<std::string> begin_in_order();
    InOrderIterator<std::string> end_in_order();
    BFSIterator<std::string> begin_bfs_scan();
    BFSIterator<std::string> end_bfs_scan();

    // Print method
    friend std::ostream& operator<<(std::ostream& os, const Tree& tree);
};

#endif // TREE_HPP
