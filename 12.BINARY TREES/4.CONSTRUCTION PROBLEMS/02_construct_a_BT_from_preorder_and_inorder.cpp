/*
105. Construct Binary Tree from Preorder and Inorder Traversal

Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

Example 1:
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]

Example 2:
Input: preorder = [-1], inorder = [-1]
Output: [-1]


Constraints:
1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder and inorder consist of unique values.
Each value of inorder also appears in preorder.
preorder is guaranteed to be the preorder traversal of the tree.
inorder is guaranteed to be the inorder traversal of the tree.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
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

TreeNode *buildI(vector<int> &preorder, vector<int> &inorder, int &preIndex, int left, int right)
{
    if (left > right)
    {
        return nullptr;
    }

    int rootValue = preorder[preIndex++];
    TreeNode *root = new TreeNode(rootValue);

    int mid = left;
    while (inorder[mid] != rootValue)
    {
        mid++;
    }

    root->left = buildI(preorder, inorder, preIndex, left, mid - 1);
    root->right = buildI(preorder, inorder, preIndex, mid + 1, right);

    return root;
}

TreeNode *BruteBuildTree(vector<int> &preorder, vector<int> &inorder)
{
    int preIndex = 0;

    return buildI(preorder, inorder, preIndex, 0, (int)inorder.size() - 1);
}

TreeNode *buildII(vector<int> &preorder, vector<int> &inorder, int &preIndex, int left, int right, unordered_map<int, int> &inMap)
{
    if (left > right)
    {
        return nullptr;
    }

    int rootValue = preorder[preIndex++];
    TreeNode *root = new TreeNode(rootValue);

    int mid = inMap[rootValue];

    root->left = buildII(preorder, inorder, preIndex, left, mid - 1, inMap);
    root->right = buildII(preorder, inorder, preIndex, mid + 1, right, inMap);

    return root;
}

TreeNode *OptimalBuildTree(vector<int> &preorder, vector<int> &inorder)
{
    unordered_map<int, int> inMap;

    for (int i = 0; i < (int)inorder.size(); i++)
    {
        inMap[inorder[i]] = i;
    }

    int preIndex = 0;

    return buildII(preorder, inorder, preIndex, 0, (int)inorder.size() - 1, inMap);
}

void printPreorder(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main()
{
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    TreeNode *bruteTree = BruteBuildTree(preorder, inorder);
    cout << "Brute build preorder: ";
    printPreorder(bruteTree);
    cout << '\n';

    TreeNode *optimalTree = OptimalBuildTree(preorder, inorder);
    cout << "Optimal build preorder: ";
    printPreorder(optimalTree);
    cout << '\n';
}