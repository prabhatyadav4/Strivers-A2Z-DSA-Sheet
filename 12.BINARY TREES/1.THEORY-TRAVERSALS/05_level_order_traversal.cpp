/*
102. Binary Tree Level Order Traversal

Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]

Example 2:
Input: root = [1]
Output: [[1]]

Example 3:
Input: root = []
Output: []


Constraints:
The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000
*/

#include <iostream>
#include <vector>
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

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> ans;

    if (root == nullptr)
    {
        return ans;
    }

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;

        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();

            level.push_back(node->val);

            if (node->left != nullptr)
            {
                q.push(node->left);
            }

            if (node->right != nullptr)
            {
                q.push(node->right);
            }
        }

        ans.push_back(level);
    }

    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> ans = levelOrder(root);

    cout << "[";
    for (int i = 0; i < ans.size(); i++)
    {
        if (i > 0)
        {
            cout << ",";
        }

        cout << "[";
        for (int j = 0; j < ans[i].size(); j++)
        {
            if (j > 0)
            {
                cout << ",";
            }
            cout << ans[i][j];
        }
        cout << "]";
    }
    cout << "]" << endl;

    return 0;
}