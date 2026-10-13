/*
101. Symmetric Tree

Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

Example 1:
Input: root = [1,2,2,3,4,4,3]
Output: true

Example 2:
Input: root = [1,2,2,null,3,null,3]
Output: false

Constraints:
The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100
*/

#include <iostream>
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

bool BruteIsSymmetric(TreeNode *root)
{
    if (root == nullptr)
    {
        return true;
    }

    stack<pair<TreeNode *, TreeNode *>> st;
    st.push({root->left, root->right});

    while (!st.empty())
    {
        auto [node1, node2] = st.top();
        st.pop();

        if (node1 == nullptr && node2 == nullptr)
        {
            continue;
        }

        if (node1 == nullptr || node2 == nullptr || node1->val != node2->val)
        {
            return false;
        }

        st.push({node1->left, node2->right});
        st.push({node1->right, node2->left});
    }

    return true;
}

bool isMirror(TreeNode *left, TreeNode *right)
{
    if (left == nullptr || right == nullptr)
    {
        return left == right;
    }

    return left->val == right->val && isMirror(left->left, right->right) && isMirror(left->right, right->left);
}

bool OptimalIsSymmetric(TreeNode *root)
{
    return root == nullptr || isMirror(root->left, root->right);
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->right->right = new TreeNode(3);

    cout << "Brute: " << (BruteIsSymmetric(root) ? "BT is symmetrical" : "BT is not symmetrical") << endl;
    cout << "Optimal: " << (OptimalIsSymmetric(root) ? "BT is symmetrical" : "BT is not symmetrical") << endl;

    return 0;
}