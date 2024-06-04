// gidirabi111@gmil.com
// tree.hpp
#ifndef TREE_HPP
#define TREE_HPP

#include "Node.hpp"
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
    void dfs(Node<T>* node, std::vector<Node<T>*>& nodes) const;

public:
    Tree();
    void add_root(Node<T> root_node);
    template <typename U>
    void add_root(U val); // Generic add_root
    void add_sub_node(Node<T> parent_node, Node<T> child_node);
    template <typename U, typename V>
    void add_sub_node(U parent_val, V child_val); // Generic add_sub_node
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

// Explicitly instantiate the template for the types you need
extern template class Tree<int>;
extern template class Tree<std::string>;
extern template class Tree<double>;

#endif // TREE_HPP
