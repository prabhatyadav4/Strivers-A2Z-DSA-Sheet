/*
235. Lowest Common Ancestor of a Binary Search Tree

Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”



Example 1:
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.

Example 2:
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.

Example 3:
Input: root = [2,1], p = 2, q = 1
Output: 2


Constraints:
The number of nodes in the tree is in the range [2, 105].
-109 <= Node.val <= 109
All Node.val are unique.
p != q
p and q will exist in the BST.
*/

#include <iostream>
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

TreeNode *BruteLowestCommonAncestors(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    if (root->val > p->val && root->val > q->val)
    {
        return BruteLowestCommonAncestors(root->left, p, q);
    }
    else if (root->val < p->val && root->val < q->val)
    {
        return BruteLowestCommonAncestors(root->right, p, q);
    }
    else
    {
        return root;
    }
}

TreeNode *OptimalLowestCommonAncestors(TreeNode *root, TreeNode *p, TreeNode *q)
{
    while (root != nullptr)
    {
        if (root->val > p->val && root->val > q->val)
        {
            root = root->left;
        }
        else if (root->val < p->val && root->val < q->val)
        {
            root = root->right;
        }
        else
        {
            return root;
        }
    }

    return nullptr;
}

int main()
{
    // Build the BST from Example 1.
    TreeNode n6(6), n2(2), n8(8), n0(0), n4(4), n7(7), n9(9), n3(3), n5(5);
    n6.left = &n2;
    n6.right = &n8;
    n2.left = &n0;
    n2.right = &n4;
    n8.left = &n7;
    n8.right = &n9;
    n4.left = &n3;
    n4.right = &n5;

    TreeNode *p = &n2;
    TreeNode *q = &n8;

    TreeNode *bruteLCA = BruteLowestCommonAncestors(&n6, p, q);
    TreeNode *optimalLCA = OptimalLowestCommonAncestors(&n6, p, q);

    cout << "Brute LCA: " << (bruteLCA ? bruteLCA->val : -1) << '\n';
    cout << "Optimal LCA: " << (optimalLCA ? optimalLCA->val : -1) << '\n';

    return 0;
}