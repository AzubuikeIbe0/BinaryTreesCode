#pragma once
#include "Tree.h"


class TreeNode
{
	friend class Tree;
private:
	int data;
	TreeNode* left;
	TreeNode* right;
public:
	TreeNode();
};

