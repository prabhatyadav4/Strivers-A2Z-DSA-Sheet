/*
124. Binary Tree Maximum Path Sum

A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.

Example 1:
Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.

Example 2:
Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.

Constraints:
The number of nodes in the tree is in the range [1, 3 * 104].
-1000 <= Node.val <= 1000
*/

#include <iostream>
#include <algorithm>
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

int findMaxDownwardPath(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int left = max(0, findMaxDownwardPath(root->left));
    int right = max(0, findMaxDownwardPath(root->right));

    return root->val + max(left, right);
}

int BruteMaxPathSum(TreeNode *root)
{
    if (root == nullptr)
    {
        return INT_MIN;
    }

    int left = max(0, findMaxDownwardPath(root->left));
    int right = max(0, findMaxDownwardPath(root->right));

    int currentPath = root->val + left + right;

    int leftBest = root->left ? BruteMaxPathSum(root->left) : INT_MIN;
    int rightBest = root->right ? BruteMaxPathSum(root->right) : INT_MIN;

    return max({currentPath, leftBest, rightBest});
}

int findMaxGain(TreeNode *root, int &maxSum)
{
    if (root == nullptr)
    {
        return 0;
    }

    int left = max(0, findMaxGain(root->left, maxSum));
    int right = max(0, findMaxGain(root->right, maxSum));

    int currentPath = root->val + left + right;

    maxSum = max(maxSum, currentPath);

    return root->val + max(left, right);
}

int OptimalMaxPathSum(TreeNode *root)
{
    int maxSum = INT_MIN;

    findMaxGain(root, maxSum);

    return maxSum;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->left->left = new TreeNode(6);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(8);
    root->right->right->right = new TreeNode(9);
    root->right->right->right->right = new TreeNode(10);

    cout << "BRUTE: The maximum path sum is: " << BruteMaxPathSum(root) << endl;
    cout << "OPTIMAL: The maximum path sum is: " << OptimalMaxPathSum(root) << endl;

    return 0;
}