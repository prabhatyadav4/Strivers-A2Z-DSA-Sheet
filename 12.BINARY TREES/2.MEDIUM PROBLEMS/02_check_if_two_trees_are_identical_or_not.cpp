/*
100. Same Tree

Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

Example 1:
Input: p = [1,2,3], q = [1,2,3]
Output: true

Example 2:
Input: p = [1,2], q = [1,null,2]
Output: false

Example 3:
Input: p = [1,2,1], q = [1,1,2]
Output: false


Constraints:
The number of nodes in both trees is in the range [0, 100].
-104 <= Node.val <= 104
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

bool BruteIsSameTree(TreeNode *p, TreeNode *q)
{
    if (p == nullptr && q == nullptr)
    {
        return true;
    }

    if (p == nullptr || q == nullptr)
    {
        return false;
    }

    if (p->val != q->val)
    {
        return false;
    }

    return BruteIsSameTree(p->left, q->left) && BruteIsSameTree(p->right, q->right);
}

bool BetterIsSameTree(TreeNode *p, TreeNode *q)
{
    stack<pair<TreeNode *, TreeNode *>> st;
    st.push({p, q});

    while (!st.empty())
    {
        auto [node1, node2] = st.top();
        st.pop();

        if (node1 == nullptr && node2 == nullptr)
        {
            continue;
        }

        if (node1 == nullptr || node2 == nullptr)
        {
            return false;
        }

        if (node1->val != node2->val)
        {
            return false;
        }

        st.push({node1->left, node2->left});
        st.push({node1->right, node2->right});
    }

    return true;
}

bool OptimalIsSameTree(TreeNode *p, TreeNode *q)
{
    if (p == nullptr || q == nullptr)
    {
        return p == q;
    }

    return p->val == q->val && OptimalIsSameTree(p->left, q->left) && OptimalIsSameTree(p->right, q->right);
}

int main()
{
    TreeNode *p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    TreeNode *q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    cout << boolalpha;
    cout << "Brute: " << BruteIsSameTree(p, q) << '\n';
    cout << "Iterative: " << BetterIsSameTree(p, q) << '\n';
    cout << "Recursive: " << OptimalIsSameTree(p, q) << '\n';
}