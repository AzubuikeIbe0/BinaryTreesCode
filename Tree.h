#pragma once
#include "TreeNode.h"
class Tree
{
	friend class TreeNode;
	friend int main();
private:
	TreeNode* root;
	TreeNode* CreateNode(int val);
	TreeNode* InsertNodePrivate(TreeNode* node, int key);
	TreeNode* DeleteNode(TreeNode* root, int key);
	void DeleteNodePrivate(TreeNode*& node, int value);
public:
	void InsertNode(TreeNode* root);
	void InOrder(TreeNode* root);
	void PreOrder(TreeNode* root);
	void PostOrder(TreeNode* root);
	void PrintTree(TreeNode* root);
};

