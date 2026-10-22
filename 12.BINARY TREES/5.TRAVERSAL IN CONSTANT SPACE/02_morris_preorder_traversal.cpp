/*
130. Morris Preorder Traversal

Given root of binary tree, return the preorder traversal of the binary tree.

Morris preorder Traversal is a tree traversal algorithm aiming to achieve a space complexity of O(1) without recursion or an external data structure.

Example 1:
Input : root = [1, 4, null, 4 2]
Output : [1, 4, 4, 2]

Example 2:
Input : root = [1]
Output : [1]
Explanation : Only root node is present.

Constraints:
1 <= Number of Nodes <= 100
-100 Node.val <= 100
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

vector<int> preorderTraversal(TreeNode *root)
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
                result.push_back(curr->val);
                prev->right = curr;
                curr = curr->left;
            }
            else
            {
                prev->right = nullptr;
                curr = curr->right;
            }
        }
    }

    return result;
}

int main()
{
    TreeNode root(1);
    TreeNode left(4);
    TreeNode leftLeft(4);
    TreeNode leftRight(2);

    root.left = &left;
    left.left = &leftLeft;
    left.right = &leftRight;

    vector<int> result = preorderTraversal(&root);
    cout << "Morris Preorder Traversal: ";
    cout << "[";
    for (size_t i = 0; i < result.size(); ++i)
    {
        if (i > 0)
            cout << ", ";
        cout << result[i];
    }
    cout << "]\n";

    return 0;
}