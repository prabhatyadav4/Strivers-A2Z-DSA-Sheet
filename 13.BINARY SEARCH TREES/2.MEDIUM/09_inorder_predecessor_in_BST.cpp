/*
Inorder Predecessor in BST

Given a BST, and a reference to a Node k in the BST. Find the Inorder Predecessor of the given node in the BST. If there is no predecessor, return -1.

Examples:

Input: root = [2, 1, 3], k = 2
Output: 1
Explanation: Inorder traversal: 1 2 3. Hence, inorder predecessor of 2 is 1.

Input: root = [20, 8, 22, 4, 12, N, N, N, N, 10, 14], k = 8
Output: 4
Explanation: Inorder traversal: 4 8 10 12 14 20 22. Hence, predecessor of 8 is 4.

Constraints:
1 ≤ n ≤ 10^5, where n is the number of nodes
*/

#include <iostream>
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

void inorder(TreeNode *root, vector<int> &ans)
{
    if (root == nullptr)
    {
        return;
    }

    inorder(root->left, ans);
    ans.push_back(root->val);
    inorder(root->right, ans);
}

int BruteInorderPredecessor(TreeNode *root, TreeNode *x)
{
    if (root == nullptr || x == nullptr)
    {
        return -1;
    }

    vector<int> ans;

    inorder(root, ans);

    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i] == x->val)
        {
            if (i > 0)
            {
                return ans[i - 1];
            }

            return -1;
        }
    }

    return -1;
}

void inorderHelper(TreeNode *root, TreeNode *x, TreeNode *&prev, int &ans)
{
    if (root == nullptr || ans != -1)
    {
        return;
    }

    inorderHelper(root->left, x, prev, ans);

    if (root->val == x->val)
    {
        if (prev != nullptr)
        {
            ans = prev->val;
        }

        return;
    }

    prev = root;

    inorderHelper(root->right, x, prev, ans);
}

int BetterInorderPredecessor(TreeNode *root, TreeNode *x)
{
    if (root == nullptr || x == nullptr)
    {
        return -1;
    }

    TreeNode *prev = nullptr;
    int ans = -1;

    inorderHelper(root, x, prev, ans);

    return ans;
}

int OptimalInorderPredecessor(TreeNode *root, TreeNode *x)
{
    if (root == nullptr || x == nullptr)
    {
        return -1;
    }

    int predecessor = -1;

    while (root != nullptr)
    {
        if (root->val < x->val)
        {
            predecessor = root->val;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }

    return predecessor;
}

int main()
{
    // Example: [20, 8, 22, 4, 12, N, N, N, N, 10, 14], target = 8
    TreeNode n20(20), n8(8), n22(22), n4(4), n12(12), n10(10), n14(14);

    n20.left = &n8;
    n20.right = &n22;
    n8.left = &n4;
    n8.right = &n12;
    n12.left = &n10;
    n12.right = &n14;

    TreeNode *root = &n20;
    TreeNode *target = &n8;

    cout << "Brute predecessor: " << BruteInorderPredecessor(root, target) << '\n';
    cout << "Better predecessor: " << BetterInorderPredecessor(root, target) << '\n';
    cout << "Optimal predecessor: " << OptimalInorderPredecessor(root, target) << '\n';
    return 0;
}