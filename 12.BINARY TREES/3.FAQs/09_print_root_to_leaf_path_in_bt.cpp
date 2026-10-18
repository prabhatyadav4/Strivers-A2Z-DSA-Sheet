/*
257. Binary Tree Paths

You are given the root of a binary tree.

Return all root-to-leaf paths in any order.

A leaf is a node with no children.

Example 1:
Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]

Example 2:
Input: root = [1]
Output: ["1"]


Constraints:
The number of nodes in the tree is in the range [1, 100].
-100 <= Node.val <= 100
*/

#include <iostream>
#include <string>
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

void dfs(TreeNode *node, string currentPath, vector<string> &paths)
{
    if (node == nullptr)
    {
        return;
    }

    if (!currentPath.empty())
    {
        currentPath += "->";
    }

    currentPath += to_string(node->val);

    if (node->left == nullptr && node->right == nullptr)
    {
        paths.push_back(currentPath);
        return;
    }

    dfs(node->left, currentPath, paths);
    dfs(node->right, currentPath, paths);
}

vector<string> BruteBinaryTreePaths(TreeNode *root)
{
    vector<string> paths;

    if (root == nullptr)
    {
        return paths;
    }

    string currentPath = "";

    dfs(root, currentPath, paths);

    return paths;
}

void DFS(TreeNode *node, vector<int> &currentPath, vector<vector<int>> &paths)
{
    if (node == nullptr)
    {
        return;
    }

    currentPath.push_back(node->val);

    if (node->left == nullptr && node->right == nullptr)
    {
        paths.push_back(currentPath);
    }
    else
    {
        DFS(node->left, currentPath, paths);
        DFS(node->right, currentPath, paths);
    }

    currentPath.pop_back();
}

vector<vector<int>> OptimalBinaryTreePaths(TreeNode *root)
{
    vector<vector<int>> paths;

    if (root == nullptr)
    {
        return paths;
    }

    vector<int> currentPath;

    DFS(root, currentPath, paths);

    return paths;
}

int main()
{
    // Example tree: [1, 2, 3, null, 5]
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);

    cout << "BruteBinaryTreePaths:\n";
    vector<string> stringPaths = BruteBinaryTreePaths(root);
    for (const string &path : stringPaths)
    {
        cout << path << '\n';
    }

    cout << "OptimalBinaryTreePaths:\n";
    vector<vector<int>> numberPaths = OptimalBinaryTreePaths(root);
    for (const vector<int> &path : numberPaths)
    {
        for (size_t i = 0; i < path.size(); ++i)
        {
            if (i > 0)
            {
                cout << "->";
            }
            cout << path[i];
        }
        cout << '\n';
    }

    return 0;
}