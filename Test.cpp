// 325483444 gidirabi111@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Node.hpp"
#include "Tree.hpp"

using namespace std;

TEST_CASE("Test adding root node") {
    Node<int> root_node(42);
    Tree<int> tree;
    tree.add_root(root_node);
    CHECK(tree.begin_bfs_scan()->get_value() == 42);
}

TEST_CASE("Test adding child nodes") {
    Node<int> root_node(13);
    Tree<int> tree;
    tree.add_root(root_node);
    Node<int> n1(-7);
    Node<int> n2(29);
    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    auto it = tree.begin_bfs_scan();
    CHECK(it->get_value() == 13);
    ++it;
    CHECK(it->get_value() == -7);
    ++it;
    CHECK(it->get_value() == 29);
}

TEST_CASE("Test pre-order traversal") {
    Node<double> root_node(3.14);
    Tree<double> tree;
    tree.add_root(root_node);
    Node<double> n1(-2.71);
    Node<double> n2(1.618);
    Node<double> n3(0.007);
    Node<double> n4(42.42);
    Node<double> n5(-99.99);
    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    vector<double> values;
    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node) {
        values.push_back(node->get_value());
    }

    CHECK(values == vector<double>{3.14, -2.71, 0.007, 42.42, 1.618, -99.99});
}

TEST_CASE("Test post-order traversal") {
    Node<double> root_node(6.28);
    Tree<double> tree;
    tree.add_root(root_node);
    Node<double> n1(1.41);
    Node<double> n2(-3.33);
    Node<double> n3(2.718);
    Node<double> n4(-1.23);
    Node<double> n5(0.618);
    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    vector<double> values;
    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node) {
        values.push_back(node->get_value());
    }

    CHECK(values == vector<double>{2.718, -1.23, 1.41, 0.618, -3.33, 6.28});
}

TEST_CASE("Test in-order traversal") {
    Node<double> root_node(-1.0);
    Tree<double> tree;
    tree.add_root(root_node);
    Node<double> n1(3.33);
    Node<double> n2(4.44);
    Node<double> n3(5.55);
    Node<double> n4(6.66);
    Node<double> n5(-7.77);
    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    vector<double> values;
    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node) {
        values.push_back(node->get_value());
    }

    CHECK(values == vector<double>{5.55, 3.33, 6.66, -1.0, -7.77, 4.44});
}

TEST_CASE("Test BFS traversal") {
    Node<int> root_node(100);
    Tree<int> tree;
    tree.add_root(root_node);
    Node<int> n1(50);
    Node<int> n2(-50);
    Node<int> n3(75);
    Node<int> n4(-75);
    Node<int> n5(25);
    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    vector<int> values;
    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node) {
        values.push_back(node->get_value());
    }

    CHECK(values == vector<int>{100, 50, -50, 75, -75, 25});
}

TEST_CASE("Test DFS traversal") {
    Node<int> root_node(200);
    Tree<int> tree;
    tree.add_root(root_node);
    Node<int> n1(100);
    Node<int> n2(-100);
    Node<int> n3(150);
    Node<int> n4(-150);
    Node<int> n5(50);
    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    vector<int> values;
    for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node) {
        values.push_back(node->get_value());
    }

    CHECK(!values.empty()); // Just to make sure we have values.
    CHECK(values.size() == 6);
}

TEST_CASE("Test 3-ary tree structure") {
    Node<int> root_node(10);
    Tree<int, 3> tree;
    tree.add_root(root_node);
    Node<int> n1(20);
    Node<int> n2(-30);
    Node<int> n3(40);
    Node<int> n4(50);
    Node<int> n5(-60);
    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(root_node, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    vector<int> values;
    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node) {
        values.push_back(node->get_value());
    }

    CHECK(values == vector<int>{10, 20, -30, 40, 50, -60});
}

TEST_CASE("Test different tree data type") {
    Node<string> root_node("root");
    Tree<string> tree;
    tree.add_root(root_node);
    Node<string> n1("left");
    Node<string> n2("right");
    Node<string> n3("left-left");
    Node<string> n4("left-right");
    Node<string> n5("right-left");
    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    vector<string> values;
    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node) {
        values.push_back(node->get_value());
    }

    CHECK(values == vector<string>{"root", "left", "right", "left-left", "left-right", "right-left"});
}
