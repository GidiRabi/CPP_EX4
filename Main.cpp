// 325483444 gidirabi111@gmail.com
#include <iostream>
#include <string>
#include "Node.hpp"
#include "Tree.hpp"

using namespace std;

int main() {
    Node<double> root_node = Node(-0.5);
    Tree<double> tree; // Binary tree that contains doubles.
    tree.add_root(root_node);
    Node<double> n1 = Node(2.1);
    Node<double> n2 = Node(-3.3);
    Node<double> n3 = Node(4.4);
    Node<double> n4 = Node(-5.5);
    Node<double> n5 = Node(6.6);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);
   
    // The tree should look like:
    /**
     *       root = -0.5
     *     /       \
     *    2.1     -3.3
     *   /  \      /
     *  4.4 -5.5  6.6
     */

	cout << "Pre-order traversal, should print -0.5, 2.1, 4.4, -5.5, -3.3, 6.6: \n";
    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node) {
        cout << node->get_value() << endl;
    } // prints: -0.5, 2.1, 4.4, -5.5, -3.3, 6.6

	cout << "Post-order traversal, should print 4.4, -5.5, 2.1, 6.6, -3.3, -0.5: \n";
    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node) {
        cout << node->get_value() << endl;
    } // prints: 4.4, -5.5, 2.1, 6.6, -3.3, -0.5

	cout << "In-order traversal, should print 4.4, 2.1, -5.5, -0.5, 6.6, -3.3: \n";
    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node) {
        cout << node->get_value() << endl;
    } // prints: 4.4, 2.1, -5.5, -0.5, 6.6, -3.3

	cout << "BFS traversal, should print -0.5, 2.1, -3.3, 4.4, -5.5, 6.6: \n";
    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node) {
        cout << node->get_value() << endl;
    } // prints: -0.5, 2.1, -3.3, 4.4, -5.5, 6.6

	cout << "DFS traversal, should print -0.5, 2.1, 4.4, -5.5, -3.3, 6.6: \n";
    for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node) {
        cout << node->get_value() << endl;
    } // prints: -0.5, 2.1, 4.4, -5.5, -3.3, 6.6

    cout << tree << endl; // Should print the graph using GUI.

    Tree<double,3> three_ary_tree; // 3-ary tree.
    three_ary_tree.add_root(root_node);
    three_ary_tree.add_sub_node(root_node, n1);
    three_ary_tree.add_sub_node(root_node, n2);
    three_ary_tree.add_sub_node(root_node, n3);
    three_ary_tree.add_sub_node(n1, n4);
    three_ary_tree.add_sub_node(n2, n5);

	cout << three_ary_tree << endl; // Should print the graph using GUI.

    // The tree should look like:
    /**
     *       root = -0.5
     *     /      |     \
     *    2.1   -3.3    4.4
     *   /        |
     * -5.5      6.6
     */
}
