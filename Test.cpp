// 325483444 gidirabi111@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Node.hpp"
#include "Tree.hpp"
#include "Complex.hpp"

using namespace std;

TEST_CASE("Test with INT Binary Tree") {
    Node<int> root_node(13);
    Tree<int> tree;
    tree.add_root(root_node);
    Node<int> n1(-7);
    Node<int> n2(29);
    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);

	SUBCASE("Testing BFS"){
		vector<int> values;
		vector<int> expected = {13, -7, 29};
		for (auto node = tree.begin_bfs(); node != tree.end_bfs(); ++node) {
			values.push_back(node->get_value());
		}
		CHECK(values == expected);
	}

	SUBCASE("Testing DFS"){
		vector<int> values;
		vector<int> expected = {13, -7, 29};
		for (auto node = tree.begin_dfs(); node != tree.end_dfs(); ++node) {
			values.push_back(node->get_value());
		}
		CHECK(values == expected);
	}

	SUBCASE("Testing Pre-Order"){
		vector<int> values;
		vector<int> expected = {13, -7, 29};
		for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node) {
			values.push_back(node->get_value());
		}
		CHECK(values == expected);
	}
	
	SUBCASE("Testing Post-Order"){
		vector<int> values;
		vector<int> expected = {-7, 29, 13};
		for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node) {
			values.push_back(node->get_value());
		}
		CHECK(values == expected);
	}

	SUBCASE("Testing In-Order"){
		vector<int> values;
		vector<int> expected = {-7, 13, 29};
		for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node) {
			values.push_back(node->get_value());
		}
		CHECK(values == expected);
	}

}

TEST_CASE("Test Complex Numbers Binary Tree") {

	ComplexNumber root(0.5, 2);
	Node<ComplexNumber> root_node(root);
	Tree<ComplexNumber> tree;
	tree.add_root(root_node);
	ComplexNumber n1(1, 1);
	ComplexNumber n2(5,2);
	ComplexNumber n3(1,8);
	ComplexNumber n4(8, 4);
	ComplexNumber n5(1, 2);
	ComplexNumber n6(4, 5);
	ComplexNumber n7(5, 1);
	ComplexNumber n8(9, 10);
	ComplexNumber n9(-4, 3); 
	Node<ComplexNumber> n1_node(n1);
	Node<ComplexNumber> n2_node(n2);
	Node<ComplexNumber> n3_node(n3);
	Node<ComplexNumber> n4_node(n4);
	Node<ComplexNumber> n5_node(n5);
	Node<ComplexNumber> n6_node(n6);
	Node<ComplexNumber> n7_node(n7);
	Node<ComplexNumber> n8_node(n8);
	Node<ComplexNumber> n9_node(n9);
	tree.add_sub_node(root_node, n1_node);
	tree.add_sub_node(root_node, n2_node);
	tree.add_sub_node(n1_node, n3_node);
	tree.add_sub_node(n1_node, n4_node);
	tree.add_sub_node(n2_node, n5_node);
	tree.add_sub_node(n2_node, n6_node);
	tree.add_sub_node(n3_node, n7_node);
	tree.add_sub_node(n3_node, n8_node);
	tree.add_sub_node(n4_node, n9_node);


	SUBCASE("Testing BFS"){
		vector<ComplexNumber> values;
		vector<ComplexNumber> expected = {root, n1, n2, n3, n4, n5, n6, n7, n8, n9};
		for (auto node = tree.begin_bfs(); node != tree.end_bfs(); ++node) {
			values.push_back(node->get_value());
		}
		CHECK(values == expected);
	}

	SUBCASE("Testing DFS"){
		vector<ComplexNumber> values;
		vector<ComplexNumber> expected = {root, n1, n3, n7, n8, n4, n9, n2, n5, n6};
		for (auto node = tree.begin_dfs(); node != tree.end_dfs(); ++node) {
			values.push_back(node->get_value());
		}
		CHECK(values == expected);
	}

	SUBCASE("Testing Pre-Order"){
		vector<ComplexNumber> values;
		vector<ComplexNumber> expected = {root, n1, n3, n7, n8, n4, n9, n2, n5, n6};
		for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node) {
			values.push_back(node->get_value());
		}
		CHECK(values == expected);
	}
	
	SUBCASE("Testing Post-Order"){
		vector<ComplexNumber> values;
		vector<ComplexNumber> expected = {n7, n8, n3, n9, n4, n1, n5, n6, n2, root};
		for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node) {
			values.push_back(node->get_value());
		}
		CHECK(values == expected);
	}

	SUBCASE("Testing In-Order"){
		vector<ComplexNumber> values;
		vector<ComplexNumber> expected = {n7, n3, n8, n1, n9, n4, root, n5, n2, n6};
		for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node) {
			values.push_back(node->get_value());
		}
		CHECK(values == expected);
	}

	SUBCASE("Testing Heap order"){
		vector<ComplexNumber> values;
		vector<ComplexNumber> expected = {n1, root, n5, n7, n2, n9, n6, n3, n4, n8};
		for (auto node = tree.begin_heap(); node != tree.end_heap(); ++node) {
			values.push_back(node->get_value());
		}
		CHECK(values == expected);
	}
}


TEST_CASE("Test String 3-ary tree structure") {
    Node<string> root("root");
    Tree<string, 3> tree;
    tree.add_root(root);
	Node<string> n1("Animal");
	Node<string> n2("Bird");
	Node<string> n3("Cat");
	Node<string> n4("Dog");
	Node<string> n5("Elephant");
	Node<string> n6("Frog");
	Node<string> n7("Goat");
	Node<string> n8("Horse");
	tree.add_sub_node(root, n6);
	tree.add_sub_node(root, n7);
	tree.add_sub_node(root, n8);
	tree.add_sub_node(n6, n1);
	tree.add_sub_node(n7, n2);
	tree.add_sub_node(n8, n3);
	tree.add_sub_node(n8, n4);
	tree.add_sub_node(n8, n5);
    
	SUBCASE("Testing BFS"){
		vector<string> values;
		vector<string> expected = {"root", "Frog", "Goat", "Horse", "Animal", "Bird", "Cat", "Dog", "Elephant"};
		for (auto node = tree.begin_bfs(); node != tree.end_bfs(); ++node) {
			values.push_back(node->get_value());
		}
		CHECK(values == expected);
	}

	SUBCASE("Testing DFS"){
		vector<string> values;
		vector<string> expected = {"root", "Frog", "Animal", "Goat", "Bird", "Horse", "Cat", "Dog", "Elephant"};
		for (auto node = tree.begin_dfs(); node != tree.end_dfs(); ++node) {
			values.push_back(node->get_value());
		}
		CHECK(values == expected);
	}

	SUBCASE("Testing Pre-Order"){
		vector<string> values;
		vector<string> expected = {"root", "Frog", "Animal", "Goat", "Bird", "Horse", "Cat", "Dog", "Elephant"};
		for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node) {
			values.push_back(node->get_value());
		}
		CHECK(values == expected);
	}
	
	SUBCASE("Testing Post-Order"){
		vector<string> values;
		vector<string> expected = {"Animal", "Frog", "Bird", "Goat", "Cat", "Dog", "Elephant", "Horse", "root"};
		for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node) {
			values.push_back(node->get_value());
		}
		CHECK(values == expected);
	}

	SUBCASE("Testing In-Order"){
		vector<string> values;
		vector<string> expected = {"Animal", "Frog", "root", "Bird", "Goat"};
		for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node) {
			values.push_back(node->get_value());
		}
		CHECK(values == expected);
	}

	SUBCASE("Testing Heap order"){
		vector<string> values;
		vector<string> expected = {"Animal", "Bird", "Cat", "Dog", "Elephant", "Frog", "Goat", "Horse", "root"};
		for (auto node = tree.begin_heap(); node != tree.end_heap(); ++node) {
			values.push_back(node->get_value());
		}
		CHECK(values == expected);
	}
}
