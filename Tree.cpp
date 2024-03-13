#include "Tree.h"
#include "TreeNode.h"
#include <iostream>
using namespace std;

TreeNode* Tree::CreateNode(int val)
{
    TreeNode* NewNode = new TreeNode();

    NewNode->data = val;

    NewNode->left = nullptr;

    NewNode->right = nullptr;

    return NewNode;

}

TreeNode* Tree::InsertNode(TreeNode* node, int key)
{
    if (node == NULL) {
        return CreateNode(key);
    }

    if (key < node->data) {
        node->left = InsertNode(node->left, key);
    }
    else {
        node->right = InsertNode(node->right, key);
    }

    return node;
}

TreeNode* Tree::DeleteNode(TreeNode* root, int key)
{
    if (root == nullptr) {
        return root;
    }

    if (root->data > key) {
        root->left = DeleteNode(root->left, key);
        return root;
    }
    else if (root->data < key) {
        root->right = DeleteNode(root->right, key);
        return root;
    }

    if (root->left == nullptr) {
        TreeNode* temp = root->right;
        delete root;
        return temp;
    }
    else if (root->right == nullptr) {
        TreeNode* temp = root->left;
        delete root;
        return temp;
    }
    else {
        TreeNode* parentSuccessor = root;

        // Find successor
        TreeNode* successor = root->right;
        while (successor->left != nullptr) {
            parentSuccessor = successor;
            successor = successor->left;
        }

        if (parentSuccessor != root) {
            parentSuccessor->left = successor->right;
        }
        else {
            parentSuccessor->right = successor->right;
        }

        root->data = successor->data;

        return successor;
        return root;
    }
}



void Tree::InsertNode(TreeNode* root)
{
    if (root == nullptr) {
        return;
    }

    cout << root->data << ", ";
    InsertNode(root->left);
    InsertNode(root->right);
}

void Tree::InOrder(TreeNode* root)
{
    if (root == nullptr) {
        return;
    }

    InOrder(root->left);
    cout << root->data << ", ";
    InOrder(root->right);
}

void Tree::PreOrder(TreeNode* root)
{
    if (root == nullptr) {
        return;
    }

    cout << root->data << ", ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void Tree::PostOrder(TreeNode* root)
{
    if (root == nullptr) {
        return;
    }
    
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << ", ";
}

void Tree::PrintTree(TreeNode* root)
{
    if (root == nullptr) {
        return;
    }

    cout << root->data << ", ";
    PrintTree(root->left);
    PrintTree(root->right);
}
