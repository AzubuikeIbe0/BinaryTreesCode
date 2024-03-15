#include "BinaryTree.h"
#include "TreeNode.h"
#include <iostream>
using namespace std;

BinaryTree::BinaryTree() : root(nullptr){}



TreeNode* BinaryTree::InsertNodePrivate(TreeNode* node, int key) {
    if (node == nullptr) {
        return new TreeNode(key);
    }

    if (key < node->data) {
        node->left = InsertNodePrivate(node->left, key);
    }
    else {
        node->right = InsertNodePrivate(node->right, key);
    }

    return node;
}



void BinaryTree::InsertNode(int key)
{
    root = InsertNodePrivate(root, key);
}



void BinaryTree::InOrderPrivate(TreeNode* root)
{
    if (root == nullptr) {
        return;
    }

    InOrderPrivate(root->left);
    cout << root->data << ", ";
    InOrderPrivate(root->right);

}



void BinaryTree::InOrder()
{
    InOrderPrivate(root);
}

void BinaryTree::PreOrderPrivate(TreeNode* root)
{
    if (root == nullptr) {
        return;
    }

    cout << root->data << ", ";
    PreOrderPrivate(root->left);
    PreOrderPrivate(root->right);

}



void BinaryTree::PreOrder()
{
    PreOrderPrivate(root);
}


void BinaryTree::PostOrderPrivate(TreeNode* root)
{
    if (root == nullptr) {
        return;
    }

    PostOrderPrivate(root->left);
    PostOrderPrivate(root->right);
    cout << root->data << ", ";


}


void BinaryTree::PostOrder()
{
    PostOrderPrivate(root);
}

void BinaryTree::PrintTreePrivate(TreeNode* root)
{
    if (root == nullptr) {
        return;
    }

    cout << root->data << ", ";
    PrintTreePrivate(root->left);
    PrintTreePrivate(root->right);

}

void BinaryTree::PrintTree()
{
    PrintTreePrivate(root);
}




TreeNode* BinaryTree::FindMin(TreeNode* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}



// Delete a node


TreeNode* BinaryTree::DeleteNodePrivate(TreeNode*& node, int value) {
    // Check if the node is null
    if (node == nullptr) {
        return nullptr; // If the node is null, return nullptr
    }

    // Check if the current node's value matches the value to be deleted
    if (node->data == value) {
        // If the node has no left child
        if (node->left == nullptr) {
            TreeNode* tmp = node->right;
            delete node;
            node = tmp; // Update the link to the deleted node
        }
        // If the node has no right child
        else if (node->right == nullptr) {
            TreeNode* tmp = node->left;
            delete node;
            node = tmp; // Update the link to the deleted node
        }
        // If the node has both left and right children
        else {
            // Find the minimum value node in the right subtree
            TreeNode* minRight = FindMin(node->right);
            // Replace the current node's value with the minimum value
            node->data = minRight->data;
            // Delete the minimum value node from the right subtree
            DeleteNodePrivate(node->right, minRight->data);
        }
    }
    // If the current node's value doesn't match the value to be deleted
    else {
        // If the value is greater than the current node's value, search in the right subtree
        if (value > node->data) {
            DeleteNodePrivate(node->right, value);
        }
        // If the value is less than the current node's value, search in the left subtree
        else {
            DeleteNodePrivate(node->left, value);
        }
    }

    return node;
}



void BinaryTree::DeleteNode(int data)
{
    DeleteNodePrivate(root, data);
}


int BinaryTree::GetHeightPrivate(TreeNode* node) {
    // Base case: If the node is nullptr (empty), return 0
    if (node == nullptr) {
        return 0;
    }

    // Recursive steps:
    // 1. Calculate the height of the left subtree
    int leftHeight = GetHeightPrivate(node->left);

    // 2. Calculate the height of the right subtree
    int rightHeight = GetHeightPrivate(node->right);

    // 3. Return the maximum height between left and right subtrees, plus 1 for the current node
    return 1 + std::max(leftHeight, rightHeight);
}

void BinaryTree::GetHeight() {
    // Print the height of the tree
    std::cout << "Height of the tree: " << GetHeightPrivate(root) <<std::endl;
}




//TreeNode* BinaryTree::GetHeightPrivate(TreeNode* node)
//{
//    // Base case: If the node is nullptr (empty), return nullptr
//    if (node == nullptr) {
//        return nullptr;
//    }
//
//    // Recursive steps:
//    // 1. Calculate the height of the left subtree
//    TreeNode* leftHeight = GetHeightPrivate(node->left);
//
//    // 2. Calculate the height of the right subtree
//    TreeNode* rightHeight = GetHeightPrivate(node->right);
//
//    // 3. Return the maximum height between left and right subtrees, plus 1 for the current node
//    return leftHeight > rightHeight ? leftHeight : rightHeight;
//}
//
//void BinaryTree::GetHeight()
//{
//    GetHeightPrivate(root);
//}




