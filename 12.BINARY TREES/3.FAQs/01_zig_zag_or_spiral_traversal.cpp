/*
103. Binary Tree Zigzag Level Order Traversal

Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]

Example 2:
Input: root = [1]
Output: [[1]]

Example 3:
Input: root = []
Output: []


Constraints:
The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100
*/

#include <iostream>
#include <queue>
#include <vector>
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

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> result;

    if (root == nullptr)
    {
        return result;
    }

    queue<TreeNode *> q;
    q.push(root);

    bool leftToRight = true;

    while (!q.empty())
    {
        int size = q.size();
        vector<int> level(size);

        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();

            int index = leftToRight ? i : size - 1 - i;
            level[index] = node->val;

            if (node->left != nullptr)
            {
                q.push(node->left);
            }

            if (node->right != nullptr)
            {
                q.push(node->right);
            }
        }

        result.push_back(level);
        leftToRight = !leftToRight;
    }

    return result;
}

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> result = zigzagLevelOrder(root);

    cout << "Zigzag Level Order Traversal:" << endl;
    for (const vector<int> &level : result)
    {
        for (int value : level)
        {
            cout << value << " ";
        }
        cout << " ";
    }

    return 0;
}