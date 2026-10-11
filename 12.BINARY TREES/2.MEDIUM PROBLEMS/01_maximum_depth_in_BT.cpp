/*
104. Maximum Depth of Binary Tree

Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: 3

Example 2:
Input: root = [1,null,2]
Output: 2

Constraints:
The number of nodes in the tree is in the range [0, 104].
-100 <= Node.val <= 100
*/

#include <iostream>
#include <queue>
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

int BruteMaxDepth(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int left = BruteMaxDepth(root->left);
    int right = BruteMaxDepth(root->right);

    return 1 + max(left, right);
}

int OptimalMaxDepth(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    queue<TreeNode *> q;
    q.push(root);
    int depth = 0;

    while (!q.empty())
    {
        int size = q.size();
        depth++;

        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();

            if (node->left != nullptr)
            {
                q.push(node->left);
            }

            if (node->right != nullptr)
            {
                q.push(node->right);
            }
        }
    }

    return depth;
}

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(17);

    int ans1 = BruteMaxDepth(root);
    cout << "BRUTE: The maximum depth of the Binary Tree is: " << ans1 << endl;

    int ans2 = OptimalMaxDepth(root);
    cout << "OPTIMAL: The maximum depth of the Binary Tree is: " << ans2 << endl;

    return 0;
}