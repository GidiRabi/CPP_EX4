// gidirabi111@gmil.com
// tree.cpp
#include "tree.hpp"
#include <queue>
#include <stack>

template <typename T>
Tree<T>::Tree() : root(nullptr) {}

template <typename T>
void Tree<T>::add_root(T value) {
    root = new Node<T>(value);
}

template <typename T>
void Tree<T>::add_sub_node(T parent_value, T child_value) {
    auto parent_node = find(root, parent_value);
    if (parent_node) {
        parent_node->add_child(new Node<T>(child_value));
    }
}

template <typename T>
Node<T>* Tree<T>::find(Node<T>* node, T value) {
    if (!node) return nullptr;
    if (node->get_value() == value) return node;
    for (auto child : node->get_children()) {
        auto result = find(child, value);
        if (result) return result;
    }
    return nullptr;
}

template <typename T>
void Tree<T>::pre_order(Node<T>* node, std::vector<Node<T>*>& nodes) const {
    if (!node) return;
    nodes.push_back(node);
    for (auto child : node->get_children()) {
        pre_order(child, nodes);
    }
}

template <typename T>
void Tree<T>::post_order(Node<T>* node, std::vector<Node<T>*>& nodes) const {
    if (!node) return;
    for (auto child : node->get_children()) {
        post_order(child, nodes);
    }
    nodes.push_back(node);
}

template <typename T>
void Tree<T>::in_order(Node<T>* node, std::vector<Node<T>*>& nodes) const {
    if (!node) return;
    if (node->get_children().size() > 0) in_order(node->get_children()[0], nodes);
    nodes.push_back(node);
    if (node->get_children().size() > 1) in_order(node->get_children()[1], nodes);
}

template <typename T>
void Tree<T>::bfs(std::vector<Node<T>*>& nodes) const {
    if (!root) return;
    std::queue<Node<T>*> q;
    q.push(root);
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        nodes.push_back(node);
        for (auto child : node->get_children()) {
            q.push(child);
        }
    }
}

template <typename T>
void Tree<T>::dfs(std::vector<Node<T>*>& nodes) const {
    if (!root) return;
    std::stack<Node<T>*> s;
    s.push(root);
    while (!s.empty()) {
        auto node = s.top();
        s.pop();
        nodes.push_back(node);
        for (auto it = node->get_children().rbegin(); it != node->get_children().rend(); ++it) {
            s.push(*it);
        }
    }
}

template <typename T>
std::vector<Node<T>*> Tree<T>::begin_pre_order() const {
    std::vector<Node<T>*> nodes;
    pre_order(root, nodes);
    return nodes;
}

template <typename T>
std::vector<Node<T>*> Tree<T>::begin_post_order() const {
    std::vector<Node<T>*> nodes;
    post_order(root, nodes);
    return nodes;
}

template <typename T>
std::vector<Node<T>*> Tree<T>::begin_in_order() const {
    std::vector<Node<T>*> nodes;
    in_order(root, nodes);
    return nodes;
}

template <typename T>
std::vector<Node<T>*> Tree<T>::begin_bfs_scan() const {
    std::vector<Node<T>*> nodes;
    bfs(nodes);
    return nodes;
}

template <typename T>
std::vector<Node<T>*> Tree<T>::begin_dfs_scan() const {
    std::vector<Node<T>*> nodes;
    dfs(nodes);
    return nodes;
}

template <typename T>
Tree<T>::~Tree() {
    delete root;
}

// Explicitly instantiate the template for the types you need
template class Tree<int>;
template class Tree<std::string>;
template class Tree<double>;
