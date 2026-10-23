/*
701. Insert into a Binary Search Tree

You are given the root node of a binary search tree (BST) and a value to insert into the tree. Return the root node of the BST after the insertion.
It is guaranteed that the new value does not exist in the original BST.

Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.



Example 1:
Input: root = [4,2,7,1,3], val = 5
Output: [4,2,7,1,3,5]
Explanation: Another accepted tree is:

Example 2:
Input: root = [40,20,60,10,30,50,70], val = 25
Output: [40,20,60,10,30,50,70,null,null,25]

Example 3:
Input: root = [4,2,7,1,3,null,null,null,null,null,null], val = 5
Output: [4,2,7,1,3,5]


Constraints:
The number of nodes in the tree will be in the range [0, 104].
-108 <= Node.val <= 108
All the values Node.val are unique.
-108 <= val <= 108
It's guaranteed that val does not exist in the original BST.
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