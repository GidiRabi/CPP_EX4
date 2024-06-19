//Node.hpp
#include "Node.hpp"


template<typename T>
Node<T>::Node(const T& data) : data(data) {}

template<typename T>
Node<T>::~Node() {}

template<typename T>
T Node<T>::get_value() const {
    return data;
}


// ----- PreOrder Iterator Definitions -----
template<typename T>
Node<T>::iterator_preorder::iterator_preorder(Node<T>* root) {
    if (root != nullptr) {
        stack.push(root);
    }
    current = (stack.empty() ? nullptr : stack.top());
}

template<typename T>
Node<T>& Node<T>::iterator_preorder::operator*() const {
    return current->data;
}

template<typename T>
Node<T>* Node<T>::iterator_preorder::operator->() const {
    return &current->data;
}

template<typename T>
typename Node<T>::iterator_preorder& Node<T>::iterator_preorder::operator++() {
    if (stack.empty()) {
        current = nullptr;
        return *this;
    }
    Node<T>* node = stack.top();
    stack.pop();
    for (auto it = node->children.rbegin(); it != node->children.rend(); ++it) {
        stack.push(it->get());
    }
    current = (stack.empty() ? nullptr : stack.top());
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

template<typename T>
Node<T>::const_iterator_preorder::const_iterator_preorder(const Node<T>* root) {
    if (root != nullptr) {
        stack.push(root);
    }
    current = (stack.empty() ? nullptr : stack.top());
}

template<typename T>
const Node<T>& Node<T>::const_iterator_preorder::operator*() const {
    return current->data;
}

template<typename T>
const Node<T>* Node<T>::const_iterator_preorder::operator->() const {
    return &current->data;
}

template<typename T>
typename Node<T>::const_iterator_preorder& Node<T>::const_iterator_preorder::operator++() {
    if (stack.empty()) {
        current = nullptr;
        return *this;
    }
    const Node<T>* node = stack.top();
    stack.pop();
    for (auto it = node->children.rbegin(); it != node->children.rend(); ++it) {
        stack.push(it->get());
    }
    current = (stack.empty() ? nullptr : stack.top());
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

// ----- Const PreOrder Iterator Definitions -----
template<typename T>
Node<T>::const_iterator_preorder::const_iterator_preorder(const Node<T>* root) {
    if (root != nullptr) {
        stack.push(root);
    }
    current = (stack.empty() ? nullptr : stack.top());
}

template<typename T>
const Node<T>& Node<T>::const_iterator_preorder::operator*() const {
    return current->data;
}

template<typename T>
const Node<T>* Node<T>::const_iterator_preorder::operator->() const {
    return &current->data;
}

template<typename T>
typename Node<T>::const_iterator_preorder& Node<T>::const_iterator_preorder::operator++() {
    if (stack.empty()) {
        current = nullptr;
        return *this;
    }
    const Node<T>* node = stack.top();
    stack.pop();
    for (auto it = node->children.rbegin(); it != node->children.rend(); ++it) {
        stack.push(it->get());
    }
    current = (stack.empty() ? nullptr : stack.top());
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
        stack.push(root);
        root = (root->children.empty() ? nullptr : root->children.front().get());
    }
    current = (stack.empty() ? nullptr : stack.top());
}

template<typename T>
Node<T>& Node<T>::iterator_inorder::operator*() const {
    return current->data;
}

template<typename T>
Node<T>* Node<T>::iterator_inorder::operator->() const {
    return &current->data;
}

template<typename T>
typename Node<T>::iterator_inorder& Node<T>::iterator_inorder::operator++() {
    if (stack.empty()) {
        current = nullptr;
        return *this;
    }
    Node<T>* node = stack.top();
    stack.pop();
    if (node->children.size() > 1) {
        node = node->children[1].get();
        while (node) {
            stack.push(node);
            node = (node->children.empty() ? nullptr : node->children.front().get());
        }
    }
    current = (stack.empty() ? nullptr : stack.top());
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

template<typename T>
Node<T>::const_iterator_inorder::const_iterator_inorder(const Node<T>* root) {
    while (root != nullptr) {
        stack.push(root);
        root = (root->children.empty() ? nullptr : root->children.front().get());
    }
    current = (stack.empty() ? nullptr : stack.top());
}

template<typename T>
const Node<T>& Node<T>::const_iterator_inorder::operator*() const {
    return current->data;
}

template<typename T>
const Node<T>* Node<T>::const_iterator_inorder::operator->() const {
    return &current->data;
}

template<typename T>
typename Node<T>::const_iterator_inorder& Node<T>::const_iterator_inorder::operator++() {
    if (stack.empty()) {
        current = nullptr;
        return *this;
    }
    const Node<T>* node = stack.top();
    stack.pop();
    if (node->children.size() > 1) {
        node = node->children[1].get();
        while (node) {
            stack.push(node);
            node = (node->children.empty() ? nullptr : node->children.front().get());
        }
    }
    current = (stack.empty() ? nullptr : stack.top());
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

// ----- Const InOrder Iterator Definitions -----
template<typename T>
Node<T>::const_iterator_inorder::const_iterator_inorder(const Node<T>* root) {
    while (root != nullptr) {
        stack.push(root);
        root = (root->children.empty() ? nullptr : root->children.front().get());
    }
    current = (stack.empty() ? nullptr : stack.top());
}

template<typename T>
const Node<T>& Node<T>::const_iterator_inorder::operator*() const {
    return current->data;
}

template<typename T>
const Node<T>* Node<T>::const_iterator_inorder::operator->() const {
    return &current->data;
}

template<typename T>
typename Node<T>::const_iterator_inorder& Node<T>::const_iterator_inorder::operator++() {
    if (stack.empty()) {
        current = nullptr;
        return *this;
    }
    const Node<T>* node = stack.top();
    stack.pop();
    if (node->children.size() > 1) {
        node = node->children[1].get();
        while (node) {
            stack.push(node);
            node = (node->children.empty() ? nullptr : node->children.front().get());
        }
    }
    current = (stack.empty() ? nullptr : stack.top());
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
    return current->data;
}

template<typename T>
Node<T>* Node<T>::iterator_postorder::operator->() const {
    return &current->data;
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
    const Node<T>* lastNode = nullptr;
    while (root != nullptr) {
        stack.push(root);
        if (!root->children.empty()) {
            root = root->children.front().get();
        } else {
            root = nullptr;
        }
    }
    if (!stack.empty()) {
        lastNode = stack.top();
    }
    current = lastNode;
}

template<typename T>
const Node<T>& Node<T>::const_iterator_postorder::operator*() const {
    return current->data;
}

template<typename T>
const Node<T>* Node<T>::const_iterator_postorder::operator->() const {
    return &current->data;
}

template<typename T>
typename Node<T>::const_iterator_postorder& Node<T>::const_iterator_postorder::operator++() {
    if (stack.empty()) {
        current = nullptr;
        return *this;
    }

    const Node<T>* lastNode = nullptr;
    bool hasChildrenProcessed = false;

    while (!stack.empty() && !hasChildrenProcessed) {
        const Node<T>* node = stack.top();
        stack.pop();

        if (!node->children.empty()) {
            // Push all children to stack, starting from the last to first (right to left)
            for (auto it = node->children.rbegin(); it != node->children.rend(); ++it) {
                stack.push(it->get());
            }
            stack.push(node);  // Push the parent node back to stack
            hasChildrenProcessed = true;
        } else {
            // If no children, this is a leaf node, process it
            lastNode = node;
        }
    }

    // If we've processed children, the next node to process is on top of the stack
    if (!stack.empty() && hasChildrenProcessed) {
        lastNode = stack.top();
        stack.pop();
    }

    current = lastNode;
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
        queue.push(root);
    }
    current = (queue.empty() ? nullptr : queue.front());
}

template<typename T>
Node<T>& Node<T>::iterator_bfs::operator*() const {
    return current->data;
}

template<typename T>
Node<T>* Node<T>::iterator_bfs::operator->() const {
    return &current->data;
}

template<typename T>
typename Node<T>::iterator_bfs& Node<T>::iterator_bfs::operator++() {
    if (queue.empty()) {
        current = nullptr;
        return *this;
    }
    Node<T>* node = queue.front();
    queue.pop();
    for (auto& child : node->children) {
        queue.push(child.get());
    }
    current = (queue.empty() ? nullptr : queue.front());
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

template<typename T>
Node<T>::iterator_bfs::iterator_bfs(Node<T>* root) : current(nullptr) {
    if (root != nullptr) {
        queue.push(root);
        advance();  // Ensure the current is set correctly at construction
    }
}

template<typename T>
void Node<T>::iterator_bfs::advance() {
    if (!queue.empty()) {
        current = queue.front();
        queue.pop();
        for (auto& child : current->children) {
            if (child.get() != nullptr) {
                queue.push(child.get());
            }
        }
    } else {
        current = nullptr;
    }
}

// ----- Const BFS Iterator Definitions -----
template<typename T>
Node<T>::const_iterator_bfs::const_iterator_bfs(const Node<T>* root) {
    if (root != nullptr) {
        queue.push(root);
    }
    current = (queue.empty() ? nullptr : queue.front());
}

template<typename T>
const Node<T>& Node<T>::const_iterator_bfs::operator*() const {
    return current->data;
}

template<typename T>
const Node<T>* Node<T>::const_iterator_bfs::operator->() const {
    return &current->data;
}

template<typename T>
typename Node<T>::const_iterator_bfs& Node<T>::const_iterator_bfs::operator++() {
    if (queue.empty()) {
        current = nullptr;
        return *this;
    }
    const Node<T>* node = queue.front();
    queue.pop();
    for (const auto& child : node->children) {
        queue.push(child.get());
    }
    current = (queue.empty() ? nullptr : queue.front());
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
template class Node<std::string>;
