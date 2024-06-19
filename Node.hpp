#ifndef NODE_HPP
#define NODE_HPP

#include <vector>
#include <memory>

template<typename T>
class Node {
public:
    T data;
    std::vector<std::unique_ptr<Node<T>>> children;

    explicit Node(const T& data) : data(data) {}
    Node(const Node& other) = delete; // Non-copyable
    Node& operator=(const Node& other) = delete; // Non-assignable
	~Node();

    // PreOrder iterator
    class iterator_preorder {
    private:
        Node<T>* current;

    public:
        explicit iterator_preorder(Node<T>* root);
        T& operator*() const;
        T* operator->() const;
        iterator_preorder& operator++();
        iterator_preorder operator++(int);
        bool operator==(const iterator_preorder& other) const;
        bool operator!=(const iterator_preorder& other) const;
    };

    // Const PreOrder iterator
    class const_iterator_preorder {
    private:
        const Node<T>* current;

    public:
        explicit const_iterator_preorder(const Node<T>* root);
        const T& operator*() const;
        const T* operator->() const;
        const_iterator_preorder& operator++();
        const_iterator_preorder operator++(int);
        bool operator==(const const_iterator_preorder& other) const;
        bool operator!=(const const_iterator_preorder& other) const;
    };

    // PostOrder iterator
    class iterator_postorder {
    private:
        Node<T>* current;

    public:
        explicit iterator_postorder(Node<T>* root);
        T& operator*() const;
        T* operator->() const;
        iterator_postorder& operator++();
        iterator_postorder operator++(int);
        bool operator==(const iterator_postorder& other) const;
        bool operator!=(const iterator_postorder& other) const;
    };

    // Const PostOrder iterator
    class const_iterator_postorder {
    private:
        const Node<T>* current;

    public:
        explicit const_iterator_postorder(const Node<T>* root);
        const T& operator*() const;
        const T* operator->() const;
        const_iterator_postorder& operator++();
        const_iterator_postorder operator++(int);
        bool operator==(const const_iterator_postorder& other) const;
        bool operator!=(const const_iterator_postorder& other) const;
    };

    // InOrder iterator
    class iterator_inorder {
    private:
        Node<T>* current;

    public:
        explicit iterator_inorder(Node<T>* root);
        T& operator*() const;
        T* operator->() const;
        iterator_inorder& operator++();
        iterator_inorder operator++(int);
        bool operator==(const iterator_inorder& other) const;
        bool operator!=(const iterator_inorder& other) const;
    };

    // Const InOrder iterator
    class const_iterator_inorder {
    private:
        const Node<T>* current;

    public:
        explicit const_iterator_inorder(const Node<T>* root);
        const T& operator*() const;
        const T* operator->() const;
        const_iterator_inorder& operator++();
        const_iterator_inorder operator++(int);
        bool operator==(const const_iterator_inorder& other) const;
        bool operator!=(const const_iterator_inorder& other) const;
    };

    // BFS iterator
    class iterator_bfs {
    private:
        Node<T>* current;

    public:
        explicit iterator_bfs(Node<T>* root);
        T& operator*() const;
        T* operator->() const;
        iterator_bfs& operator++();
        iterator_bfs operator++(int);
        bool operator==(const iterator_bfs& other) const;
        bool operator!=(const iterator_bfs& other) const;
    };

    // Const BFS iterator
    class const_iterator_bfs {
    private:
        const Node<T>* current;

    public:
        explicit const_iterator_bfs(const Node<T>* root);
        const T& operator*() const;
        const T* operator->() const;
        const_iterator_bfs& operator++();
        const_iterator_bfs operator++(int);
        bool operator==(const const_iterator_bfs& other) const;
        bool operator!=(const const_iterator_bfs& other) const;
    };
};

#endif // NODE_HPP
