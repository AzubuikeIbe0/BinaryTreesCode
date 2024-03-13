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

TreeNode* Tree::InsertNodePrivate(TreeNode* node, int key) {
    if (node == NULL) {
        return CreateNode(key);
    }

    if (key < node->data) {
        node->left = InsertNodePrivate(node->left, key);
    }
    else {
        node->right = InsertNodePrivate(node->right, key);
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

TreeNode* Tree::FindMin(TreeNode* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}


// Delete a node


void Tree::DeleteNodePrivate(TreeNode*& node, int value) {
    // Check if the node is null
    if (node == nullptr) {
        return; // If the node is null, return
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
}



