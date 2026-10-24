/*
Kth Largest Element in a BST

Given the root of a binary search tree, and an integer k, return the kth largest value (1-indexed) of all the values of the nodes in the tree.

Example 1:
Input: root = [3,1,4,null,2], k = 1
Output: 4

Example 2:
Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 4


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

void inorderI(TreeNode *root, int k, vector<int> &ans)
{
    if (root == nullptr)
    {
        return;
    }

    inorderI(root->right, k, ans);
    ans.push_back(root->val);
    inorderI(root->left, k, ans);
}

int kthLargestElementVector(TreeNode *root, int k)
{
    vector<int> ans;

    inorderI(root, k, ans);

    return ans[k - 1];
}

void inorderII(TreeNode *root, int k, int &count, int &ans)
{
    if (root == nullptr || count >= k)
    {
        return;
    }

    inorderII(root->right, k, count, ans);

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

    inorderII(root->left, k, count, ans);
}

int kthLargestElementRecursive(TreeNode *root, int k)
{
    int ans = -1;
    int count = 0;

    inorderII(root, k, count, ans);

    return ans;
}

int kthLargestElementStack(TreeNode *root, int k)
{
    stack<TreeNode *> st;

    while (root != nullptr || !st.empty())
    {
        while (root != nullptr)
        {
            st.push(root);
            root = root->right;
        }

        root = st.top();
        st.pop();

        k--;

        if (k == 0)
        {
            return root->val;
        }

        root = root->left;
    }

    return -1;
}

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);

    int k = 3;

    cout << "Vector Approach: " << kthLargestElementVector(root, k) << endl;
    cout << "Recursive Approach: " << kthLargestElementRecursive(root, k) << endl;
    cout << "Stack Approach: " << kthLargestElementStack(root, k) << endl;

    return 0;
}