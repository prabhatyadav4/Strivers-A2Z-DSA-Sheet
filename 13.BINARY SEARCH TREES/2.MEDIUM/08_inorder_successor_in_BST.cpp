/*
Inorder Successor in BST

Given a BST, and a reference to a Node k in the BST. Find the Inorder Successor of the given node in the BST. If there is no successor, return -1.

Examples :

Input: root = [2, 1, 3], k = 2
Output: 3
Explanation: Inorder traversal : 1 2 3 Hence, inorder successor of 2 is 3.

Input: root = [20, 8, 22, 4, 12, N, N, N, N, 10, 14], k = 8
Output: 10
Explanation: Inorder traversal: 4 8 10 12 14 20 22. Hence, successor of 8 is 10.

Constraints:
1 ≤ n ≤ 105, where n is the number of nodes
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
        this->right = nullptr;
        this->left = nullptr;
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

int BruteInorderSuccessor(TreeNode *root, TreeNode *x)
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
            if (i + 1 < ans.size())
            {
                return ans[i + 1];
            }

            return -1;
        }
    }

    return -1;
}

void reverseInorder(TreeNode *root, TreeNode *x, TreeNode *&prev, int &ans)
{
    if (root == nullptr || ans != -1)
    {
        return;
    }

    reverseInorder(root->right, x, prev, ans);

    if (root->val == x->val)
    {
        if (prev != nullptr)
        {
            ans = prev->val;
        }

        return;
    }

    prev = root;

    reverseInorder(root->left, x, prev, ans);
}

int BetterInorderSuccessor(TreeNode *root, TreeNode *x)
{
    if (root == nullptr || x == nullptr)
    {
        return -1;
    }

    TreeNode *prev = nullptr;
    int ans = -1;

    reverseInorder(root, x, prev, ans);

    return ans;
}

int OptimalInorderSuccessor(TreeNode *root, TreeNode *x)
{
    if (root == nullptr || x == nullptr)
    {
        return -1;
    }

    int successor = -1;

    while (root != nullptr)
    {
        if (x->val < root->val)
        {
            successor = root->val;
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }

    return successor;
}

int main()
{
    //        20
    //       /  \\
    //      8    22
    //     / \\
    //    4  12
    //       / \\
    //      10  14
    TreeNode *root = new TreeNode(20);
    root->left = new TreeNode(8);
    root->right = new TreeNode(22);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(12);
    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(14);

    TreeNode *target = root->left;
    cout << "Brute: " << BruteInorderSuccessor(root, target) << '\n';
    cout << "Better: " << BetterInorderSuccessor(root, target) << '\n';
    cout << "Optimal: " << OptimalInorderSuccessor(root, target) << '\n';

    return 0;
}