/*
450. Delete Node in a BST

Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.


Example 1:
Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.

Example 2:
Input: root = [5,3,6,2,4,null,7], key = 0
Output: [5,3,6,2,4,null,7]
Explanation: The tree does not contain a node with value = 0.

Example 3:
Input: root = [], key = 0
Output: []


Constraints:
The number of nodes in the tree is in the range [0, 104].
-105 <= Node.val <= 105
Each node has a unique value.
root is a valid binary search tree.
-105 <= key <= 105
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

TreeNode *getSuccessor(TreeNode *curr)
{
    curr = curr->right;

    while (curr != nullptr && curr->left != nullptr)
    {
        curr = curr->left;
    }

    return curr;
}

TreeNode *delNode(TreeNode *root, int x)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    if (x < root->val)
    {
        root->left = delNode(root->left, x);
    }
    else if (x > root->val)
    {
        root->right = delNode(root->right, x);
    }
    else
    {
        if (root->left == nullptr)
        {
            TreeNode *temp = root->right;
            delete root;
            return temp;
        }
        if (root->right == nullptr)
        {
            TreeNode *temp = root->left;
            delete root;
            return temp;
        }

        TreeNode *succ = getSuccessor(root);
        root->val = succ->val;
        root->right = delNode(root->right, succ->val);
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
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    cout << "Before Deletion: ";
    printInorder(root);
    cout << endl;
    root = delNode(root, 3);
    cout << "After Deletion: ";
    printInorder(root);
    cout << endl;

    return 0;
}