// gidirabi111@gmil.com
// tree.hpp
#ifndef TREE_HPP
#define TREE_HPP

#include "node.hpp"
#include <iostream>
#include <vector>

template <typename T>
class Tree {
private:
    Node<T>* root;

    void pre_order(Node<T>* node, std::vector<Node<T>*>& nodes) const;
    void post_order(Node<T>* node, std::vector<Node<T>*>& nodes) const;
    void in_order(Node<T>* node, std::vector<Node<T>*>& nodes) const;
    void bfs(std::vector<Node<T>*>& nodes) const;
    void dfs(std::vector<Node<T>*>& nodes) const;

public:
    Tree();
    void add_root(T value);
    void add_sub_node(T parent_value, T child_value);
    Node<T>* find(Node<T>* node, T value);
    std::vector<Node<T>*> begin_pre_order() const;
    std::vector<Node<T>*> begin_post_order() const;
    std::vector<Node<T>*> begin_in_order() const;
    std::vector<Node<T>*> begin_bfs_scan() const;
    std::vector<Node<T>*> begin_dfs_scan() const;
    ~Tree();

    friend std::ostream& operator<<(std::ostream& os, const Tree& tree) {
        // Implement GUI logic to print the tree
        return os;
    }
};

#endif // TREE_HPP
