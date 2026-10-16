/*
180. Top View of BT

Given the root of a binary tree, return the top view of the binary tree.

The top view of a binary tree consists of the set of nodes visible when the tree is observed from above.

Return the values of these nodes ordered from the leftmost to the rightmost position.

If multiple nodes share the same horizontal distance from the root, only the node that appears first when traversing from left to right (i.e., the leftmost node) should be included in the result.

Example 1:
Input : root = [1, 2, 3, 4, 5, 6, 7]
Output : [4, 2, 1, 3, 7]

Example 2:
Input : root = [10, 20, 30, 40, 60, 90, 100]
Output : [40, 20, 10, 30, 100]

Constraints:
1 <= Number of Nodes <= 104
-103 <= Node.val <= 103
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
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

// Approach 1: BFS + ordered map

vector<int> BruteTopView(TreeNode *root)
{
    vector<int> result;

    if (root == nullptr)
    {
        return result;
    }

    map<int, int> topNodes;

    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        auto [node, hd] = q.front();
        q.pop();

        if (topNodes.find(hd) == topNodes.end())
        {
            topNodes[hd] = node->val;
        }

        if (node->left != nullptr)
        {
            q.push({node->left, hd - 1});
        }

        if (node->right != nullptr)
        {
            q.push({node->right, hd + 1});
        }
    }

    for (auto &entry : topNodes)
    {
        result.push_back(entry.second);
    }

    return result;
}

// Approach 2: BFS + unordered map

vector<int> OptimalTopView(TreeNode *root)
{
    vector<int> result;

    if (root == nullptr)
    {
        return result;
    }

    unordered_map<int, int> topNodes;
    queue<pair<TreeNode *, int>> q;

    int minHD = 0, maxHD = 0;
    q.push({root, 0});

    while (!q.empty())
    {
        auto [node, hd] = q.front();
        q.pop();

        if (topNodes.find(hd) == topNodes.end())
        {
            topNodes[hd] = node->val;
        }

        minHD = min(minHD, hd);
        maxHD = max(maxHD, hd);

        if (node->left != nullptr)
        {
            q.push({node->left, hd - 1});
        }

        if (node->right != nullptr)
        {
            q.push({node->right, hd + 1});
        }
    }

    for (int hd = minHD; hd <= maxHD; hd++)
    {
        result.push_back(topNodes[hd]);
    }

    return result;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<int> bruteResult = BruteTopView(root);
    vector<int> optimalResult = OptimalTopView(root);

    cout << "Brute top view: ";
    for (int value : bruteResult)
    {
        cout << value << " ";
    }
    cout << "\nOptimal top view: ";
    for (int value : optimalResult)
    {
        cout << value << " ";
    }
    cout << '\n';

    return 0;
}