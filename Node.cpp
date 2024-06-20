#include "Node.hpp"
#include <stack>
#include <queue>

using namespace std;

// Constructor
template<typename T>
Node<T>::Node(const T& data) : data(data) {}

// Destructor
template<typename T>
Node<T>::~Node() = default;

// Accessor for node data
template<typename T>
T Node<T>::get_value() const {
    return data;
}

// ----- PreOrder Iterator Definitions -----
template<typename T>
Node<T>::iterator_preorder::iterator_preorder(Node<T>* root) {
    if (root != nullptr) {
        this->stack.push(root);
    }
    current = (this->stack.empty() ? nullptr : this->stack.top());
}

template<typename T>
Node<T>& Node<T>::iterator_preorder::operator*() const {
    return *current;
}

template<typename T>
Node<T>* Node<T>::iterator_preorder::operator->() const {
    return current;
}

template<typename T>
typename Node<T>::iterator_preorder& Node<T>::iterator_preorder::operator++() {
    if (this->stack.empty()) {
        current = nullptr;
        return *this;
    }
    Node<T>* node = this->stack.top();
    this->stack.pop();
    for (auto it = node->children.rbegin(); it != node->children.rend(); ++it) {
        this->stack.push(it->get());
    }
    current = (this->stack.empty() ? nullptr : this->stack.top());
    return *this;
}

template<typename T>
typename Node<T>::iterator_preorder Node<T>::iterator_preorder::operator++(int) {
    iterator_preorder tmp(*this);
    ++(*this);
    return tmp;
}

template<typename T>
bool Node<T>::iterator_preorder::operator==(const iterator_preorder& other) const {
    return current == other.current;
}

template<typename T>
bool Node<T>::iterator_preorder::operator!=(const iterator_preorder& other) const {
    return current != other.current;
}

// ----- Const PreOrder Iterator Definitions -----
template<typename T>
Node<T>::const_iterator_preorder::const_iterator_preorder(const Node<T>* root) {
    if (root != nullptr) {
        this->stack.push(root);
    }
    current = (this->stack.empty() ? nullptr : this->stack.top());
}

template<typename T>
const Node<T>& Node<T>::const_iterator_preorder::operator*() const {
    return *current;
}

template<typename T>
const Node<T>* Node<T>::const_iterator_preorder::operator->() const {
    return current;
}

template<typename T>
typename Node<T>::const_iterator_preorder& Node<T>::const_iterator_preorder::operator++() {
    if (this->stack.empty()) {
        current = nullptr;
        return *this;
    }
    const Node<T>* node = this->stack.top();
    this->stack.pop();
    for (auto it = node->children.rbegin(); it != node->children.rend(); ++it) {
        this->stack.push(it->get());
    }
    current = (this->stack.empty() ? nullptr : this->stack.top());
    return *this;
}

template<typename T>
typename Node<T>::const_iterator_preorder Node<T>::const_iterator_preorder::operator++(int) {
    const_iterator_preorder tmp(*this);
    ++(*this);
    return tmp;
}

template<typename T>
bool Node<T>::const_iterator_preorder::operator==(const const_iterator_preorder& other) const {
    return current == other.current;
}

template<typename T>
bool Node<T>::const_iterator_preorder::operator!=(const const_iterator_preorder& other) const {
    return current != other.current;
}

// ----- InOrder Iterator Definitions -----
template<typename T>
Node<T>::iterator_inorder::iterator_inorder(Node<T>* root) {
    // Push all left children onto the stack
    while (root != nullptr) {
        this->stack.push(root);
        root = (root->children.empty() ? nullptr : root->children.front().get());
    }
    current = (this->stack.empty() ? nullptr : this->stack.top());
}

template<typename T>
Node<T>& Node<T>::iterator_inorder::operator*() const {
    return *current;
}

template<typename T>
Node<T>* Node<T>::iterator_inorder::operator->() const {
    return current;
}

template<typename T>
typename Node<T>::iterator_inorder& Node<T>::iterator_inorder::operator++() {
    if (this->stack.empty()) {
        current = nullptr;
        return *this;
    }
    Node<T>* node = this->stack.top();
    this->stack.pop();
    if (node->children.size() > 1) {
        node = node->children[1].get();
        while (node) {
            this->stack.push(node);
            node = (node->children.empty() ? nullptr : node->children.front().get());
        }
    }
    current = (this->stack.empty() ? nullptr : this->stack.top());
    return *this;
}

template<typename T>
typename Node<T>::iterator_inorder Node<T>::iterator_inorder::operator++(int) {
    iterator_inorder tmp(*this);
    ++(*this);
    return tmp;
}

template<typename T>
bool Node<T>::iterator_inorder::operator==(const iterator_inorder& other) const {
    return current == other.current;
}

template<typename T>
bool Node<T>::iterator_inorder::operator!=(const iterator_inorder& other) const {
    return current != other.current;
}

// ----- Const InOrder Iterator Definitions -----
template<typename T>
Node<T>::const_iterator_inorder::const_iterator_inorder(const Node<T>* root) {
    while (root != nullptr) {
        this->stack.push(root);
        root = (root->children.empty() ? nullptr : root->children.front().get());
    }
    current = (this->stack.empty() ? nullptr : this->stack.top());
}

template<typename T>
const Node<T>& Node<T>::const_iterator_inorder::operator*() const {
    return *current;
}

template<typename T>
const Node<T>* Node<T>::const_iterator_inorder::operator->() const {
    return current;
}

template<typename T>
typename Node<T>::const_iterator_inorder& Node<T>::const_iterator_inorder::operator++() {
    if (this->stack.empty()) {
        current = nullptr;
        return *this;
    }
    const Node<T>* node = this->stack.top();
    this->stack.pop();
    if (node->children.size() > 1) {
        node = node->children[1].get();
        while (node) {
            this->stack.push(node);
            node = (node->children.empty() ? nullptr : node->children.front().get());
        }
    }
    current = (this->stack.empty() ? nullptr : this->stack.top());
    return *this;
}

template<typename T>
typename Node<T>::const_iterator_inorder Node<T>::const_iterator_inorder::operator++(int) {
    const_iterator_inorder tmp(*this);
    ++(*this);
    return tmp;
}

template<typename T>
bool Node<T>::const_iterator_inorder::operator==(const const_iterator_inorder& other) const {
    return current == other.current;
}

template<typename T>
bool Node<T>::const_iterator_inorder::operator!=(const const_iterator_inorder& other) const {
    return current != other.current;
}

// ----- PostOrder Iterator Definitions -----
template<typename T>
Node<T>::iterator_postorder::iterator_postorder(Node<T>* root) {
    // Full logic to be added
}

template<typename T>
Node<T>& Node<T>::iterator_postorder::operator*() const {
    return *current;
}

template<typename T>
Node<T>* Node<T>::iterator_postorder::operator->() const {
    return current;
}

template<typename T>
typename Node<T>::iterator_postorder& Node<T>::iterator_postorder::operator++() {
    // Full logic to be added
    return *this;
}

template<typename T>
typename Node<T>::iterator_postorder Node<T>::iterator_postorder::operator++(int) {
    iterator_postorder tmp(*this);
    ++(*this);
    return tmp;
}

template<typename T>
bool Node<T>::iterator_postorder::operator==(const iterator_postorder& other) const {
    return current == other.current;
}

template<typename T>
bool Node<T>::iterator_postorder::operator!=(const iterator_postorder& other) const {
    return current != other.current;
}

// ----- Const PostOrder Iterator Definitions -----
template<typename T>
Node<T>::const_iterator_postorder::const_iterator_postorder(const Node<T>* root) {
    // Initialize by navigating to the leftmost leaf
    while (root != nullptr) {
        this->stack.push(root);
        if (!root->children.empty()) {
            root = root->children.front().get();
        } else {
            root = nullptr;
        }
    }
    current = (this->stack.empty() ? nullptr : this->stack.top());
}

template<typename T>
const Node<T>& Node<T>::const_iterator_postorder::operator*() const {
    return *current;
}

template<typename T>
const Node<T>* Node<T>::const_iterator_postorder::operator->() const {
    return current;
}

template<typename T>
typename Node<T>::const_iterator_postorder& Node<T>::const_iterator_postorder::operator++() {
    if (this->stack.empty()) {
        current = nullptr;
        return *this;
    }
    const Node<T>* node = this->stack.top();
    this->stack.pop();
    if (!this->stack.empty() && node == this->stack.top()->children.back().get()) {
        current = this->stack.top();
    } else {
        current = nullptr;
        while (!this->stack.empty()) {
            node = this->stack.top();
            this->stack.pop();
            if (!this->stack.empty() && node == this->stack.top()->children.back().get()) {
                current = this->stack.top();
                break;
            }
        }
    }
    return *this;
}

template<typename T>
typename Node<T>::const_iterator_postorder Node<T>::const_iterator_postorder::operator++(int) {
    const_iterator_postorder tmp(*this);
    ++(*this);
    return tmp;
}

template<typename T>
bool Node<T>::const_iterator_postorder::operator==(const const_iterator_postorder& other) const {
    return current == other.current;
}

template<typename T>
bool Node<T>::const_iterator_postorder::operator!=(const const_iterator_postorder& other) const {
    return current != other.current;
}

// ----- BFS Iterator Definitions -----
template<typename T>
Node<T>::iterator_bfs::iterator_bfs(Node<T>* root) {
    if (root != nullptr) {
        this->queue.push(root);
    }
    current = (this->queue.empty() ? nullptr : this->queue.front());
}

template<typename T>
Node<T>& Node<T>::iterator_bfs::operator*() const {
    return *current;
}

template<typename T>
Node<T>* Node<T>::iterator_bfs::operator->() const {
    return current;
}

template<typename T>
typename Node<T>::iterator_bfs& Node<T>::iterator_bfs::operator++() {
    if (this->queue.empty()) {
        current = nullptr;
        return *this;
    }
    Node<T>* node = this->queue.front();
    this->queue.pop();
    for (auto& child : node->children) {
        this->queue.push(child.get());
    }
    current = (this->queue.empty() ? nullptr : this->queue.front());
    return *this;
}

template<typename T>
typename Node<T>::iterator_bfs Node<T>::iterator_bfs::operator++(int) {
    iterator_bfs tmp(*this);
    ++(*this);
    return tmp;
}

template<typename T>
bool Node<T>::iterator_bfs::operator==(const iterator_bfs& other) const {
    return current == other.current;
}

template<typename T>
bool Node<T>::iterator_bfs::operator!=(const iterator_bfs& other) const {
    return current != other.current;
}

// ----- Const BFS Iterator Definitions -----
template<typename T>
Node<T>::const_iterator_bfs::const_iterator_bfs(const Node<T>* root) {
    if (root != nullptr) {
        this->queue.push(root);
    }
    current = (this->queue.empty() ? nullptr : this->queue.front());
}

template<typename T>
const Node<T>& Node<T>::const_iterator_bfs::operator*() const {
    return *current;
}

template<typename T>
const Node<T>* Node<T>::const_iterator_bfs::operator->() const {
    return current;
}

template<typename T>
typename Node<T>::const_iterator_bfs& Node<T>::const_iterator_bfs::operator++() {
    if (this->queue.empty()) {
        current = nullptr;
        return *this;
    }
    const Node<T>* node = this->queue.front();
    this->queue.pop();
    for (const auto& child : node->children) {
        this->queue.push(child.get());
    }
    current = (this->queue.empty() ? nullptr : this->queue.front());
    return *this;
}

template<typename T>
typename Node<T>::const_iterator_bfs Node<T>::const_iterator_bfs::operator++(int) {
    const_iterator_bfs tmp(*this);
    ++(*this);
    return tmp;
}

template<typename T>
bool Node<T>::const_iterator_bfs::operator==(const const_iterator_bfs& other) const {
    return current == other.current;
}

template<typename T>
bool Node<T>::const_iterator_bfs::operator!=(const const_iterator_bfs& other) const {
    return current != other.current;
}

// Explicit template instantiation for types
template class Node<int>;
template class Node<double>;
template class Node<string>;
