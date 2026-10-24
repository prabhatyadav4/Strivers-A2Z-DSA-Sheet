/*
230. Kth Smallest Element in a BST

Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

Example 1:
Input: root = [3,1,4,null,2], k = 1
Output: 1

Example 2:
Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3


Constraints:
The number of nodes in the tree is n.
1 <= k <= n <= 104
0 <= Node.val <= 104
*/

#include <iostream>
#include <vector>
#include <stack>
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

// Inorder traversal + array (Brute-force approach)

void inorderI(TreeNode *root, int k, vector<int> &ans)
{
    if (root == nullptr)
    {
        return;
    }

    inorderI(root->left, k, ans);
    ans.push_back(root->val);
    inorderI(root->right, k, ans);
}

int kthSmallestVector(TreeNode *root, int k)
{
    vector<int> ans;

    inorderI(root, k, ans);

    return ans[k - 1];
}

// Recursive inorder with a counter

void inorderII(TreeNode *root, int k, int &count, int &ans)
{
    if (root == nullptr || count >= k)
    {
        return;
    }

    inorderII(root->left, k, count, ans);

    if (count >= k)
    {
        return;
    }

    count++;

    if (count == k)
    {
        ans = root->val;
        return;
    }

    inorderII(root->right, k, count, ans);
}

int kthSmallestRecursive(TreeNode *root, int k)
{
    int ans = -1;
    int count = 0;

    inorderII(root, k, count, ans);

    return ans;
}

// Iterative inorder using a stack

int kthSmallestStack(TreeNode *root, int k)
{
    stack<TreeNode *> st;

    while (root != nullptr || !st.empty())
    {
        while (root != nullptr)
        {
            st.push(root);
            root = root->left;
        }

        root = st.top();
        st.pop();

        k--;

        if (k == 0)
        {
            return root->val;
        }

        root = root->right;
    }

    return -1;
}

int main()
{
    // Example: [5, 3, 6, 2, 4, null, null, 1], k = 3
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);

    const int k = 3;
    cout << "Vector Approach: " << kthSmallestVector(root, k) << '\n';
    cout << "Recursive Approach: " << kthSmallestRecursive(root, k) << '\n';
    cout << "Stack Approach: " << kthSmallestStack(root, k) << '\n';

    return 0;
}