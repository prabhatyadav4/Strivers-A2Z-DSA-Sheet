/*
222. Count Complete Tree Nodes

Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.

Example 1:
Input: root = [1,2,3,4,5,6]
Output: 6

Example 2:
Input: root = []
Output: 0

Example 3:
Input: root = [1]
Output: 1


Constraints:
The number of nodes in the tree is in the range [0, 5 * 104].
0 <= Node.val <= 5 * 104
The tree is guaranteed to be complete.
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

int BruteCountNodes(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    return 1 + BruteCountNodes(root->left) + BruteCountNodes(root->right);
}

int leftHeight(TreeNode *node)
{
    if (node == nullptr)
    {
        return 0;
    }

    int height = 0;

    while (node)
    {
        height++;
        node = node->left;
    }

    return height;
}

int rightHeight(TreeNode *node)
{
    if (node == nullptr)
    {
        return 0;
    }

    int height = 0;

    while (node)
    {
        height++;
        node = node->right;
    }

    return height;
}

int OptimalCountNodes(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int left = leftHeight(root);
    int right = rightHeight(root);

    if (left == right)
    {
        return (1LL << left) - 1;
    }

    return 1 + OptimalCountNodes(root->left) + OptimalCountNodes(root->right);
}

int main()
{
    // Complete binary tree: [1, 2, 3, 4, 5, 6]
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    cout << "Brute count: " << BruteCountNodes(root) << '\n';
    cout << "Optimal count: " << OptimalCountNodes(root) << '\n';

    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}