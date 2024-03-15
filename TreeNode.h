#pragma once
#include "BinaryTree.h"


class TreeNode
{
	friend class BinaryTree;
private:
	int data;
	TreeNode* left;
	TreeNode* right;
public:
	TreeNode(int val);
};

