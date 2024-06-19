#ifndef NODE_HPP
#define NODE_HPP

#include <vector>
#include <string>

template <typename T>
class Node {
public:
    T value;
    std::vector<Node*> children;

    Node(T val);
    ~Node();

    T get_value();
};

#include "Node.tpp"

#endif // NODE_HPP
