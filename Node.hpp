// node.hpp
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
    Node(T val);
    T get_value() const;
    void set_value(T val);
    std::vector<Node<T>*> get_children() const;
    void add_child(Node<T>* child);
    ~Node();
};

#endif // NODE_HPP
