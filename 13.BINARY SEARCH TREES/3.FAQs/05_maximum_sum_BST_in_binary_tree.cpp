/*
1373. Maximum Sum BST in Binary Tree

Given a binary tree root, return the maximum sum of all keys of any sub-tree which is also a Binary Search Tree (BST).

Assume a BST is defined as follows:
    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.


Example 1:
Input: root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
Output: 20
Explanation: Maximum sum in a valid Binary search tree is obtained in root node with key equal to 3.

Example 2:
Input: root = [4,3,null,1,2]
Output: 2
Explanation: Maximum sum in a valid Binary search tree is obtained in a single root node with key equal to 2.

Example 3:
Input: root = [-4,-2,-5]
Output: 0
Explanation: All values are negatives. Return an empty BST.


Constraints:
The number of nodes in the tree is in the range [1, 4 * 104].
-4 * 104 <= Node.val <= 4 * 104
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

    return isBST(root->left, low, root->val) &&
           isBST(root->right, root->val, high);
}

int sumNodes(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    return root->val + sumNodes(root->left) + sumNodes(root->right);
}

void solve(TreeNode *root, int &maxSum)
{
    if (root == nullptr)
    {
        return;
    }

    if (isBST(root, LLONG_MIN, LLONG_MAX))
    {
        int currSum = sumNodes(root);
        maxSum = max(maxSum, currSum);
    }

    solve(root->left, maxSum);
    solve(root->right, maxSum);
}

int BruteMaxSumBST(TreeNode *root)
{
    int maxSum = 0;

    solve(root, maxSum);

    return maxSum;
}

struct Info
{
    bool isBST;
    int minVal;
    int maxVal;
    long long sum;
};

long long maxSum = 0;

Info solve(TreeNode *root)
{
    if (root == nullptr)
    {
        return {true, INT_MAX, INT_MIN, 0};
    }

    Info left = solve(root->left);
    Info right = solve(root->right);

    if (left.isBST && right.isBST && root->val > left.maxVal && root->val < right.minVal)
    {
        long long currSum = left.sum + root->val + right.sum;
        maxSum = max(maxSum, currSum);
        int currMin = min(root->val, left.minVal);
        int currMax = max(root->val, right.maxVal);

        return {true, currMin, currMax, currSum};
    }

    return {false, 0, 0, 0};
}

long long OptimalMaxSumBST(TreeNode *root)
{
    maxSum = 0;
    solve(root);
    return maxSum;
}

int main()
{
    // Example tree: [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
    TreeNode *root = new TreeNode{1, nullptr, nullptr};
    root->left = new TreeNode{4, nullptr, nullptr};
    root->right = new TreeNode{3, nullptr, nullptr};
    root->left->left = new TreeNode{2, nullptr, nullptr};
    root->left->right = new TreeNode{4, nullptr, nullptr};
    root->right->left = new TreeNode{2, nullptr, nullptr};
    root->right->right = new TreeNode{5, nullptr, nullptr};
    root->right->right->left = new TreeNode{4, nullptr, nullptr};
    root->right->right->right = new TreeNode{6, nullptr, nullptr};

    cout << "Brute force: " << BruteMaxSumBST(root) << '\n';
    cout << "Optimal (postorder): " << OptimalMaxSumBST(root) << '\n';
}