#include <iostream>
#include <string>
#include "Node.hpp"
#include "Tree.hpp"
#include "Complex.hpp"

using namespace std;

int main()
{

    Node<string> root_node_str("root");
    Tree<string> tree_str; // Binary tree that contains strings.
    tree_str.add_root(root_node_str);
    Node<string> n1_str("left");
    Node<string> n2_str("right");
    Node<string> n3_str("left-left");
    Node<string> n4_str("left-right");
    Node<string> n5_str("right-left");

    tree_str.add_sub_node(root_node_str, n1_str);
    tree_str.add_sub_node(root_node_str, n2_str);
    tree_str.add_sub_node(n1_str, n3_str);
    tree_str.add_sub_node(n1_str, n4_str);
    tree_str.add_sub_node(n2_str, n5_str);

    cout << "Pre-order traversal: \n";
    for (auto node = tree_str.begin_pre_order(); node != tree_str.end_pre_order(); ++node)
    {
        cout << node->get_value() << ", ";
    }
    cout << endl;

    cout << "Post-order traversal: \n";
    for (auto node = tree_str.begin_post_order(); node != tree_str.end_post_order(); ++node)
    {
        cout << node->get_value() << ", ";
    }
    cout << endl;

    cout << "In-order traversal: \n";
    for (auto node = tree_str.begin_in_order(); node != tree_str.end_in_order(); ++node)
    {
        cout << node->get_value() << ", ";
    }
    cout << endl;

    cout << "BFS traversal: \n";
    for (auto node = tree_str.begin_bfs(); node != tree_str.end_bfs(); ++node)
    {
        cout << node->get_value() << ", ";
    }
    cout << endl;

    cout << "DFS traversal: \n";
    for (auto node = tree_str.begin_dfs(); node != tree_str.end_dfs(); ++node)
    {
        cout << node->get_value() << ", ";
    }
    cout << endl;

    cout << "Heap traversal: \n";
    for (auto node = tree_str.begin_heap(); node != tree_str.end_heap(); ++node)
    {
        cout << node->get_value() << ", ";
    }
    cout << endl;

    cout << "(BFS) traversal: \n";
    for (auto node : tree_str)
    {
        cout << node.get_value() << ", ";
    }
    cout << endl;

    cout << tree_str << endl; // Should print the graph using GUI.

    Tree<string, 3> three_ary_tree_str; // 3-ary tree.
    root_node_str = Node<string>("new_root");
    three_ary_tree_str.add_root(root_node_str);
    three_ary_tree_str.add_sub_node(root_node_str, n1_str);
    three_ary_tree_str.add_sub_node(root_node_str, n2_str);
    three_ary_tree_str.add_sub_node(root_node_str, n3_str);
    three_ary_tree_str.add_sub_node(n1_str, n4_str);
    three_ary_tree_str.add_sub_node(n2_str, n5_str);

    cout << three_ary_tree_str << endl; // Should print the graph using GUI.

    // Demo with ComplexNumber
    cout << "ComplexNumber Tree Demo:\n";

    ComplexNumber root_num(1.1, 2.2);
    Node<ComplexNumber> root_node_complex(root_num);
    Tree<ComplexNumber> tree_complex; // Binary tree that contains complex numbers.
    tree_complex.add_root(root_node_complex);
    ComplexNumber n1_complex(3.3, 4.4);
    ComplexNumber n2_complex(5.5, 6.6);
    ComplexNumber n3_complex(7.7, 8.8);
    ComplexNumber n4_complex(9.9, 10.10);
    ComplexNumber n5_complex(11.11, 12.12);
    Node<ComplexNumber> n1_node(n1_complex);
    Node<ComplexNumber> n2_node(n2_complex);
    Node<ComplexNumber> n3_node(n3_complex);
    Node<ComplexNumber> n4_node(n4_complex);
    Node<ComplexNumber> n5_node(n5_complex);

    tree_complex.add_sub_node(root_node_complex, n1_node);
    tree_complex.add_sub_node(root_node_complex, n2_node);
    tree_complex.add_sub_node(n1_node, n3_node);
    tree_complex.add_sub_node(n1_node, n4_node);
    tree_complex.add_sub_node(n2_node, n5_node);

    cout << "Pre-order traversal: \n";
    for (auto node = tree_complex.begin_pre_order(); node != tree_complex.end_pre_order(); ++node)
    {
        cout << node->get_value() << ", ";
    }
    cout << endl;

    cout << "Post-order traversal: \n";
    for (auto node = tree_complex.begin_post_order(); node != tree_complex.end_post_order(); ++node)
    {
        cout << node->get_value() << ", ";
    }
    cout << endl;

    cout << "In-order traversal: \n";
    for (auto node = tree_complex.begin_in_order(); node != tree_complex.end_in_order(); ++node)
    {
        cout << node->get_value() << ", ";
    }
    cout << endl;

    cout << "BFS traversal: \n";
    for (auto node = tree_complex.begin_bfs(); node != tree_complex.end_bfs(); ++node)
    {
        cout << node->get_value() << ", ";
    }
    cout << endl;

    cout << "DFS traversal: \n";
    for (auto node = tree_complex.begin_dfs(); node != tree_complex.end_dfs(); ++node)
    {
        cout << node->get_value() << ", ";
    }
    cout << endl;

    cout << "Heap traversal: \n";
    for (auto node = tree_complex.begin_heap(); node != tree_complex.end_heap(); ++node)
    {
        cout << node->get_value() << ", ";
    }
    cout << endl;

    cout << "(BFS) traversal: \n";
    for (auto node : tree_complex)
    {
        cout << node.get_value() << ", ";
    }
    cout << endl;

    cout << tree_complex << endl; // Should print the graph using GUI.

    Tree<ComplexNumber, 3> three_ary_tree_complex; // 3-ary tree.
    root_num = ComplexNumber(17.17, 18.18);
    Node<ComplexNumber> root_node_complex_new(root_num);
    three_ary_tree_complex.add_root(root_node_complex_new);
    three_ary_tree_complex.add_sub_node(root_node_complex_new, n1_node);
    three_ary_tree_complex.add_sub_node(root_node_complex_new, n2_node);
    three_ary_tree_complex.add_sub_node(root_node_complex_new, n3_node);
    three_ary_tree_complex.add_sub_node(n1_node, n4_node);
    three_ary_tree_complex.add_sub_node(n2_node, n5_node);

    cout << three_ary_tree_complex << endl; // Should print the graph using GUI.

    return 0;
}
