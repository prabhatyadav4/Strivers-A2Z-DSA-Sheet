/*
Maximum in a Binary Search Tree

Given a Binary Search Tree, the task is to find the node with the maximum value in a BST.

Example:

Input: root = [8, 3, 12, 1, 6, 10, 14]

Output: 14
*/

#include <iostream>
#include <vector>
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

// Using Inorder Traversal – O(n) Time and O(n) Space

void inorder(TreeNode *root, vector<int> &sortedInorder)
{
    if (root == nullptr)
    {
        return;
    }

    inorder(root->left, sortedInorder);
    sortedInorder.push_back(root->val);
    inorder(root->right, sortedInorder);
}

int BruteMaximumBST(TreeNode *root)
{
    if (root == nullptr)
    {
        return -1;
    }

    vector<int> sortedInorder;
    inorder(root, sortedInorder);
    int n = sortedInorder.size();

    return sortedInorder[n - 1];
}

// Using Recursion - O(h) Time and O(h) Space

int BetterMaximumBST(TreeNode *root)
{
    if (root == nullptr)
    {
        return -1;
    }

    if (root->right == nullptr)
        return root->val;

    return BetterMaximumBST(root->right);
}

// Using Iterative Way - O(h) Time and O(1) Space

int OptimalMaximumBST(TreeNode *root)
{
    if (root == nullptr)
    {
        return -1;
    }

    TreeNode *curr = root->right;

    while (curr->right != nullptr)
    {
        curr = curr->right;
    }

    return curr->val;
}

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(3);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(1);

    cout << "Maximum (Inorder): " << BruteMaximumBST(root) << '\n';
    cout << "Maximum (Recursive): " << BetterMaximumBST(root) << '\n';
    cout << "Maximum (Iterative): " << OptimalMaximumBST(root) << '\n';

    return 0;
}