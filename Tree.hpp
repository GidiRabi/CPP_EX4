// 325483444 gidirabi111@gmail.com
#ifndef TREE_HPP
#define TREE_HPP

#include "Node.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <type_traits>
#include <string>
#include <iomanip>
#include <sstream>
#include <queue>
#include <functional>
#include <cmath>

using namespace std;


template<typename T, int K = 2>
class Tree {
private:
    Node<T>* root;

public:
    Tree();
	Tree(Node<T>* key);
    ~Tree();
    
    void add_root(Node<T>& node);
    void add_sub_node(Node<T>& parent, Node<T>& child);
	Node<T>* getRoot() const { return root; }

	// begin and end functions for range-based for loop
    typename Node<T>::iterator_bfs begin();
    typename Node<T>::iterator_bfs end();

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
    typename Node<T>::iterator_bfs begin_bfs();
    typename Node<T>::iterator_bfs end_bfs();
    typename Node<T>::const_iterator_bfs cbegin_bfs() const;
    typename Node<T>::const_iterator_bfs cend_bfs() const;

    // DFS traversal
    typename Node<T>::iterator_dfs begin_dfs();
    typename Node<T>::iterator_dfs end_dfs();
    typename Node<T>::const_iterator_dfs cbegin_dfs() const;
    typename Node<T>::const_iterator_dfs cend_dfs() const;

    // Heap (Min-Heap) traversal
    typename Node<T>::iterator_heap begin_heap();
    typename Node<T>::iterator_heap end_heap();
    typename Node<T>::const_iterator_heap cbegin_heap() const;
    typename Node<T>::const_iterator_heap cend_heap() const;


    // Print tree
    template<typename U, int M>
    friend ostream& operator<<(ostream& os, const Tree<U, M>& tree);
};


// The implementation of the Tree class is in the header file (Tree.hpp)
// because template definitions must be included in the header file.
// This ensures the compiler can see the full definition whenever the template is instantiated.
// Templates cannot be separated into a .cpp file because the linker won't be able to find the definitions.


// Constructors
template<typename T, int K>
Tree<T, K>::Tree() : root(nullptr) {}

template<typename T, int K>
Tree<T, K>::Tree(Node<T>* key) : root(key) {}

// Destructor
template<typename T, int K>
Tree<T, K>::~Tree() {
   std::function<void(Node<T>*)> del_node = [&](Node<T>* node) {
        if (node) {
            for (auto& child : node->children) {
                del_node(child);
            }
            node->children.clear();
        }
    };
    del_node(root);
    root = nullptr;
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
	queue<Node<T>*> q;
	q.push(root);
	while (!q.empty()) {
		auto node = q.front();
		q.pop();
		if (node->get_value() == parent.get_value()) {
			if (node->children.size() < K) {
				node->children.push_back(new Node<T>(child.get_value()));
				return;
			}
		}
		for (auto& child : node->children) {
			q.push(child);
		}
	}
}


// Implementations of the begin and end functions
template<typename T, int K>
typename Node<T>::iterator_bfs Tree<T, K>::begin() {
    return typename Node<T>::iterator_bfs(root);
}

template<typename T, int K>
typename Node<T>::iterator_bfs Tree<T, K>::end() {
    return typename Node<T>::iterator_bfs(nullptr);
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
typename Node<T>::iterator_bfs Tree<T, K>::begin_bfs() {
    return typename Node<T>::iterator_bfs(root);
}

template<typename T, int K>
typename Node<T>::iterator_bfs Tree<T, K>::end_bfs() {
    return typename Node<T>::iterator_bfs(nullptr);
}

template<typename T, int K>
typename Node<T>::const_iterator_bfs Tree<T, K>::cbegin_bfs() const {
    return typename Node<T>::const_iterator_bfs(root);
}

template<typename T, int K>
typename Node<T>::const_iterator_bfs Tree<T, K>::cend_bfs() const {
    return typename Node<T>::const_iterator_bfs(nullptr);
}

// DFS traversal
template<typename T, int K>
typename Node<T>::iterator_dfs Tree<T, K>::begin_dfs() {
    return typename Node<T>::iterator_dfs(root);
}

template<typename T, int K>
typename Node<T>::iterator_dfs Tree<T, K>::end_dfs() {
    return typename Node<T>::iterator_dfs(nullptr);
}

template<typename T, int K>
typename Node<T>::const_iterator_dfs Tree<T, K>::cbegin_dfs() const {
    return typename Node<T>::const_iterator_dfs(root);
}

template<typename T, int K>
typename Node<T>::const_iterator_dfs Tree<T, K>::cend_dfs() const {
    return typename Node<T>::const_iterator_dfs(nullptr);
}

// Heap (Min-Heap) traversal
template<typename T, int K>
typename Node<T>::iterator_heap Tree<T, K>::begin_heap() {
    return typename Node<T>::iterator_heap(root);
}

template<typename T, int K>
typename Node<T>::iterator_heap Tree<T, K>::end_heap() {
    return typename Node<T>::iterator_heap(nullptr);
}

template<typename T, int K>
typename Node<T>::const_iterator_heap Tree<T, K>::cbegin_heap() const {
    return typename Node<T>::const_iterator_heap(root);
}

template<typename T, int K>
typename Node<T>::const_iterator_heap Tree<T, K>::cend_heap() const {
    return typename Node<T>::const_iterator_heap(nullptr);
}

template<typename T>
int getTreeWidth(const Node<T>* node) {
    if (!node) return 0;
    int width = 0;
    for (const auto& child : node->children) {
        width += getTreeWidth(child);
    }
    return std::max(1, width);
}

template<typename T, int K>
void drawTree(sf::RenderWindow& window, const Node<T>* node, int x, int y, int totalWidth) {
    if (!node) return;

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
    text.setCharacterSize(15);
    text.setFillColor(sf::Color::White);
    text.setPosition(x - radius / 2, y - radius / 2);

    std::ostringstream stream;
    if constexpr (std::is_floating_point<T>::value) {
        stream << std::fixed << std::setprecision(2) << node->get_value();
    } else {
        stream << node->get_value();
    }
    text.setString(stream.str());

    int childX = x - totalWidth / 2;

    for (const auto& child : node->children) {
        if (child) {
            int subtreeWidth = getTreeWidth(child) * (800 / (K + 1));
            int childPosX = childX + subtreeWidth / 2;

            sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(x, y + radius)),
                sf::Vertex(sf::Vector2f(childPosX, y + 100 - radius))
            };
            window.draw(line, 2, sf::Lines);
            drawTree<T, K>(window, child, childPosX, y + 100, subtreeWidth);
            childX += subtreeWidth;
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
        drawTree<T, K>(window, tree.getRoot(), 400, 50, 800);
        window.display();
    }

    return os;
}

// Explicit template instantiation
// template class Tree<int>;
// template class Tree<double>;
// template class Tree<string>;
// template ostream& operator<< <>(ostream& os, const Tree<int>& tree);
// template ostream& operator<< <>(ostream& os, const Tree<double>& tree);
// template ostream& operator<< <>(ostream& os, const Tree<string>& tree);

#endif // TREE_HPP
