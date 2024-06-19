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

    void add_root(const T& data);
    void add_sub_node(Node<T>* parent, const T& child_data);

    typename Node<T>::iterator_preorder begin_preorder();
    typename Node<T>::iterator_preorder end_preorder();
    typename Node<T>::const_iterator_preorder cbegin_preorder() const;
    typename Node<T>::const_iterator_preorder cend_preorder() const;

    typename Node<T>::iterator_inorder begin_inorder();
    typename Node<T>::iterator_inorder end_inorder();
    typename Node<T>::const_iterator_inorder cbegin_inorder() const;
    typename Node<T>::const_iterator_inorder cend_inorder() const;

    typename Node<T>::iterator_postorder begin_postorder();
    typename Node<T>::iterator_postorder end_postorder();
    typename Node<T>::const_iterator_postorder cbegin_postorder() const;
    typename Node<T>::const_iterator_postorder cend_postorder() const;

    typename Node<T>::iterator_bfs begin_bfs();
    typename Node<T>::iterator_bfs end_bfs();
    typename Node<T>::const_iterator_bfs cbegin_bfs() const;
    typename Node<T>::const_iterator_bfs cend_bfs() const;
};

#include "Tree.cpp"  // Include the implementation details
#endif // TREE_HPP
