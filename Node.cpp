// gidirabi111@gmil.com
// node.cpp
#include "node.hpp"

template <typename T>
Node<T>::Node(T val) : value(val) {}

template <typename T>
T Node<T>::get_value() const { return value; }

template <typename T>
void Node<T>::set_value(T val) { value = val; }

template <typename T>
std::vector<Node<T>*> Node<T>::get_children() const { return children; }

template <typename T>
void Node<T>::add_child(Node<T>* child) { children.push_back(child); }

template <typename T>
Node<T>::~Node() {
    for (auto child : children) {
        delete child;
    }
}

// Explicitly instantiate the template for the types you need
template class Node<int>;
template class Node<std::string>;
template class Node<double>;
