/*
99. Recover Binary Search Tree

You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

Example 1:
Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]
Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.

Example 2:
Input: root = [3,1,4,null,null,2]
Output: [2,1,4,null,null,3]
Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.


Constraints:
The number of nodes in the tree is in the range [2, 1000].
-231 <= Node.val <= 231 - 1
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        this->val = val;
        this->right = nullptr;
        this->left = nullptr;
    }
};

void inorder(TreeNode *root, vector<int> &values)
{
    if (root == nullptr)
    {
        return;
    }

    inorder(root->left, values);
    values.push_back(root->val);
    inorder(root->right, values);
}

void replaceValues(TreeNode *root, vector<int> &values, int &index)
{
    if (root == nullptr)
    {
        return;
    }

    replaceValues(root->left, values, index);
    root->val = values[index++];
    replaceValues(root->right, values, index);
}

void BruteRecoverTree(TreeNode *root)
{
    vector<int> values;

    inorder(root, values);

    sort(values.begin(), values.end());

    int index = 0;

    replaceValues(root, values, index);
}

void inorderHelper(TreeNode *root, TreeNode *&first, TreeNode *&middle, TreeNode *&last, TreeNode *&prev)
{
    if (root == nullptr)
    {
        return;
    }

    inorderHelper(root->left, first, middle, last, prev);

    if (prev != nullptr && root->val < prev->val)
    {
        if (first == nullptr)
        {
            first = prev;
            middle = root;
        }
        else
        {
            last = root;
        }
    }

    prev = root;
    inorderHelper(root->right, first, middle, last, prev);
}

void OptimalRecoverTree(TreeNode *root)
{
    TreeNode *first = nullptr, *middle = nullptr, *last = nullptr;
    TreeNode *prev = nullptr;

    inorderHelper(root, first, middle, last, prev);

    if (first && last)
    {
        swap(first->val, last->val);
    }
    else if (first && middle)
    {
        swap(first->val, middle->val);
    }
}

int main()
{
    // Build separate copies of [3, 1, 4, null, null, 2], where 2 and 3 are swapped.
    TreeNode bruteRoot(3);
    TreeNode bruteLeft(1);
    TreeNode bruteRight(4);
    TreeNode bruteSwapped(2);
    bruteRoot.left = &bruteLeft;
    bruteRoot.right = &bruteRight;
    bruteRight.left = &bruteSwapped;

    TreeNode betterRoot(3);
    TreeNode betterLeft(1);
    TreeNode betterRight(4);
    TreeNode betterSwapped(2);
    betterRoot.left = &betterLeft;
    betterRoot.right = &betterRight;
    betterRight.left = &betterSwapped;

    BruteRecoverTree(&bruteRoot);
    OptimalRecoverTree(&betterRoot);

    vector<int> bruteValues;
    inorder(&bruteRoot, bruteValues);
    cout << "Brute approach: ";
    for (int value : bruteValues)
    {
        cout << value << ' ';
    }
    cout << '\n';

    vector<int> betterValues;
    inorder(&betterRoot, betterValues);
    cout << "Better approach: ";
    for (int value : betterValues)
    {
        cout << value << ' ';
    }
    cout << '\n';

    return 0;
}