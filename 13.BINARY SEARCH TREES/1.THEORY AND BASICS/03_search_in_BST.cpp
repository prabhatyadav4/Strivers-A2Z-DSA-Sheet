/*
700. Search in a Binary Search Tree

You are given the root of a binary search tree (BST) and an integer val.

Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.

 

Example 1:
Input: root = [4,2,7,1,3], val = 2
Output: [2,1,3]

Example 2:
Input: root = [4,2,7,1,3], val = 5
Output: []
 

Constraints:
The number of nodes in the tree is in the range [1, 5000].
1 <= Node.val <= 107
root is a binary search tree.
1 <= val <= 107
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

TreeNode *searchRecursive(TreeNode *root, int key)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    if (root->val == key)
    {
        return root;
    }

    if (key < root->val)
    {
        return searchRecursive(root->left, key);
    }
    return searchRecursive(root->right, key);
}

TreeNode *searchIterative(TreeNode *root, int key)
{
    while (root != nullptr)
    {
        if (root->val == key)
        {
            return root;
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

    return nullptr;
}

int main()
{
    TreeNode *root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    int key = 7;

    TreeNode *recursiveResult = searchRecursive(root, key);
    TreeNode *iterativeResult = searchIterative(root, key);

    cout << "Recursive search: ";
    if (recursiveResult != nullptr)
    {
        cout << "found node with value " << recursiveResult->val << endl;
    }
    else
    {
        cout << "not found" << endl;
    }

    cout << "Iterative search: ";
    if (iterativeResult != nullptr)
    {
        cout << "found node with value " << iterativeResult->val << endl;
    }
    else
    {
        cout << "not found" << endl;
    }

    return 0;
}