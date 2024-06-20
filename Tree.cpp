//Tree.cpp
#include "Tree.hpp"
#include "Node.hpp"

template<typename T, int K>
Tree<T, K>::Tree() {}

template<typename T, int K>
Tree<T, K>::~Tree() {}

template<typename T, int K>
void Tree<T, K>::add_root(Node<T>& node) {
    root = std::make_unique<Node<T>>(node.data);  // Properly construct a Node from data
}

template<typename T, int K>
void Tree<T, K>::add_sub_node(Node<T>& parent, Node<T>& child) {
    if (parent.children.size() < K) {
        parent.children.emplace_back(std::make_unique<Node<T>>(child.data)); // Correctly add child
    }
}

// PreOrder
template<typename T, int K>
typename Node<T>::iterator_preorder Tree<T, K>::begin_pre_order() {
    return typename Node<T>::iterator_preorder(root.get());
}

template<typename T, int K>
typename Node<T>::iterator_preorder Tree<T, K>::end_pre_order() {
    return typename Node<T>::iterator_preorder(nullptr);
}

template<typename T, int K>
typename Node<T>::const_iterator_preorder Tree<T, K>::cbegin_pre_order() const {
    return typename Node<T>::const_iterator_preorder(root.get());
}

template<typename T, int K>
typename Node<T>::const_iterator_preorder Tree<T, K>::cend_pre_order() const {
    return typename Node<T>::const_iterator_preorder(nullptr);
}

// InOrder
template<typename T, int K>
typename Node<T>::iterator_inorder Tree<T, K>::begin_in_order() {
    return typename Node<T>::iterator_inorder(root.get());
}

template<typename T, int K>
typename Node<T>::iterator_inorder Tree<T, K>::end_in_order() {
    return typename Node<T>::iterator_inorder(nullptr);
}

template<typename T, int K>
typename Node<T>::const_iterator_inorder Tree<T, K>::cbegin_in_order() const {
    return typename Node<T>::const_iterator_inorder(root.get());
}

template<typename T, int K>
typename Node<T>::const_iterator_inorder Tree<T, K>::cend_in_order() const {
    return typename Node<T>::const_iterator_inorder(nullptr);
}

// PostOrder
template<typename T, int K>
typename Node<T>::iterator_postorder Tree<T, K>::begin_post_order() {
    return typename Node<T>::iterator_postorder(root.get());
}

template<typename T, int K>
typename Node<T>::iterator_postorder Tree<T, K>::end_post_order() {
    return typename Node<T>::iterator_postorder(nullptr);
}

template<typename T, int K>
typename Node<T>::const_iterator_postorder Tree<T, K>::cbegin_post_order() const {
    return typename Node<T>::const_iterator_postorder(root.get());
}

template<typename T, int K>
typename Node<T>::const_iterator_postorder Tree<T, K>::cend_post_order() const {
    return typename Node<T>::const_iterator_postorder(nullptr);
}

// BFS
template<typename T, int K>
typename Node<T>::iterator_bfs Tree<T, K>::begin_bfs_scan() {
    return typename Node<T>::iterator_bfs(root.get());
}

template<typename T, int K>
typename Node<T>::iterator_bfs Tree<T, K>::end_bfs_scan() {
    return typename Node<T>::iterator_bfs(nullptr);
}

template<typename T, int K>
typename Node<T>::const_iterator_bfs Tree<T, K>::cbegin_bfs_scan() const {
    return typename Node<T>::const_iterator_bfs(root.get());
}

template<typename T, int K>
typename Node<T>::const_iterator_bfs Tree<T, K>::cend_bfs_scan() const {
    return typename Node<T>::const_iterator_bfs(nullptr);
}

// Explicit template instantiation for expected types
template class Tree<int>;
template class Tree<double>;
template class Tree<std::string>;
