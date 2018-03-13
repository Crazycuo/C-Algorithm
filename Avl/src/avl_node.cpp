/*************************************************************************
	> File Name: avl_node.cpp
	> Author: crazycuo
	> Mail: crazycuo@cisco.com 
	> Created Time: Wed Jan 10 21:37:18 2018
 ************************************************************************/

#include <stdio.h>
#include "avl_node.h"

int AvlTree::height(avl_node *node) {
	int height = 0;
	int lheight = 0;
	int rheight = 0;
	if(!node)	return height;
	/**
	if(node->left) lheight = height(node->left);
	else	lheight = 0;
	if(node->right) rheight = height(node->right);
	else	rheight = 0;
	**/
	//the following codes will be better than above
	lheight = AvlTree::height(node->left) + 1;
	rheight = AvlTree::height(node->right) + 1;
	return lheight > rheight? lheight: rheight;
}

int AvlTree::diff(avl_node *node) {
	if(!node) return 0;
	int lheight = height(node->left) + 1;
	int rheight = height(node->right) + 1;
	int diff = lheight - rheight;
	
	return diff;
	//just diff. We need to decide RR or RL or LL or LR
	//return diff > 0? diff: -diff;
}


avl_node *AvlTree::ll_rotation(avl_node *node) {
	cout << "ll_rotation" << endl;
	avl_node *tmp = node->left;

	node->left = tmp->right;	
	tmp->right = node;
	return tmp;
}

avl_node *AvlTree::rr_rotation(avl_node *node) {
	cout << "rr_rotation" << endl;
	avl_node *tmp = node->right;

	node->right = tmp->left;	
	tmp->left = node;

	return tmp;
}

//lr == rr(left) + ll(root)
avl_node *AvlTree::lr_rotation(avl_node *node) {
	cout << "lr_rotation" << endl;
	/* may be right, but not dedicated than below
	avl_node *tmp = node->left->right;

	node->left->right = tmp->left;
	node->left = tmp->right;
	tmp->left = node->left;
	tmp->right = node;

	return tmp;
	*/
	avl_node *tmp;

	tmp = node->left;
	node->left = rr_rotation(tmp);

	return ll_rotation(node);
}

avl_node *AvlTree::rl_rotation(avl_node *node) {
	cout << "rl_rotation" << endl;
	avl_node *tmp;

	tmp = node->right;
	node->right = ll_rotation(tmp);

	return rr_rotation(node);
}

avl_node *AvlTree::balance(avl_node *node) {
	int diff = AvlTree::diff(node);	
	avl_node *partial_root = node;

	if(diff > 1) {
		if(AvlTree::diff(node->left) > 0) 
			partial_root = ll_rotation(node);
		else
			partial_root = lr_rotation(node);
	}
	if(diff < -1) {
		if(AvlTree::diff(node->right) < 0) 
			partial_root = rr_rotation(node);
		else
			partial_root = rl_rotation(node);
	}

	return partial_root;
}

avl_node *AvlTree::insert(avl_node *root, int value) {
	if(root == NULL) {
		root = new avl_node;
		root->data = value;
		root->left = root->right = NULL;
		return root;
	}	
		
	if(value < root->data) {
		root->left = AvlTree::insert(root->left, value);
		root = balance(root);
	}else if(value >= root->data) {
		root->right = AvlTree::insert(root->right, value);
		root = balance(root);
	}
	return root;
}

void AvlTree::inorder(avl_node *root) {
	if(root == NULL) 
		return;
	AvlTree::inorder(root->left);
	cout << root->data << " ";
	AvlTree::inorder(root->right);
}

void AvlTree::preorder(avl_node *root) {
	if(root == NULL) 
		return;
	cout << root->data << " ";
	AvlTree::preorder(root->left);
	AvlTree::preorder(root->right);
}

void AvlTree::postorder(avl_node *root) {
	if(root == NULL) 
		return;
	AvlTree::postorder(root->left);
	AvlTree::postorder(root->right);
	cout << root->data << " ";
}

void AvlTree::display(avl_node *ptr, int level) {
	int i;

	if(ptr) {
		AvlTree::display(ptr->right, level + 1);
		cout << endl;
		
		if(ptr == root)
			cout << "Root -> ";
		for(i = 0; i < level && ptr != root; i++)
			cout << "	";
		cout << ptr->data;
		AvlTree::display(ptr->left, level + 1);
	}
}
