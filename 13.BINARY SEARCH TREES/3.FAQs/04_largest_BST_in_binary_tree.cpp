/*
142. Largest BST in Binary Tree

Given a root of Binary Tree, where the nodes have integer values. Return the size of the largest subtree of the binary tree which is also a BST.

A binary search tree (BST) is a binary tree data structure which has the following properties.

The left subtree of a node contains only nodes with data less than the node’s data.
The right subtree of a node contains only nodes with data greater than the node’s data.
Both the left and right subtrees must also be binary search trees.

Example 1:
Input : root = [2, 1, 3]

Output : 3

Explanation :

The given complete binary tree is a BST consisting of 3 nodes.

Example 2:
Input : root = [10, null, 20, null, 30, null, 40, null, 50]

Output : 5

Explanation :

If we consider the node 10 as root node then it forms the largest BST.

Constraints:
1 <= Number of Nodes <= 104
1 <= Node.val <= 105
*/

#include <iostream>
#include <algorithm>
#include <climits>
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

bool isBST(TreeNode *root, long long low, long long high)
{
    if (root == nullptr)
    {
        return true;
    }

    if (root->val <= low || root->val >= high)
    {
        return false;
    }

    return isBST(root->left, low, root->val) && isBST(root->right, root->val, high);
}

int countNodes(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}

int BruteLargestBST(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int currSize = 0;

    if (isBST(root, LLONG_MIN, LLONG_MAX))
    {
        currSize = countNodes(root);
    }

    int leftSize = BruteLargestBST(root->left);
    int rightSize = BruteLargestBST(root->right);

    return max({currSize, leftSize, rightSize});
}

struct Info
{
    int size;
    int minVal;
    int maxVal;

    Info(int size, int minVal, int maxVal)
    {
        this->size = size;
        this->minVal = minVal;
        this->maxVal = maxVal;
    }
};

Info solve(TreeNode *root)
{
    if (root == nullptr)
    {
        return {0, INT_MAX, INT_MIN};
    }

    Info left = solve(root->left);
    Info right = solve(root->right);

    if (root->val > left.maxVal && root->val < right.minVal)
    {
        int currSize = 1 + left.size + right.size;
        int currMin = min(root->val, left.minVal);
        int currMax = max(root->val, right.maxVal);

        return {currSize, currMin, currMax};
    }

    return {max(left.size, right.size), INT_MIN, INT_MAX};
}

int OptimalLargestBST(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    return solve(root).size;
}

int main()
{
    // Example 1: the entire tree is a BST.
    TreeNode *root1 = new TreeNode(2);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(3);

    cout << "Example 1 - Brute: " << BruteLargestBST(root1) << '\n';
    cout << "Example 1 - Optimal: " << OptimalLargestBST(root1) << '\n';

    // Example 2: a right-skewed BST.
    TreeNode *root2 = new TreeNode(10);
    root2->right = new TreeNode(20);
    root2->right->right = new TreeNode(30);
    root2->right->right->right = new TreeNode(40);
    root2->right->right->right->right = new TreeNode(50);

    cout << "Example 2 - Brute: " << BruteLargestBST(root2) << '\n';
    cout << "Example 2 - Optimal: " << OptimalLargestBST(root2) << '\n';
}