/*
BST Insert

Given a root of Binary Search Tree (BST) and an integer key, insert a new node with value key into the BST.
Return the root of the modified tree after the insertion.

Note: If the key is already present in the BST, return the root.

Examples :
Input: root = [2, 1, 3], key = 4
Output: [2, 1, 3, N, N, N, 4]
Explanation: After inserting the node 4, the new tree will be [2, 1, 3, N, N, N, 4].

Input: root = [2, 1, 3, N, N, N, 6], key = 4
Output: [2, 1, 3, N, N, N, 6, 4]
Explanation: After inserting the node 4, the new tree will be [2, 1, 3, N, N, N, 6, 4].

Constraints:
1 ≤ size of binary tree ≤ 105
1 ≤ node.data, key ≤ 109
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

// Using Recursive Insertion - O(h) Time and O(h) Space

TreeNode *insertRecursive(TreeNode *root, int key)
{
    if (root == nullptr)
    {
        return new TreeNode(key);
    }

    if (root->val == key)
    {
        return root;
    }

    if (key < root->val)
    {
        root->left = insertRecursive(root->left, key);
    }
    else
    {
        root->right = insertRecursive(root->right, key);
    }

    return root;
}

// Using Iterative Traversal - O(h) Time and O(1) Space

TreeNode *insertIterative(TreeNode *root, int key)
{
    TreeNode *temp = new TreeNode(key);

    if (root == nullptr)
    {
        return temp;
    }

    TreeNode *curr = root;

    while (curr != nullptr)
    {
        if (curr->val == key)
        {
            return root;
        }
        else if (key < curr->val && curr->left != nullptr)
        {
            curr = curr->left;
        }
        else if (key > curr->val && curr->right != nullptr)
        {
            curr = curr->right;
        }
        else
        {
            break;
        }
    }

    if (key < curr->val)
    {
        curr->left = temp;
    }
    else
    {
        curr->right = temp;
    }

    return root;
}

void printInorder(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main()
{
    TreeNode *recursiveRoot = new TreeNode(2);
    recursiveRoot->left = new TreeNode(1);
    recursiveRoot->right = new TreeNode(3);
    recursiveRoot->right->right = new TreeNode(6);

    TreeNode *iterativeRoot = new TreeNode(2);
    iterativeRoot->left = new TreeNode(1);
    iterativeRoot->right = new TreeNode(3);
    iterativeRoot->right->right = new TreeNode(6);

    recursiveRoot = insertRecursive(recursiveRoot, 4);
    iterativeRoot = insertIterative(iterativeRoot, 4);

    cout << "Recursive insertion: ";
    printInorder(recursiveRoot);
    cout << endl;

    cout << "Iterative insertion: ";
    printInorder(iterativeRoot);
    cout << endl;

    return 0;
}