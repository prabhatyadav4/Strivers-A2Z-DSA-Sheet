/*
Search in BST

Given a Binary Search Tree and a node value key, return true if the node with value key is present in the BST; otherwise, return false.

Examples:
Input: root = [6, 2, 8, N, N, 7, 9], key = 8
Output: true
Explanation: 8 is present in the BST as right child of root.

Input: root = [16, 12, 18, 10, N, 17, 19], key = 14
Output: false
Explanation: 14 is not present in the BST

Constraints:
1 ≤ number of nodes ≤ 3*104
1 ≤ node->data, key ≤ 109
*/

#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

bool searchRecursive(TreeNode *root, int key)
{
    if (root == nullptr)
    {
        return false;
    }

    if (root->val == key)
    {
        return true;
    }

    if (key < root->val)
    {
        return searchRecursive(root->left, key);
    }
    else
    {
        return searchRecursive(root->right, key);
    }

    return false;
}

bool searchIterative(TreeNode *root, int key)
{
    bool present = false;

    while (root != nullptr)
    {
        if (root->val == key)
        {
            present = true;
            break;
        }
        else if (key < root->val)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }

    return present;
}

int main()
{
    TreeNode *root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    int key = 7;

    cout << "Recursive search: "
         << (searchRecursive(root, key) ? "true" : "false") << endl;
    cout << "Iterative search: "
         << (searchIterative(root, key) ? "true" : "false") << endl;

    return 0;
}