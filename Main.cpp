#include <iostream>
#include "Tree.h"
using namespace std;

int main() {

	Tree T1;
	TreeNode* root = T1.CreateNode(1);

	root->left = T1.CreateNode(2);
	root->right = T1.CreateNode(3);

	root->left->left = T1.CreateNode(4);
	root->left->right = T1.CreateNode(5);
	root->right->left = T1.CreateNode(6);
	root->right->right = T1.CreateNode(7);

	root->left->left->left = T1.CreateNode(8);
	root->left->left->right = T1.CreateNode(9);
	root->right->left->left = T1.CreateNode(10);
	root->right->left->right = T1.CreateNode(11);

	//T1.PrintTree(root);
	//1, 2, 4, 8, 9, 5, 3, 6, 10, 11, 7,

	//T1.InOrder(root);
	//8, 4, 9, 2, 5, 1, 10, 6, 11, 3, 7,

	//T1.InsertNode(root);
	//1, 2, 4, 8, 9, 5, 3, 6, 10, 11, 7,

	//T1.PostOrder(root);
	//8, 9, 4, 5, 2, 10, 11, 6, 7, 3, 1,


	T1.PreOrder(root);
	cout << endl;
	/*1, 2, 4, 8, 9, 5, 3, 6, 10, 11, 7,*/

	T1.DeleteNode(root, 6);
	cout << endl;

	T1.PreOrder(root);



	return 0;
}