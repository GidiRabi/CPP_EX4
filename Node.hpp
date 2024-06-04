// gidirabi111@gmail.com
//Node.hpp
#ifndef NODE_HPP
#define NODE_HPP

#include <vector>
#include <string>

template <typename T>
class Node {
private:
    T value;
    std::vector<Node<T>*> children;

public:
    Node(T val); // Constructor with type T
    template <typename U>
    Node(U val); // Generic constructor with type U
    T get_value() const;
    void set_value(T val);
    std::vector<Node<T>*> get_children() const;
    void add_child(Node<T>* child);
    ~Node();
};

#endif // NODE_HPP
