// 325483444 gidirabi111@gmail.com
#ifndef NODE_HPP
#define NODE_HPP

#include <vector>
#include <stack>
#include <queue>

template<typename T>
class Node {
public:
    T data; // The data stored in the node.
    std::vector<Node<T>*> children; // The children nodes of this node.

    Node(const T& data);
    Node(const Node& other); // Copy constructor
    Node& operator=(const Node<T>& other); // Copy assignment operator
    ~Node();

    T get_value() const;

    // PreOrder iterator
    class iterator_preorder {
    private:
        Node<T>* current;
        std::stack<Node<T>*> stack;
    public:
        iterator_preorder(Node<T>* root);
        Node<T>& operator*() const;
        Node<T>* operator->() const;
        iterator_preorder& operator++();
        iterator_preorder operator++(int);
        bool operator==(const iterator_preorder& other) const;
        bool operator!=(const iterator_preorder& other) const;
    };

    // Const PreOrder iterator
    class const_iterator_preorder {
    private:
        const Node<T>* current;
        std::stack<const Node<T>*> stack;
    public:
        const_iterator_preorder(const Node<T>* root);
        const Node<T>& operator*() const;
        const Node<T>* operator->() const;
        const_iterator_preorder& operator++();
        const_iterator_preorder operator++(int);
        bool operator==(const const_iterator_preorder& other) const;
        bool operator!=(const const_iterator_preorder& other) const;
    };

    // PostOrder iterator
    class iterator_postorder {
    private:
        Node<T>* current;
        std::stack<Node<T>*> stack;
    public:
        iterator_postorder(Node<T>* root);
        Node<T>& operator*() const;
        Node<T>* operator->() const;
        iterator_postorder& operator++();
        iterator_postorder operator++(int);
        bool operator==(const iterator_postorder& other) const;
        bool operator!=(const iterator_postorder& other) const;
    };

    // Const PostOrder iterator
    class const_iterator_postorder {
    private:
        const Node<T>* current;
        std::stack<const Node<T>*> stack;
    public:
        const_iterator_postorder(const Node<T>* root);
        const Node<T>& operator*() const;
        const Node<T>* operator->() const;
        const_iterator_postorder& operator++();
        const_iterator_postorder operator++(int);
        bool operator==(const const_iterator_postorder& other) const;
        bool operator!=(const const_iterator_postorder& other) const;
    };

    // InOrder iterator
    class iterator_inorder {
    private:
        Node<T>* current;
        std::stack<Node<T>*> stack;
    public:
        iterator_inorder(Node<T>* root);
        Node<T>& operator*() const;
        Node<T>* operator->() const;
        iterator_inorder& operator++();
        iterator_inorder operator++(int);
        bool operator==(const iterator_inorder& other) const;
        bool operator!=(const iterator_inorder& other) const;
    };

    // Const InOrder iterator
    class const_iterator_inorder {
    private:
        const Node<T>* current;
        std::stack<const Node<T>*> stack;
    public:
        const_iterator_inorder(const Node<T>* root);
        const Node<T>& operator*() const;
        const Node<T>* operator->() const;
        const_iterator_inorder& operator++();
        const_iterator_inorder operator++(int);
        bool operator==(const const_iterator_inorder& other) const;
        bool operator!=(const const_iterator_inorder& other) const;
    };

    // BFS iterator
    class iterator_bfs {
    private:
        Node<T>* current;
        std::queue<Node<T>*> queue;
    public:
        iterator_bfs(Node<T>* root);
        Node<T>& operator*() const;
        Node<T>* operator->() const;
        iterator_bfs& operator++();
        iterator_bfs operator++(int);
        bool operator==(const iterator_bfs& other) const;
        bool operator!=(const iterator_bfs& other) const;
    };

    // Const BFS iterator
    class const_iterator_bfs {
    private:
        const Node<T>* current;
        std::queue<const Node<T>*> queue;
    public:
        const_iterator_bfs(const Node<T>* root);
        const Node<T>& operator*() const;
        const Node<T>* operator->() const;
        const_iterator_bfs& operator++();
        const_iterator_bfs operator++(int);
        bool operator==(const const_iterator_bfs& other) const;
        bool operator!=(const const_iterator_bfs& other) const;
    };

    // DFS iterator
    class iterator_dfs {
    private:
        Node<T>* current;
        std::stack<Node<T>*> stack;
    public:
        iterator_dfs(Node<T>* root);
        Node<T>& operator*() const;
        Node<T>* operator->() const;
        iterator_dfs& operator++();
        iterator_dfs operator++(int);
        bool operator==(const iterator_dfs& other) const;
        bool operator!=(const iterator_dfs& other) const;
    };

    // Const DFS iterator
    class const_iterator_dfs {
    private:
        const Node<T>* current;
        std::stack<const Node<T>*> stack;
    public:
        const_iterator_dfs(const Node<T>* root);
        const Node<T>& operator*() const;
        const Node<T>* operator->() const;
        const_iterator_dfs& operator++();
        const_iterator_dfs operator++(int);
        bool operator==(const const_iterator_dfs& other) const;
        bool operator!=(const const_iterator_dfs& other) const;
    };

    // Heap iterator (min-heap for binary tree)
    class iterator_heap {
    private:
        Node<T>* current;
        std::vector<Node<T>*> heap;
        void build_heap(Node<T>* root);
    public:
        iterator_heap(Node<T>* root);
        Node<T>& operator*() const;
        Node<T>* operator->() const;
        iterator_heap& operator++();
        iterator_heap operator++(int);
        bool operator==(const iterator_heap& other) const;
        bool operator!=(const iterator_heap& other) const;
    };

    // Const Heap iterator (min-heap for binary tree)
    class const_iterator_heap {
    private:
        const Node<T>* current;
        std::vector<const Node<T>*> heap;
        void build_heap(const Node<T>* root);
    public:
        const_iterator_heap(const Node<T>* root);
        const Node<T>& operator*() const;
        const Node<T>* operator->() const;
        const_iterator_heap& operator++();
        const_iterator_heap operator++(int);
        bool operator==(const const_iterator_heap& other) const;
        bool operator!=(const const_iterator_heap& other) const;
    };
};

// Definitions in header file for templates
template<typename T>
Node<T>::Node(const T& data) : data(data) {}

// Copy constructor
template<typename T>
Node<T>::Node(const Node<T>& other) : data(other.data) {
    for (const auto& child : other.children) {
        children.push_back(new Node<T>(*child));
    }
}

// Copy assignment operator
template<typename T>
Node<T>& Node<T>::operator=(const Node<T>& other) {
    if (this == &other) return *this; // self-assignment check

    // Clean up existing children
    for (auto& child : children) {
        delete child;
    }
    children.clear();

    // Copy data and children
    data = other.data;
    for (const auto& child : other.children) {
        children.push_back(new Node<T>(*child));
    }

    return *this;
}

// Destructor
template<typename T>
Node<T>::~Node() {
    for (Node<T>* child : children) {
        delete child;
    }
}

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
        this->stack.push(*it);
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
        this->stack.push(*it);
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
        root = (root->children.empty() ? nullptr : root->children.front());
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
        node = node->children[1];
        while (node) {
            this->stack.push(node);
            node = (node->children.empty() ? nullptr : node->children.front());
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
        root = (root->children.empty() ? nullptr : root->children.front());
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
        node = node->children[1];
        while (node) {
            this->stack.push(node);
            node = (node->children.empty() ? nullptr : node->children.front());
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
    if (root == nullptr) {
        current = nullptr;
    } else {
        std::stack<Node<T>*> tmp_stack;
        tmp_stack.push(root);
        while (!tmp_stack.empty()) {
            Node<T>* node = tmp_stack.top();
            tmp_stack.pop();
            stack.push(node);
            for (auto& child : node->children) {
                tmp_stack.push(child);
            }
        }
        current = stack.top();
    }
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
    if (stack.empty()) {
        current = nullptr;
    } else {
        stack.pop();
        current = stack.empty() ? nullptr : stack.top();
    }
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
    if (root == nullptr) {
        current = nullptr;
    } else {
        std::stack<const Node<T>*> tmp_stack;
        tmp_stack.push(root);
        while (!tmp_stack.empty()) {
            const Node<T>* node = tmp_stack.top();
            tmp_stack.pop();
            stack.push(node);
            for (auto& child : node->children) {
                tmp_stack.push(child);
            }
        }
        current = stack.top();
    }
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
    if (stack.empty()) {
        current = nullptr;
    } else {
        stack.pop();
        current = stack.empty() ? nullptr : stack.top();
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
        this->queue.push(child);
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
        this->queue.push(child);
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

// ----- DFS Iterator Definitions -----
template<typename T>
Node<T>::iterator_dfs::iterator_dfs(Node<T>* root) {
    if (root != nullptr) {
        this->stack.push(root);
    }
    current = (this->stack.empty() ? nullptr : this->stack.top());
}

template<typename T>
Node<T>& Node<T>::iterator_dfs::operator*() const {
    return *current;
}

template<typename T>
Node<T>* Node<T>::iterator_dfs::operator->() const {
    return current;
}

template<typename T>
typename Node<T>::iterator_dfs& Node<T>::iterator_dfs::operator++() {
    if (this->stack.empty()) {
        current = nullptr;
        return *this;
    }
    Node<T>* node = this->stack.top();
    this->stack.pop();
    for (auto it = node->children.rbegin(); it != node->children.rend(); ++it) {
        this->stack.push(*it);
    }
    current = (this->stack.empty() ? nullptr : this->stack.top());
    return *this;
}

template<typename T>
typename Node<T>::iterator_dfs Node<T>::iterator_dfs::operator++(int) {
    iterator_dfs tmp(*this);
    ++(*this);
    return tmp;
}

template<typename T>
bool Node<T>::iterator_dfs::operator==(const iterator_dfs& other) const {
    return current == other.current;
}

template<typename T>
bool Node<T>::iterator_dfs::operator!=(const iterator_dfs& other) const {
    return current != other.current;
}

// ----- Const DFS Iterator Definitions -----
template<typename T>
Node<T>::const_iterator_dfs::const_iterator_dfs(const Node<T>* root) {
    if (root != nullptr) {
        this->stack.push(root);
    }
    current = (this->stack.empty() ? nullptr : this->stack.top());
}

template<typename T>
const Node<T>& Node<T>::const_iterator_dfs::operator*() const {
    return *current;
}

template<typename T>
const Node<T>* Node<T>::const_iterator_dfs::operator->() const {
    return current;
}

template<typename T>
typename Node<T>::const_iterator_dfs& Node<T>::const_iterator_dfs::operator++() {
    if (this->stack.empty()) {
        current = nullptr;
        return *this;
    }
    const Node<T>* node = this->stack.top();
    this->stack.pop();
    for (auto it = node->children.rbegin(); it != node->children.rend(); ++it) {
        this->stack.push(*it);
    }
    current = (this->stack.empty() ? nullptr : this->stack.top());
    return *this;
}

template<typename T>
typename Node<T>::const_iterator_dfs Node<T>::const_iterator_dfs::operator++(int) {
    const_iterator_dfs tmp(*this);
    ++(*this);
    return tmp;
}

template<typename T>
bool Node<T>::const_iterator_dfs::operator==(const const_iterator_dfs& other) const {
    return current == other.current;
}

template<typename T>
bool Node<T>::const_iterator_dfs::operator!=(const const_iterator_dfs& other) const {
    return current != other.current;
}

// ----- Heap Iterator Definitions -----
template<typename T>
Node<T>::iterator_heap::iterator_heap(Node<T>* root) : current(nullptr) {
    build_heap(root);
}

template<typename T>
void Node<T>::iterator_heap::build_heap(Node<T>* root) {
    if (root == nullptr) return;
    heap.push_back(root);
    for (Node<T>* child : root->children) {
        build_heap(child);
    }
    std::make_heap(heap.begin(), heap.end(), [](Node<T>* a, Node<T>* b) { return a->data > b->data; });
}

template<typename T>
Node<T>& Node<T>::iterator_heap::operator*() const {
    return *current;
}

template<typename T>
Node<T>* Node<T>::iterator_heap::operator->() const {
    return current;
}

template<typename T>
typename Node<T>::iterator_heap& Node<T>::iterator_heap::operator++() {
    if (heap.empty()) {
        current = nullptr;
        return *this;
    }
    std::pop_heap(heap.begin(), heap.end(), [](Node<T>* a, Node<T>* b) { return a->data > b->data; });
    current = heap.back();
    heap.pop_back();
    return *this;
}

template<typename T>
typename Node<T>::iterator_heap Node<T>::iterator_heap::operator++(int) {
    iterator_heap tmp(*this);
    ++(*this);
    return tmp;
}

template<typename T>
bool Node<T>::iterator_heap::operator==(const iterator_heap& other) const {
    return current == other.current;
}

template<typename T>
bool Node<T>::iterator_heap::operator!=(const iterator_heap& other) const {
    return current != other.current;
}

// ----- Const Heap Iterator Definitions -----
template<typename T>
Node<T>::const_iterator_heap::const_iterator_heap(const Node<T>* root) : current(nullptr) {
    build_heap(root);
}

template<typename T>
void Node<T>::const_iterator_heap::build_heap(const Node<T>* root) {
    if (root == nullptr) return;
    heap.push_back(root);
    for (const Node<T>* child : root->children) {
        build_heap(child);
    }
    std::make_heap(heap.begin(), heap.end(), [](const Node<T>* a, const Node<T>* b) { return a->data > b->data; });
}

template<typename T>
const Node<T>& Node<T>::const_iterator_heap::operator*() const {
    return *current;
}

template<typename T>
const Node<T>* Node<T>::const_iterator_heap::operator->() const {
    return current;
}

template<typename T>
typename Node<T>::const_iterator_heap& Node<T>::const_iterator_heap::operator++() {
    if (heap.empty()) {
        current = nullptr;
        return *this;
    }
    std::pop_heap(heap.begin(), heap.end(), [](const Node<T>* a, const Node<T>* b) { return a->data > b->data; });
    current = heap.back();
    heap.pop_back();
    return *this;
}

template<typename T>
typename Node<T>::const_iterator_heap Node<T>::const_iterator_heap::operator++(int) {
    const_iterator_heap tmp(*this);
    ++(*this);
    return tmp;
}

template<typename T>
bool Node<T>::const_iterator_heap::operator==(const const_iterator_heap& other) const {
    return current == other.current;
}

template<typename T>
bool Node<T>::const_iterator_heap::operator!=(const const_iterator_heap& other) const {
    return current != other.current;
}

// Explicit template instantiation for types
template class Node<int>;
template class Node<double>;
template class Node<std::string>;

/*
// Explicit template instantiation for iterator_heap
template class Node<int>::iterator_heap;
template class Node<double>::iterator_heap;
template class Node<std::string>::iterator_heap;
*/

#endif // NODE_HPP