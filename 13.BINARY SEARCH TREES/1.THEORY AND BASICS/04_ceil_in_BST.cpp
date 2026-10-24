/*
Ceil in BST

Given a root binary search tree and an integer x , find the Ceil of x in the tree.

Ceil(x) is a number that is either equal to x or is immediately greater than x. If Ceil could not be found, return -1.

Examples:

Input: root = [5, 1, 7, N, 2, N, N, N, 3], x = 3
Output: 3
Explanation: We find 3 in BST, so ceil of 3 is 3.

Input: root = [10, 5, 11, 4, 7, N, N, N, N, N, 8], x = 6
Output: 7
Explanation: We find 7 in BST, so ceil of 6 is 7.

Constraints:
1 ≤ size of binary tree, node.data ≤ 105
*/

#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Using Recursion - O(h) Time and O(h) Space

int ceilRecursive(TreeNode* root, int x) {
    if (root == nullptr) {
        return -1;
    }

    if (root->val == x) {
        return root->val;
    }

    if (x > root->val) {
        return ceilRecursive(root->right, x);
    }

    int leftCeil = ceilRecursive(root->left, x);
    return (leftCeil != -1) ? leftCeil : root->val;
}

// Using Iterative Way - O(h) Time and O(1) Space

int ceilIterative(TreeNode* root, int x) {
    int ceil = -1;

    while (root != nullptr) {
        if (root->val == x) {
            return root->val;
        }

        if (x < root->val) {
            ceil = root->val;
            root = root->left;
        }
        else {
            root = root->right;
        }
    }

    return ceil;
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(7);
    root->left->right = new TreeNode(2);
    root->left->right->right = new TreeNode(3);

    int x1 = 3;
    int x2 = 6;

    cout << "Recursive Ceil of " << x1 << " is: " << ceilRecursive(root, x1) << endl;
    cout << "Iterative Ceil of " << x1 << " is: " << ceilIterative(root, x1) << endl;

    cout << "Recursive Ceil of " << x2 << " is: " << ceilRecursive(root, x2) << endl;
    cout << "Iterative Ceil of " << x2 << " is: " << ceilIterative(root, x2) << endl;

    return 0;
}