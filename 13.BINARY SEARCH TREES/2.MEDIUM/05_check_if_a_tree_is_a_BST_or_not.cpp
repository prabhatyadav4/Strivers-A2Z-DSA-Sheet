/*
98. Validate Binary Search Tree

Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys strictly less than the node's key.
The right subtree of a node contains only nodes with keys strictly greater than the node's key.
Both the left and right subtrees must also be binary search trees.


Example 1:
Input: root = [2,1,3]
Output: true

Example 2:
Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.


Constraints:
The number of nodes in the tree is in the range [1, 104].
-231 <= Node.val <= 231 - 1
*/

#include <iostream>
#include <stack>
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

// Recursion with minimum and maximum bounds

bool isValid(TreeNode *root, long long low, long long high)
{
    if (root == nullptr)
    {
        return true;
    }

    if (root->val <= low || root->val >= high)
    {
        return false;
    }

    return isValid(root->left, low, root->val) && isValid(root->right, root->val, high);
}

bool isValidBSTBounds(TreeNode *root)
{
    return isValid(root, LLONG_MIN, LLONG_MAX);
}

// Inorder traversal

bool inorder(TreeNode *root, TreeNode *&prev)
{
    if (root == nullptr)
    {
        return true;
    }

    if (!inorder(root->left, prev))
    {
        return false;
    }

    if (prev != nullptr && root->val <= prev->val)
    {
        return false;
    }

    prev = root;

    return inorder(root->right, prev);
}

bool isValidBSTRecursive(TreeNode *root)
{
    TreeNode *prev = nullptr;
    return inorder(root, prev);
}

bool isValidBSTIterative(TreeNode *root)
{
    stack<TreeNode *> st;
    long long prev = LLONG_MIN;

    while (root != nullptr || !st.empty())
    {
        while (root != nullptr)
        {
            st.push(root);
            root = root->left;
        }

        root = st.top();
        st.pop();

        if (root->val <= prev)
        {
            return false;
        }

        prev = root->val;

        root = root->right;
    }

    return true;
}

int main()
{
    // Example 1: [2, 1, 3] is a valid BST.
    TreeNode *validRoot = new TreeNode(2);
    validRoot->left = new TreeNode(1);
    validRoot->right = new TreeNode(3);

    // Example 2: [5, 1, 4, null, null, 3, 6] is not a valid BST.
    TreeNode *invalidRoot = new TreeNode(5);
    invalidRoot->left = new TreeNode(1);
    invalidRoot->right = new TreeNode(4);
    invalidRoot->right->left = new TreeNode(3);
    invalidRoot->right->right = new TreeNode(6);

    cout << boolalpha;
    cout << "Example 1 (Bounds): " << isValidBSTBounds(validRoot) << '\n';
    cout << "Example 1 (Recursive Inorder): " << isValidBSTRecursive(validRoot) << '\n';
    cout << "Example 1 (Iterative Inorder): " << isValidBSTIterative(validRoot) << '\n';

    cout << "Example 2 (Bounds): " << isValidBSTBounds(invalidRoot) << '\n';
    cout << "Example 2 (Recursive Inorder): " << isValidBSTRecursive(invalidRoot) << '\n';
    cout << "Example 2 (Iterative Inorder): " << isValidBSTIterative(invalidRoot) << '\n';

    delete validRoot->left;
    delete validRoot->right;
    delete validRoot;
    delete invalidRoot->left;
    delete invalidRoot->right->left;
    delete invalidRoot->right->right;
    delete invalidRoot->right;
    delete invalidRoot;
}