/*
Minimum in BST

Given a Binary Search Tree, find the minimum in the given BST.

Examples
Input: root = [5, 4, 6, 3, N, N, 7, 1]
Output: 1
Explanation: The minimum element in the given BST is 1.

Input: root = [10, 5, 20, 2]
Output: 2
Explanation: The minimum element in the given BST is 2.

Input: root = []
Output: -1
Explanation: The root of the BST is NULL.

Constraints:
0 ≤ size of binary tree, node.data ≤ 5*105
*/

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Using Inorder Traversal - O(n) Time and O(n) Space

void inorder(TreeNode* root, vector<int>& sortedInorder) {
    if(root == nullptr) {
        return;
    }

    inorder(root->left, sortedInorder);
    sortedInorder.push_back(root->val);
    inorder(root->right, sortedInorder);
}

int BruteMinimumBST(TreeNode* root) {
    if(root == nullptr) {
        return -1;
    }

    vector<int> sortedInorder;

    inorder(root, sortedInorder);

    return sortedInorder[0];
}

// Using Recursion - O(h) Time and O(h) Space

int BetterMinimumBST(TreeNode* root) {
    if(root == nullptr) {
        return -1;
    }

    if(root->left == nullptr) return root->val;

    return BetterMinimumBST(root->left);
}

// Using Iterative Way - O(h) Time and O(1) Space

int OptimalMinimumBST(TreeNode* root) {
    if(root == nullptr) {
        return -1;
    }

    TreeNode* curr = root;
    
    while(curr->left != nullptr) {
        curr = curr->left;
    }

    return curr->val;
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(3);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(1);

    cout << "Minimum (Inorder): " << BruteMinimumBST(root) << '\n';
    cout << "Minimum (Recursive): " << BetterMinimumBST(root) << '\n';
    cout << "Minimum (Iterative): " << OptimalMinimumBST(root) << '\n';

    return 0;
}