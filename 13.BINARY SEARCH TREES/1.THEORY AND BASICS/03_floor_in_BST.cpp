/*
Floor in BST

Given a binary search tree and a number k, find the greatest number in the binary search tree that is less than or equal to k.

Note: If no such node value exists that is smaller than k, then return -1.

Examples:

Input: root = [10, 7, 15, 2, 8, 11, 16],  k  =  14
Output: 11
Explanation: The greatest element in the tree which is less than or equal to 14, is 11.

Input: root = [5, 2, 12, 1, 3, 9, 21, N, N, N, N, N, N, 19, 25],  k  = 24
Output: 21
Explanation: The greatest element in the tree which is less than or equal to 24, is 21.

Input: root = [5, 2, 12, 1, 3, 9, 21, N, N, N, N, N, N, 19, 25], k = 4
Output: 3
Explanation: The greatest element in the tree which is less than or equal to 4, is 3.

Constraints:
1 ≤ size of binary tree, node.data, k ≤ 105
All node values in root are unique.
*/

#include <iostream>
using namespace std;

// Using Recursion - O(h) Time and O(h) Space

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

int floorRecursive(TreeNode *root, int x)
{
    if (root == nullptr)
    {
        return -1;
    }

    if (root->val == x)
    {
        return root->val;
    }

    if (x < root->val)
    {
        return floorRecursive(root->left, x);
    }

    int floorValue = floorRecursive(root->right, x);

    return (floorValue <= x && floorValue != -1) ? floorValue : root->val;
}

// Iterative Solution- O(h) Time and O(1) Space

int floorIterative(TreeNode *root, int x)
{
    int floor = -1;

    while (root != nullptr)
    {
        if (root->val == x)
        {
            return root->val;
        }

        if (x < root->val)
        {
            root = root->left;
        }
        else
        {
            floor = root->val;
            root = root->right;
        }
    }

    return floor;
}

int main()
{
    TreeNode root(10);
    TreeNode node7(7), node15(15);
    TreeNode node2(2), node8(8), node11(11), node16(16);

    root.left = &node7;
    root.right = &node15;
    node7.left = &node2;
    node7.right = &node8;
    node15.left = &node11;
    node15.right = &node16;

    int x = 14;
    cout << "Recursive floor: " << floorRecursive(&root, x) << '\n';
    cout << "Iterative floor: " << floorIterative(&root, x) << '\n';

    return 0;
}