#pragma once
#include "TreeNode.h"
class Tree
{
	friend class TreeNode;
private:

	TreeNode* root;
	TreeNode* CreateNode(int val);
	TreeNode* InsertNodePrivate(TreeNode* node, int key);
	TreeNode* DeleteNodePrivate(TreeNode*& node, int value);
	void InOrderPrivate(TreeNode* root);
	void PreOrderPrivate(TreeNode* root);
	void PostOrderPrivate(TreeNode* root);
	void PrintTreePrivate(TreeNode* root);
	TreeNode* FindMin(TreeNode* node);

public:
	Tree();
	void InsertNode(int data);
	void InOrder();
	void PreOrder();
	void PostOrder();
	void PrintTree();
	void DeleteNode(int data);
};

