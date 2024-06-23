#ifndef NODE_HPP
#define NODE_HPP

#include <vector>
#include <stack>
#include <queue>

template<typename T>
class Node {
public:
    T data;  // Publicly accessible data
    std::vector<Node<T>*> children;  // Use raw pointers for children

    explicit Node(const T& data);
    Node(const Node& other) = delete;  // Non-copyable
    Node& operator=(const Node& other) = delete;  // Non-assignable
    ~Node();

    T get_value() const;  // Accessor for node data

    // PreOrder iterator
    class iterator_preorder {
    private:
        Node<T>* current;
        std::stack<Node<T>*> stack;  // Declare stack here
    public:
        explicit iterator_preorder(Node<T>* root);
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
        std::stack<const Node<T>*> stack;  // Declare stack here
    public:
        explicit const_iterator_preorder(const Node<T>* root);
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
        std::stack<Node<T>*> stack;  // Declare stack here
    public:
        explicit iterator_postorder(Node<T>* root);
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
        std::stack<const Node<T>*> stack;  // Declare stack here
    public:
        explicit const_iterator_postorder(const Node<T>* root);
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
        std::stack<Node<T>*> stack;  // Declare stack here
    public:
        explicit iterator_inorder(Node<T>* root);
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
        std::stack<const Node<T>*> stack;  // Declare stack here
    public:
        explicit const_iterator_inorder(const Node<T>* root);
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
        void advance();
        std::queue<Node<T>*> queue;  // Use a queue to store pointers to nodes
    public:
        explicit iterator_bfs(Node<T>* root);
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
        std::queue<const Node<T>*> queue;  // Declare queue here
    public:
        explicit const_iterator_bfs(const Node<T>* root);
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
        std::stack<Node<T>*> stack;  // Declare stack here
    public:
        explicit iterator_dfs(Node<T>* root);
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
        std::stack<const Node<T>*> stack;  // Declare stack here
    public:
        explicit const_iterator_dfs(const Node<T>* root);
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
        std::vector<Node<T>*> heap;  // Vector to store the heap nodes
        void build_heap(Node<T>* root); // Helper function to build the heap
    public:
        explicit iterator_heap(Node<T>* root);
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
        std::vector<const Node<T>*> heap;  // Vector to store the heap nodes
        void build_heap(const Node<T>* root); // Helper function to build the heap
    public:
        explicit const_iterator_heap(const Node<T>* root);
        const Node<T>& operator*() const;
        const Node<T>* operator->() const;
        const_iterator_heap& operator++();
        const_iterator_heap operator++(int);
        bool operator==(const const_iterator_heap& other) const;
        bool operator!=(const const_iterator_heap& other) const;
    };
};

#endif // NODE_HPP
