#ifndef TREE_HPP
#define TREE_HPP

#include "Node.hpp"
#include <memory>

template<typename T, int K = 2>
class Tree {
private:
    std::unique_ptr<Node<T>> root;

public:
    Tree();
    ~Tree();

    void add_root(Node<T>& node);
    void add_sub_node(Node<T>& parent, Node<T>& child);

    // Methods to support range-based for loops
    typename Node<T>::iterator_bfs begin();
    typename Node<T>::iterator_bfs end();

    typename Node<T>::const_iterator_bfs begin() const;
    typename Node<T>::const_iterator_bfs end() const;

    typename Node<T>::iterator_preorder begin_pre_order(); // Corrected naming
    typename Node<T>::iterator_preorder end_pre_order();   // Corrected naming
    typename Node<T>::const_iterator_preorder cbegin_pre_order() const; // Corrected naming
    typename Node<T>::const_iterator_preorder cend_pre_order() const;   // Corrected naming

    typename Node<T>::iterator_inorder begin_in_order();   // Corrected naming
    typename Node<T>::iterator_inorder end_in_order();     // Corrected naming
    typename Node<T>::const_iterator_inorder cbegin_in_order() const; // Corrected naming
    typename Node<T>::const_iterator_inorder cend_in_order() const;   // Corrected naming

    typename Node<T>::iterator_postorder begin_post_order(); // Corrected naming
    typename Node<T>::iterator_postorder end_post_order();   // Corrected naming
    typename Node<T>::const_iterator_postorder cbegin_post_order() const; // Corrected naming
    typename Node<T>::const_iterator_postorder cend_post_order() const;   // Corrected naming

    typename Node<T>::iterator_bfs begin_bfs_scan();        // Corrected naming to match demo.cpp
    typename Node<T>::iterator_bfs end_bfs_scan();          // Corrected naming to match demo.cpp
    typename Node<T>::const_iterator_bfs cbegin_bfs_scan() const; // Corrected naming
    typename Node<T>::const_iterator_bfs cend_bfs_scan() const;   // Corrected naming

	// Operator<< to support printing
    template<typename U, int M>
    friend std::ostream& operator<<(std::ostream& os, const Tree<U, M>& tree);
};

#include "Tree.cpp"  // Include the implementation
#endif // TREE_HPP
