#include "Node.hpp"

template <typename T>
Node<T>::Node(T val) : value(val) {}

template <typename T>
Node<T>::~Node() {
    for (auto child : children) {
        delete child;
    }
}

template <typename T>
T Node<T>::get_value() {
    return value;
}

// Explicit instantiation of templates
template class Node<int>;
template class Node<double>;
template class Node<std::string>;
