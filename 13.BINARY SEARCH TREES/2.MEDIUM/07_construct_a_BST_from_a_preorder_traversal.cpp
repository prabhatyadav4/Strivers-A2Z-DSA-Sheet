/*
1008. Construct Binary Search Tree from Preorder Traversal

Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.

It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.

A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.

A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.



Example 1:
Input: preorder = [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]

Example 2:
Input: preorder = [1,3]
Output: [1,null,3]


Constraints:
1 <= preorder.length <= 100
1 <= preorder[i] <= 1000
All the values of preorder are unique.
*/

#include <iostream>
#include <vector>
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

TreeNode *insertNode(TreeNode *root, int val)
{
    if (root == nullptr)
    {
        return new TreeNode(val);
    }

    if (val < root->val)
    {
        root->left = insertNode(root->left, val);
    }
    else if (val > root->val)
    {
        root->right = insertNode(root->right, val);
    }

    return root;
}

TreeNode *BruteBSTfromPreorder(vector<int> &preorder)
{
    TreeNode *root = nullptr;

    for (int value : preorder)
    {
        root = insertNode(root, value);
    }

    return root;
}

TreeNode *build(vector<int> &preorder, int &i, int bound)
{
    if (i == preorder.size() || preorder[i] > bound)
    {
        return nullptr;
    }

    TreeNode *root = new TreeNode(preorder[i++]);
    root->left = build(preorder, i, root->val);
    root->right = build(preorder, i, bound);

    return root;
}

TreeNode *BetterBSTfromPreorder(vector<int> &preorder)
{
    int i = 0;
    return build(preorder, i, INT_MAX);
}

TreeNode *OptimalBSTfromPreorder(vector<int> &preorder)
{
    TreeNode *root = new TreeNode(preorder[0]);

    stack<TreeNode *> st;
    st.push(root);

    for (int i = 1; i < preorder.size(); i++)
    {
        TreeNode *node = new TreeNode(preorder[i]);

        if (preorder[i] < st.top()->val)
        {
            st.top()->left = node;
        }
        else
        {
            TreeNode *parent = nullptr;

            while (!st.empty() && preorder[i] > st.top()->val)
            {
                parent = st.top();
                st.pop();
            }

            parent->right = node;
        }

        st.push(node);
    }

    return root;
}

int main()
{
    vector<int> preorder = {8, 5, 1, 7, 10, 12};

    TreeNode *roots[] = {
        BruteBSTfromPreorder(preorder),
        BetterBSTfromPreorder(preorder),
        OptimalBSTfromPreorder(preorder)};

    const char *names[] = {"Brute", "Better", "Optimal"};
    for (int i = 0; i < 3; ++i)
    {
        cout << names[i] << " BST preorder: ";
        stack<TreeNode *> nodes;
        if (roots[i] != nullptr)
        {
            nodes.push(roots[i]);
        }

        while (!nodes.empty())
        {
            TreeNode *node = nodes.top();
            nodes.pop();
            cout << node->val << " ";
            if (node->right != nullptr)
                nodes.push(node->right);
            if (node->left != nullptr)
                nodes.push(node->left);
        }
        cout << endl;
    }

    return 0;
}