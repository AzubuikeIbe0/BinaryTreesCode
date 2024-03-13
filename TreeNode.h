#pragma once
#include "Tree.h"


class TreeNode
{
	friend class Tree;
	friend int main();
private:
	int data;
	TreeNode* left;
	TreeNode* right;
public:
	TreeNode();
};

