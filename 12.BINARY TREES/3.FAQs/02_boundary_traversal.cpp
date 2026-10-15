/*
216. Boundary Traversal

Given a root of Binary Tree, perform the boundary traversal of the tree.

The boundary traversal is the process of visiting the boundary nodes of the binary tree in the anticlockwise direction, starting from the root.

The boundary of a binary tree is the concatenation of the root, the left boundary, the leaves ordered from left-to-right, and the reverse order of the right boundary.

The left boundary is the set of nodes defined by the following:

The root node's left child is in the left boundary. If the root does not have a left child, then the left boundary is empty.
If a node in the left boundary and has a left child, then the left child is in the left boundary.
If a node is in the left boundary, has no left child, but has a right child, then the right child is in the left boundary.
The leftmost leaf is not in the left boundary.
The right boundary is similar to the left boundary, except it is the right side of the root's right subtree. Again, the leaf is not part of the right boundary, and the right boundary is empty if the root does not have a right child.

Example 1:
Input : root = [1, 2, 3, 4, 5, 6, 7, null, null, 8, 9]
Output : [1, 2, 4, 8, 9, 6, 7, 3]


Example 2:
Input : root = [1, 2, null, 4, 9, 6, 5, 3, null, null, null, null, null, 7, 8]
Output : [1, 2, 4, 6, 5, 7, 8]

Constraints:
0 <= Number of Nodes <= 104
-103 <= Node.val <= 103
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

bool isLeaf(TreeNode *node)
{
    return node != nullptr &&
           node->left == nullptr && node->right == nullptr;
}

void addLeftBoundary(TreeNode *node, vector<int> &ans)
{
    TreeNode *curr = node->left;

    while (curr != nullptr)
    {
        if (!isLeaf(curr))
        {
            ans.push_back(curr->val);
        }

        if (curr->left != nullptr)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
}

void addLeaves(TreeNode *node, vector<int> &ans)
{
    if (node == nullptr)
    {
        return;
    }

    if (isLeaf(node))
    {
        ans.push_back(node->val);
        return;
    }

    addLeaves(node->left, ans);
    addLeaves(node->right, ans);
}

void addRightBoundary(TreeNode *node, vector<int> &ans)
{
    vector<int> temp;
    TreeNode *curr = node->right;

    while (curr != nullptr)
    {
        if (!isLeaf(curr))
        {
            temp.push_back(curr->val);
        }

        if (curr->right != nullptr)
        {
            curr = curr->right;
        }
        else
        {
            curr = curr->left;
        }
    }

    for (int i = (int)temp.size() - 1; i >= 0; i--)
    {
        ans.push_back(temp[i]);
    }
}

vector<int> boundaryTraversal(TreeNode *root)
{
    vector<int> ans;

    if (root == nullptr)
    {
        return ans;
    }

    if (isLeaf(root))
    {
        ans.push_back(root->val);
        return ans;
    }

    ans.push_back(root->val);

    addLeftBoundary(root, ans);
    addLeaves(root, ans);
    addRightBoundary(root, ans);

    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<int> answer = boundaryTraversal(root);

    cout << "The Binary Tree in anti-clockwise order is: ";
    for (int value : answer)
    {
        cout << value << " ";
    }

    return 0;
}