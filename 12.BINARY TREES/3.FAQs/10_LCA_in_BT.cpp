/*
236. Lowest Common Ancestor of a Binary Tree

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Example 1:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.

Example 2:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.

Example 3:
Input: root = [1,2], p = 1, q = 2
Output: 1

Constraints:
The number of nodes in the tree is in the range [2, 105].
-109 <= Node.val <= 109
All Node.val are unique.
p != q
p and q will exist in the tree.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>
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

bool findPath(TreeNode *node, TreeNode *target, vector<TreeNode *> &path)
{
    if (node == nullptr)
    {
        return false;
    }

    path.push_back(node);

    if (node == target)
    {
        return true;
    }

    if (findPath(node->left, target, path) || findPath(node->right, target, path))
    {
        return true;
    }

    path.pop_back();

    return false;
}

TreeNode *BruteLowestCommonAncestors(TreeNode *root, TreeNode *p, TreeNode *q)
{
    vector<TreeNode *> pathP;
    vector<TreeNode *> pathQ;

    findPath(root, p, pathP);
    findPath(root, q, pathQ);

    TreeNode *lca = nullptr;

    int limit = min(pathP.size(), pathQ.size());

    for (int i = 0; i < limit; i++)
    {
        if (pathP[i] != pathQ[i])
        {
            break;
        }

        lca = pathP[i];
    }

    return lca;
}

TreeNode *BetterLowestCommonAncestors(TreeNode *root, TreeNode *p, TreeNode *q)
{
    unordered_map<TreeNode *, TreeNode *> parent;
    queue<TreeNode *> nodesQueue;

    parent[root] = nullptr;
    nodesQueue.push(root);

    while (parent.find(p) == parent.end() || parent.find(q) == parent.end())
    {
        TreeNode *node = nodesQueue.front();
        nodesQueue.pop();

        if (node->left != nullptr)
        {
            parent[node->left] = node;
            nodesQueue.push(node->left);
        }

        if (node->right != nullptr)
        {
            parent[node->right] = node;
            nodesQueue.push(node->right);
        }
    }

    unordered_set<TreeNode *> ancestors;

    TreeNode *current = p;

    while (current != nullptr)
    {
        ancestors.insert(current);
        current = parent[current];
    }

    current = q;

    while (ancestors.find(current) == ancestors.end())
    {
        current = parent[current];
    }

    return current;
}

TreeNode *OptimalLowestCommonAncestors(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    if (root == p || root == q)
    {
        return root;
    }

    TreeNode *left = OptimalLowestCommonAncestors(root->left, p, q);
    TreeNode *right = OptimalLowestCommonAncestors(root->right, p, q);

    if (left != nullptr && right != nullptr)
    {
        return root;
    }

    if (left != nullptr)
    {
        return left;
    }

    return right;
}

int main()
{
    // Build the example tree: [3,5,1,6,2,0,8,null,null,7,4].
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode *p = root->left;
    TreeNode *q = root->left->right->right;

    TreeNode *bruteLca = BruteLowestCommonAncestors(root, p, q);
    TreeNode *betterLca = BetterLowestCommonAncestors(root, p, q);
    TreeNode *optimalLca = OptimalLowestCommonAncestors(root, p, q);

    cout << "Brute LCA: " << (bruteLca ? bruteLca->val : -1) << endl;
    cout << "Better LCA: " << (betterLca ? betterLca->val : -1) << endl;
    cout << "Optimal LCA: " << (optimalLca ? optimalLca->val : -1) << endl;

    return 0;
}