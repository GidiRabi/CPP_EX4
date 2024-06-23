#ifndef TREE_HPP
#define TREE_HPP

#include "Node.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <type_traits>
#include <string>

using namespace std;


template<typename T, int K = 2>
class Tree {
private:
    Node<T>* root;

public:
    Tree();
    ~Tree();
    
    void add_root(Node<T>& node);
    void add_sub_node(Node<T>& parent, Node<T>& child);
	Node<T>* getRoot() const { return root; }

    // Pre-order traversal
    typename Node<T>::iterator_preorder begin_pre_order();
    typename Node<T>::iterator_preorder end_pre_order();
    typename Node<T>::const_iterator_preorder cbegin_pre_order() const;
    typename Node<T>::const_iterator_preorder cend_pre_order() const;

    // In-order traversal
    typename Node<T>::iterator_inorder begin_in_order();
    typename Node<T>::iterator_inorder end_in_order();
    typename Node<T>::const_iterator_inorder cbegin_in_order() const;
    typename Node<T>::const_iterator_inorder cend_in_order() const;

    // Post-order traversal
    typename Node<T>::iterator_postorder begin_post_order();
    typename Node<T>::iterator_postorder end_post_order();
    typename Node<T>::const_iterator_postorder cbegin_post_order() const;
    typename Node<T>::const_iterator_postorder cend_post_order() const;

    // BFS traversal
    typename Node<T>::iterator_bfs begin_bfs_scan();
    typename Node<T>::iterator_bfs end_bfs_scan();
    typename Node<T>::const_iterator_bfs cbegin_bfs_scan() const;
    typename Node<T>::const_iterator_bfs cend_bfs_scan() const;

    // DFS traversal
    typename Node<T>::iterator_dfs begin_dfs_scan();
    typename Node<T>::iterator_dfs end_dfs_scan();
    typename Node<T>::const_iterator_dfs cbegin_dfs_scan() const;
    typename Node<T>::const_iterator_dfs cend_dfs_scan() const;

    // Heap (Min-Heap) traversal
    typename Node<T>::iterator_heap myHeap();

    // Print tree
    template<typename U, int M>
    friend ostream& operator<<(ostream& os, const Tree<U, M>& tree);
};


// The implementation of the Tree class is in the header file (Tree.hpp)
// because template definitions must be included in the header file.
// This ensures the compiler can see the full definition whenever the template is instantiated.
// Templates cannot be separated into a .cpp file because the linker won't be able to find the definitions.


// Constructor
template<typename T, int K>
Tree<T, K>::Tree() : root(nullptr) {}

// Destructor
template<typename T, int K>
Tree<T, K>::~Tree() {
    delete root;
}

// Add root node
template<typename T, int K>
void Tree<T, K>::add_root(Node<T>& node) {
    delete root;  // Delete existing root if any
    root = new Node<T>(node.get_value());  // Create new root with same value
}

// Add child node to a parent node
template<typename T, int K>
void Tree<T, K>::add_sub_node(Node<T>& parent, Node<T>& child) {
    Node<T>* new_child = new Node<T>(child.get_value());
    parent.children.push_back(new_child);
}

// Pre-order traversal
template<typename T, int K>
typename Node<T>::iterator_preorder Tree<T, K>::begin_pre_order() {
    return typename Node<T>::iterator_preorder(root);
}

template<typename T, int K>
typename Node<T>::iterator_preorder Tree<T, K>::end_pre_order() {
    return typename Node<T>::iterator_preorder(nullptr);
}

template<typename T, int K>
typename Node<T>::const_iterator_preorder Tree<T, K>::cbegin_pre_order() const {
    return typename Node<T>::const_iterator_preorder(root);
}

template<typename T, int K>
typename Node<T>::const_iterator_preorder Tree<T, K>::cend_pre_order() const {
    return typename Node<T>::const_iterator_preorder(nullptr);
}

// In-order traversal
template<typename T, int K>
typename Node<T>::iterator_inorder Tree<T, K>::begin_in_order() {
    return typename Node<T>::iterator_inorder(root);
}

template<typename T, int K>
typename Node<T>::iterator_inorder Tree<T, K>::end_in_order() {
    return typename Node<T>::iterator_inorder(nullptr);
}

template<typename T, int K>
typename Node<T>::const_iterator_inorder Tree<T, K>::cbegin_in_order() const {
    return typename Node<T>::const_iterator_inorder(root);
}

template<typename T, int K>
typename Node<T>::const_iterator_inorder Tree<T, K>::cend_in_order() const {
    return typename Node<T>::const_iterator_inorder(nullptr);
}

// Post-order traversal
template<typename T, int K>
typename Node<T>::iterator_postorder Tree<T, K>::begin_post_order() {
    return typename Node<T>::iterator_postorder(root);
}

template<typename T, int K>
typename Node<T>::iterator_postorder Tree<T, K>::end_post_order() {
    return typename Node<T>::iterator_postorder(nullptr);
}

template<typename T, int K>
typename Node<T>::const_iterator_postorder Tree<T, K>::cbegin_post_order() const {
    return typename Node<T>::const_iterator_postorder(root);
}

template<typename T, int K>
typename Node<T>::const_iterator_postorder Tree<T, K>::cend_post_order() const {
    return typename Node<T>::const_iterator_postorder(nullptr);
}

// BFS traversal
template<typename T, int K>
typename Node<T>::iterator_bfs Tree<T, K>::begin_bfs_scan() {
    return typename Node<T>::iterator_bfs(root);
}

template<typename T, int K>
typename Node<T>::iterator_bfs Tree<T, K>::end_bfs_scan() {
    return typename Node<T>::iterator_bfs(nullptr);
}

template<typename T, int K>
typename Node<T>::const_iterator_bfs Tree<T, K>::cbegin_bfs_scan() const {
    return typename Node<T>::const_iterator_bfs(root);
}

template<typename T, int K>
typename Node<T>::const_iterator_bfs Tree<T, K>::cend_bfs_scan() const {
    return typename Node<T>::const_iterator_bfs(nullptr);
}

// DFS traversal
template<typename T, int K>
typename Node<T>::iterator_dfs Tree<T, K>::begin_dfs_scan() {
    return typename Node<T>::iterator_dfs(root);
}

template<typename T, int K>
typename Node<T>::iterator_dfs Tree<T, K>::end_dfs_scan() {
    return typename Node<T>::iterator_dfs(nullptr);
}

template<typename T, int K>
typename Node<T>::const_iterator_dfs Tree<T, K>::cbegin_dfs_scan() const {
    return typename Node<T>::const_iterator_dfs(root);
}

template<typename T, int K>
typename Node<T>::const_iterator_dfs Tree<T, K>::cend_dfs_scan() const {
    return typename Node<T>::const_iterator_dfs(nullptr);
}

// Heap (Min-Heap) traversal
template<typename T, int K>
typename Node<T>::iterator_heap Tree<T, K>::myHeap() {
    return typename Node<T>::iterator_heap(root);
}

template<typename T, int K>
void drawTree(sf::RenderWindow& window, const Node<T>* node, int x, int y, int horizontalSpacing, int level = 0) {
    if (!node) return;

    horizontalSpacing /= 2;
    const int radius = 20;
    sf::CircleShape circle(radius);
    circle.setPosition(x - radius, y - radius);
    circle.setFillColor(sf::Color::Green);

    sf::Font font;
    if (!font.loadFromFile("Arial.ttf")) {
        std::cerr << "Could not load font\n";
        return;
    }

    sf::Text text;
    text.setFont(font);
    // Use if constexpr to check if the type T is std::string and handle accordingly
    if constexpr (std::is_same_v<T, std::string>) {
        text.setString(node->get_value()); // Directly use the string
    } else {
        text.setString(std::to_string(node->get_value())); // Convert numeric value to string
    }
    text.setCharacterSize(15);
    text.setFillColor(sf::Color::White);
    text.setPosition(x - radius / 2, y - radius / 2);

    int childX = x - horizontalSpacing;
    for (const auto& child : node->children) {
        if (child) {
            sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(x, y + radius)),
                sf::Vertex(sf::Vector2f(childX, y + 100 - radius))
            };
            window.draw(line, 2, sf::Lines);
            drawTree<T, K>(window, child, childX, y + 100, horizontalSpacing, level + 1);
            childX += horizontalSpacing * 2;
        }
    }
    window.draw(circle);
    window.draw(text);
}

template<typename T, int K>
ostream& operator<<(ostream& os, const Tree<T, K>& tree) {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Tree Visualization");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        // Explicitly pass template arguments
        drawTree<T, K>(window, tree.getRoot(), 400, 50, 300);
        window.display();
    }
    return os;
}

// Explicit template instantiation
template class Tree<int>;
template class Tree<double>;
template class Tree<string>;
template ostream& operator<< <>(ostream& os, const Tree<int>& tree);
template ostream& operator<< <>(ostream& os, const Tree<double>& tree);
template ostream& operator<< <>(ostream& os, const Tree<string>& tree);

#endif // TREE_HPP
