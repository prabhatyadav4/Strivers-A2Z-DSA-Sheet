/*
113. Bottom view of BT

Given root of binary tree, return the bottom view of the binary tree.

The bottom view of a binary tree is the set of nodes visible when the tree is viewed from the bottom. Return nodes from the leftmost node to the rightmost node. Also if 2 nodes are outside the shadow of the tree and are at the same position then consider the node that appears later in level traversal.

Example 1:
Input : root = [20, 8, 22, 5, 3, null, 25, null, null, 10 ,14]

Output : [5, 10, 3, 14, 25]

Explanation : From left to right the path is as follows :

First we encounter node with value 5.

Then we have nodes 8 , 10 but from bottom only 10 will be visible.

Next we have 20 , 3 but from bottom only 3 will be visible.

Next we have 14 , 22 but from bottom only 14 will be visible.

Then we encounter node with value 25.



Example 2:
Input : root = [20, 8, 22, 5, 3, 4, 25, null, null, 10 ,14]

Output : [5, 10, 4, 14, 25]

Explanation : From left to right the path is as follows :

First we encounter node with value 5.

Then we have nodes 8 , 10 but from bottom only 10 will be visible.

Next we have 20 , 3 and 4. The 3 and 4 will be nodes visible from bottom but as the node 4 appears later from left to right , so only node 4 will be considered visible.

Next we have 14 , 22 but from bottom only 14 will be visible.

Then we encounter node with value 25.

Constraints:
1 <= Number of Nodes <= 104
-103 <= Node.val <= 103
*/

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <tuple>
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

vector<int> BruteBottomView(TreeNode *root)
{
    vector<int> ans;

    if (root == nullptr)
    {
        return ans;
    }

    // horizontal distance -> {depth, value}
    map<int, pair<int, int>> mp;

    // {node, horizontal distance, depth}
    queue<tuple<TreeNode *, int, int>> q;

    q.push({root, 0, 0});

    while (!q.empty())
    {
        auto [node, hd, depth] = q.front();
        q.pop();

        if (mp.find(hd) == mp.end() || depth >= mp[hd].first)
        {
            mp[hd] = {depth, node->val};
        }

        if (node->left)
        {
            q.push({node->left, hd - 1, depth + 1});
        }

        if (node->right)
        {
            q.push({node->right, hd + 1, depth + 1});
        }
    }

    for (auto &it : mp)
    {
        ans.push_back(it.second.second);
    }

    return ans;
}

vector<int> OptimalBottomView(TreeNode *root)
{
    vector<int> ans;

    if (root == nullptr)
    {
        return ans;
    }

    map<int, int> mp;
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        auto [node, hd] = q.front();
        q.pop();

        mp[hd] = node->val;

        if (node->left)
        {
            q.push({node->left, hd - 1});
        }

        if (node->right)
        {
            q.push({node->right, hd + 1});
        }
    }

    for (auto it : mp)
    {
        ans.push_back(it.second);
    }

    return ans;
}

int main()
{
    // Example 2: node 4 appears later than node 3 at the same horizontal distance.
    TreeNode *root = new TreeNode(20);
    root->left = new TreeNode(8);
    root->right = new TreeNode(22);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(25);
    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(14);

    vector<int> brute = BruteBottomView(root);
    vector<int> optimal = OptimalBottomView(root);

    cout << "Brute bottom view: ";
    for (int value : brute)
    {
        cout << value << " ";
    }

    cout << "\nOptimal bottom view: ";
    for (int value : optimal)
    {
        cout << value << " ";
    }
    cout << '\n';
}