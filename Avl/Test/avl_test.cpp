/*************************************************************************
	> File Name: avl_test.cpp
	> Author: crazycuo
	> Mail: crazycuo@cisco.com 
	> Created Time: Wed Jan 10 22:56:11 2018
 ************************************************************************/

#include <iostream>
#include <avl_node.h> 
using namespace std;

struct avl_node *root = NULL;
int main() {
	AvlTree tree;

	root = tree.insert(root, 1);
	root = tree.insert(root, 2);
	root = tree.insert(root, 3);
	root = tree.insert(root, 4);
	root = tree.insert(root, 5);

	tree.inorder(root);
	cout << endl;
	tree.preorder(root);
	cout << endl;
	tree.postorder(root);
	cout << endl;

	tree.display(root, 0);
	cout << endl;
	return 0;	
}


