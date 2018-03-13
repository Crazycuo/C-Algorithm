/*************************************************************************
	> File Name: avl_node.h
	> Author: crazycuo
	> Mail: crazycuo@cisco.com 
	> Created Time: Wed Jan 10 21:30:55 2018
 ************************************************************************/

#include <iostream>
#include <sstream>
#include <algorithm>

#define pow2(n) (1 << n)
using namespace std;

struct avl_node {
	int data;	
	struct avl_node *left;
	struct avl_node *right;
};

typedef struct avl_node avl_node;

class AvlTree {
	private:
		avl_node *root;
	public:
		int height(avl_node *);
		int diff(avl_node *);
		avl_node *balance(avl_node *);
		avl_node *rr_rotation(avl_node *);
		avl_node *rl_rotation(avl_node *);
		avl_node *ll_rotation(avl_node *);
		avl_node *lr_rotation(avl_node *);
		avl_node *insert(avl_node *, int);

		void display(avl_node *, int);
		void inorder(avl_node *);
		void preorder(avl_node *);
		void postorder(avl_node *);

		AvlTree() {
			root = NULL;
			cout << "AvlTree initialization test" << endl;
		}
};
