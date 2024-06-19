#include "Tree.hpp"

template<typename T, int K>
Tree<T, K>::Tree() {
}

template<typename T, int K>
Tree<T, K>::~Tree() {
}

template<typename T, int K>
void Tree<T, K>::add_root(const T& data) {
    root = std::make_unique<Node<T>>(data);
}

template<typename T, int K>
void Tree<T, K>::add_sub_node(Node<T>* parent, const T& child_data) {
    if (parent && parent->children.size() < K) {
        parent->children.emplace_back(std::make_unique<Node<T>>(child_data));
    }
}

template<typename T, int K>
typename Node<T>::iterator_preorder Tree<T, K>::begin_preorder() {
    return typename Node<T>::iterator_preorder(root.get());
}

template<typename T, int K>
typename Node<T>::iterator_preorder Tree<T, K>::end_preorder() {
    return typename Node<T>::iterator_preorder(nullptr);
}

template<typename T, int K>
typename Node<T>::const_iterator_preorder Tree<T, K>::cbegin_preorder() const {
    return typename Node<T>::const_iterator_preorder(root.get());
}

template<typename T, int K>
typename Node<T>::const_iterator_preorder Tree<T, K>::cend_preorder() const {
    return typename Node<T>::const_iterator_preorder(nullptr);
}

template<typename T, int K>
typename Node<T>::iterator_inorder Tree<T, K>::begin_inorder() {
    return typename Node<T>::iterator_inorder(root.get());
}

template<typename T, int K>
typename Node<T>::iterator_inorder Tree<T, K>::end_inorder() {
    return typename Node<T>::iterator_inorder(nullptr);
}

template<typename T, int K>
typename Node<T>::const_iterator_inorder Tree<T, K>::cbegin_inorder() const {
    return typename Node<T>::const_iterator_inorder(root.get());
}

template<typename T, int K>
typename Node<T>::const_iterator_inorder Tree<T, K>::cend_inorder() const {
    return typename Node<T>::const_iterator_inorder(nullptr);
}

template<typename T, int K>
typename Node<T>::iterator_postorder Tree<T, K>::begin_postorder() {
    return typename Node<T>::iterator_postorder(root.get());
}

template<typename T, int K>
typename Node<T>::iterator_postorder Tree<T, K>::end_postorder() {
    return typename Node<T>::iterator_postorder(nullptr);
}

template<typename T, int K>
typename Node<T>::const_iterator_postorder Tree<T, K>::cbegin_postorder() const {
    return typename Node<T>::const_iterator_postorder(root.get());
}

template<typename T, int K>
typename Node<T>::const_iterator_postorder Tree<T, K>::cend_postorder() const {
    return typename Node<T>::const_iterator_postorder(nullptr);
}

template<typename T, int K>
typename Node<T>::iterator_bfs Tree<T, K>::begin_bfs() {
    return typename Node<T>::iterator_bfs(root.get());
}

template<typename T, int K>
typename Node<T>::iterator_bfs Tree<T, K>::end_bfs() {
    return typename Node<T>::iterator_bfs(nullptr);
}

template<typename T, int K>
typename Node<T>::const_iterator_bfs Tree<T, K>::cbegin_bfs() const {
    return typename Node<T>::const_iterator_bfs(root.get());
}

template<typename T, int K>
typename Node<T>::const_iterator_bfs Tree<T, K>::cend_bfs() const {
    return typename Node<T>::const_iterator_bfs(nullptr);
}

// Explicit template instantiation for expected types
template class Tree<int>;
template class Tree<double>;
template class Tree<std::string>;
