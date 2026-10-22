/*
171. Morris Inorder Traversal

Given root of binary tree, return the Inorder traversal of the binary tree.

Morris Inorder Traversal is a tree traversal algorithm aiming to achieve a space complexity of O(1) without recursion or an external data structure.

Example 1:
Input : root = [1, 4, null, 4, 2]
Output : [4, 4, 2, 1]

Example 2:
Input : root = [1, null, 2, 3]
Output : [1, 3, 2]

Constraints:
1 <= Number of Nodes <= 100
-100 <= Node.val <= 100
*/

#include <iostream>
#include <vector>
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

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> result;

    TreeNode *curr = root;

    while (curr != nullptr)
    {
        if (curr->left == nullptr)
        {
            result.push_back(curr->val);
            curr = curr->right;
        }
        else
        {
            TreeNode *prev = curr->left;

            while (prev->right != nullptr && prev->right != curr)
            {
                prev = prev->right;
            }

            if (prev->right == nullptr)
            {
                prev->right = curr;
                curr = curr->left;
            }
            else
            {
                prev->right = nullptr;
                result.push_back(curr->val);
                curr = curr->right;
            }
        }
    }

    return result;
}

int main()
{
    // Example 1: [1, 4, null, 4, 2]
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(4);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(2);

    vector<int> result = inorderTraversal(root);
    cout << "Morris Inorder Travesal: ";
    
    for (int value : result)
    {
        cout << value << ' ';
    }
    cout << '\n';

    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root;
}