// gidirabi111@gmil.com
//Tree.cpp
#include "Tree.hpp"
#include <queue>
#include <stack>

template <typename T>
Tree<T>::Tree() : root(nullptr) {}

template <typename T>
void Tree<T>::add_root(Node<T> root_node) {
    root = new Node<T>(root_node.get_value());
}

template <typename T>
template <typename U>
void Tree<T>::add_root(U val) {
    root = new Node<T>(val);
}

template <typename T>
void Tree<T>::add_sub_node(Node<T> parent_node, Node<T> child_node) {
    auto parent = find(root, parent_node.get_value());
    if (parent) {
        parent->add_child(new Node<T>(child_node.get_value()));
    }
}

template <typename T>
template <typename U, typename V>
void Tree<T>::add_sub_node(U parent_val, V child_val) {
    auto parent = find(root, parent_val);
    if (parent) {
        parent->add_child(new Node<T>(child_val));
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
void Tree<T>::dfs(Node<T>* node, std::vector<Node<T>*>& nodes) const {
    if (!node) return;
    std::stack<Node<T>*> s;
    s.push(node);
    while (!s.empty()) {
        auto current = s.top();
        s.pop();
        nodes.push_back(current);
        for (auto it = current->get_children().rbegin(); it != current->get_children().rend(); ++it) {
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
    dfs(root, nodes);
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
