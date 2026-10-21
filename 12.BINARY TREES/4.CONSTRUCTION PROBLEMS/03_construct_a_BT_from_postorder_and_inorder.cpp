/*
106. Construct Binary Tree from Inorder and Postorder Traversal

Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

Example 1:
Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]

Example 2:
Input: inorder = [-1], postorder = [-1]
Output: [-1]


Constraints:
1 <= inorder.length <= 3000
postorder.length == inorder.length
-3000 <= inorder[i], postorder[i] <= 3000
inorder and postorder consist of unique values.
Each value of postorder also appears in inorder.
inorder is guaranteed to be the inorder traversal of the tree.
postorder is guaranteed to be the postorder traversal of the tree.
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

TreeNode *buildI(vector<int> &inorder, vector<int> &postorder, int &postIndex, int left, int right)
{
    if (left > right)
    {
        return nullptr;
    }

    int rootValue = postorder[postIndex--];
    TreeNode *root = new TreeNode(rootValue);

    int mid = left;
    while (inorder[mid] != rootValue)
    {
        mid++;
    }

    root->right = buildI(inorder, postorder, postIndex, mid + 1, right);
    root->left = buildI(inorder, postorder, postIndex, left, mid - 1);

    return root;
}

TreeNode *BruteBuildTree(vector<int> &inorder, vector<int> &postorder)
{
    int postIndex = postorder.size() - 1;

    return buildI(inorder, postorder, postIndex, 0, (int)inorder.size() - 1);
}

TreeNode *buildII(vector<int> &inorder, vector<int> &postorder, int &postIndex, int left, int right, unordered_map<int, int> &inMap)
{
    if (left > right)
    {
        return nullptr;
    }

    int rootValue = postorder[postIndex--];
    TreeNode *root = new TreeNode(rootValue);

    int mid = inMap[rootValue];

    root->right = buildII(inorder, postorder, postIndex, mid + 1, right, inMap);
    root->left = buildII(inorder, postorder, postIndex, left, mid - 1, inMap);

    return root;
}

TreeNode *OptimalBuildTree(vector<int> &inorder, vector<int> &postorder)
{
    unordered_map<int, int> inMap;

    for (int i = 0; i < (int)inorder.size(); i++)
    {
        inMap[inorder[i]] = i;
    }

    int postIndex = postorder.size() - 1;

    return buildII(inorder, postorder, postIndex, 0, (int)inorder.size() - 1, inMap);
}

void printPreorder(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    cout << root->val << ' ';
    printPreorder(root->left);
    printPreorder(root->right);
}

int main()
{
    vector<int> postorder = {9, 15, 7, 20, 3};
    vector<int> inorder = {9, 3, 15, 20, 7};

    TreeNode *bruteTree = BruteBuildTree(inorder, postorder);
    cout << "Brute build preorder: ";
    printPreorder(bruteTree);
    cout << '\n';

    TreeNode *optimalTree = OptimalBuildTree(inorder, postorder);
    cout << "Optimal build preorder: ";
    printPreorder(optimalTree);
    cout << '\n';
}