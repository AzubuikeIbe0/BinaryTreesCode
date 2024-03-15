#pragma once
#include "TreeNode.h"
class BinaryTree
{
	friend class TreeNode;
private:

	TreeNode* root;
	TreeNode* InsertNodePrivate(TreeNode* node, int key);
	TreeNode* DeleteNodePrivate(TreeNode*& node, int value);
	void InOrderPrivate(TreeNode* root);
	void PreOrderPrivate(TreeNode* root);
	void PostOrderPrivate(TreeNode* root);
	void PrintTreePrivate(TreeNode* root);
	TreeNode* FindMin(TreeNode* node);
	int GetHeightPrivate(TreeNode* node);

public:
	BinaryTree();
	void InsertNode(int data);
	void InOrder();
	void PreOrder();
	void PostOrder();
	void PrintTree();
	void DeleteNode(int data);
	void GetHeight();
};
