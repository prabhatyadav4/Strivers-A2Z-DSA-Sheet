/*
110. Balanced Binary Tree

Given a binary tree, determine if it is height-balanced.

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: true

Example 2:
Input: root = [1,2,2,3,3,null,null,4,4]
Output: false

Example 3:
Input: root = []
Output: true

Constraints:
The number of nodes in the tree is in the range [0, 5000].
-104 <= Node.val <= 104
*/

#include <iostream>
#include <algorithm>
#include <cstdlib>
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

int height(TreeNode *root)
{
    if (root == nullptr)
        return 0;

    return 1 + max(height(root->left), height(root->right));
}

bool BruteIsBalanced(TreeNode *root)
{
    if (root == nullptr)
    {
        return true;
    }

    int left = height(root->left);
    int right = height(root->right);

    if (abs(left - right) > 1)
        return false;

    return BruteIsBalanced(root->left) && BruteIsBalanced(root->right);
}

int maxHeight(TreeNode *root)
{
    if (root == nullptr)
        return 0;

    int left = maxHeight(root->left);
    if (left == -1)
        return -1;

    int right = maxHeight(root->right);
    if (right == -1)
        return -1;

    if (abs(left - right) > 1)
        return -1;

    return 1 + max(left, right);
}

bool OptimalIsBalanced(TreeNode *root)
{
    return maxHeight(root) != -1;
}

int main()
{
    TreeNode *root1 = new TreeNode(3);
    root1->left = new TreeNode(9);
    root1->right = new TreeNode(20);
    root1->right->left = new TreeNode(15);
    root1->right->right = new TreeNode(7);

    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(2);
    root2->left->left = new TreeNode(3);
    root2->left->right = new TreeNode(3);
    root2->left->left->left = new TreeNode(4);
    root2->left->left->right = new TreeNode(4);

    cout << "BRUTE (root1): " << boolalpha << BruteIsBalanced(root1) << endl;
    cout << "OPTIMAL (root1): " << boolalpha << OptimalIsBalanced(root1) << endl;

    cout << "BRUTE (root2): " << boolalpha << BruteIsBalanced(root2) << endl;
    cout << "OPTIMAL (root2): " << boolalpha << OptimalIsBalanced(root2) << endl;

    return 0;
}