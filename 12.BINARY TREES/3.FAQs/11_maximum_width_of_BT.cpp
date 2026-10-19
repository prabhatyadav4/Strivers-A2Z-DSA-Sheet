/*
662. Maximum Width of Binary Tree

Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

It is guaranteed tat the answer will in the range of a 32-bit signed integer.

Example 1:
Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).

Example 2:
Input: root = [1,3,2,5,null,null,9,6,null,7]
Output: 7
Explanation: The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7).

Example 3:
Input: root = [1,3,2,5]
Output: 2
Explanation: The maximum width exists in the second level with length 2 (3,2).

Constraints:
The number of nodes in the tree is in the range [1, 3000].
-100 <= Node.val <= 100
*/

#include <iostream>
#include <vector>
#include <queue>
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

vector<unsigned long long> firstIndex;
unsigned long long ans = 0;

void dfs(TreeNode *node, int depth, unsigned long long index)
{
    if (node == nullptr)
    {
        return;
    }

    if (depth == firstIndex.size())
    {
        firstIndex.push_back(index);
    }

    unsigned long long idx = index - firstIndex[depth];

    ans = max(ans, idx + 1);

    dfs(node->left, depth + 1, 2 * idx);
    dfs(node->right, depth + 1, 2 * idx + 1);
}

int BruteWidthOfBinaryTree(TreeNode *root)
{
    firstIndex.clear();
    ans = 0;
    dfs(root, 0, 0);

    return static_cast<int>(ans);
}

int BetterWidthOfBinaryTree(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    queue<pair<TreeNode *, unsigned long long>> q;
    q.push({root, 0});

    unsigned long long ans = 0;

    while (!q.empty())
    {
        int n = q.size();

        unsigned long long first = q.front().second;
        unsigned long long last = first;

        for (int i = 0; i < n; i++)
        {
            auto [node, index] = q.front();
            q.pop();

            last = index;

            if (node->left)
            {
                q.push({node->left, 2 * index});
            }

            if (node->right)
            {
                q.push({node->right, 2 * index + 1});
            }
        }

        ans = max(ans, last - first + 1);
    }

    return static_cast<int>(ans);
}

int OptimalWidthOfBinaryTree(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    queue<pair<TreeNode *, unsigned long long>> q;
    q.push({root, 0});

    unsigned long long ans = 0;

    while (!q.empty())
    {
        int n = q.size();
        unsigned long long base = q.front().second;
        unsigned long long first = 0, last = 0;

        for (int i = 0; i < n; i++)
        {
            auto [node, rawIndex] = q.front();
            q.pop();

            unsigned long long idx = rawIndex - base;

            if (i == 0)
            {
                first = idx;
            }

            if (i == n - 1)
            {
                last = idx;
            }

            if (node->left)
            {
                q.push({node->left, 2 * idx});
            }

            if (node->right)
            {
                q.push({node->right, 2 * idx + 1});
            }
        }

        ans = max(ans, last - first + 1);
    }

    return static_cast<int>(ans);
}

int main()
{
    TreeNode *example1 = new TreeNode(1);
    example1->left = new TreeNode(3);
    example1->right = new TreeNode(2);
    example1->left->left = new TreeNode(5);
    example1->left->right = new TreeNode(3);
    example1->right->right = new TreeNode(9);

    TreeNode *example2 = new TreeNode(1);
    example2->left = new TreeNode(3);
    example2->right = new TreeNode(2);
    example2->left->left = new TreeNode(5);
    example2->right->right = new TreeNode(9);
    example2->left->left->left = new TreeNode(6);
    example2->right->right->right = new TreeNode(7);

    TreeNode *example3 = new TreeNode(1);
    example3->left = new TreeNode(3);
    example3->right = new TreeNode(2);
    example3->left->left = new TreeNode(5);

    vector<pair<TreeNode *, int>> tests = {
        {example1, 4},
        {example2, 7},
        {example3, 2}};

    for (int i = 0; i < tests.size(); i++)
    {
        TreeNode *root = tests[i].first;
        int expected = tests[i].second;
        cout << "Example " << i + 1 << " (expected " << expected << "): "
             << "Brute=" << BruteWidthOfBinaryTree(root)
             << ", Better=" << BetterWidthOfBinaryTree(root)
             << ", Optimal=" << OptimalWidthOfBinaryTree(root) << '\n';
    }
}