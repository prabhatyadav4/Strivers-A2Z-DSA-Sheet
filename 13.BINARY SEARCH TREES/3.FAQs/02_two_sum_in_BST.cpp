/*
653. Two Sum IV - Input is a BST

Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.

Example 1:
Input: root = [5,3,6,2,4,null,7], k = 9
Output: true

Example 2:
Input: root = [5,3,6,2,4,null,7], k = 28
Output: false


Constraints:
The number of nodes in the tree is in the range [1, 104].
-104 <= Node.val <= 104
root is guaranteed to be a valid binary search tree.
-105 <= k <= 105
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <stack>
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

// Brute force	    TC-> O(n^2)     SC-> O(n)

void inorder(TreeNode *root, vector<int> &ans)
{
    if (root == nullptr)
    {
        return;
    }

    inorder(root->left, ans);
    ans.push_back(root->val);
    inorder(root->right, ans);
}

bool findTargetI(TreeNode *root, int k)
{
    vector<int> ans;
    inorder(root, ans);

    int n = ans.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ans[i] + ans[j] == k)
            {
                return true;
            }
        }
    }

    return false;
}

// Hash set	        TC-> O(n)	SC-> O(n)

bool solve(TreeNode *root, int k, unordered_set<int> &seen)
{
    if (root == nullptr)
    {
        return false;
    }

    int complement = k - root->val;

    if (seen.count(complement))
    {
        return true;
    }

    seen.insert(root->val);

    return solve(root->left, k, seen) || solve(root->right, k, seen);
}

bool findTargetII(TreeNode *root, int k)
{
    unordered_set<int> seen;
    return solve(root, k, seen);
}

// Inorder + two pointers	    TC-> O(n)	SC-> O(n)

bool findTargetIII(TreeNode *root, int k)
{
    vector<int> ans;
    inorder(root, ans);

    if (ans.size() < 2)
    {
        return false;
    }

    int left = 0;
    int right = ans.size() - 1;

    while (left < right)
    {
        int sum = ans[left] + ans[right];

        if (sum == k)
        {
            return true;
        }
        else if (sum < k)
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    return false;
}

// Two BST iterators        TC-> O(n)    SC-> O(h)

class BSTIterator
{
    stack<TreeNode *> st;
    bool reverse;

    void pushAll(TreeNode *root)
    {
        while (root != nullptr)
        {
            st.push(root);

            if (reverse)
            {
                root = root->right;
            }
            else
            {
                root = root->left;
            }
        }
    }

public:
    BSTIterator(TreeNode *root, bool isReverse)
    {
        reverse = isReverse;
        pushAll(root);
    }

    TreeNode *nextNode()
    {
        TreeNode *node = st.top();
        st.pop();

        if (reverse)
        {
            pushAll(node->left);
        }
        else
        {
            pushAll(node->right);
        }

        return node;
    }
};

bool findTargetIV(TreeNode *root, int k)
{
    if (root == nullptr)
    {
        return false;
    }

    BSTIterator ascending(root, false);
    BSTIterator descending(root, true);

    TreeNode *left = ascending.nextNode();
    TreeNode *right = descending.nextNode();

    while (left != right)
    {
        int sum = left->val + right->val;

        if (sum == k)
        {
            return true;
        }
        else if (sum < k)
        {
            left = ascending.nextNode();
        }
        else
        {
            right = descending.nextNode();
        }
    }

    return false;
}

int main()
{
    /*
              5
             / \
            3   6
           / \   \
          2   4   7
    */

    TreeNode *root = new TreeNode(5);

    root->left = new TreeNode(3);
    root->right = new TreeNode(6);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    root->right->right = new TreeNode(7);

    int k = 9;

    cout << boolalpha;

    cout << "Brute Force: "
         << findTargetI(root, k) << endl;

    cout << "Hash Set: "
         << findTargetII(root, k) << endl;

    cout << "Inorder + Two Pointers: "
         << findTargetIII(root, k) << endl;

    cout << "Two BST Iterators: "
         << findTargetIV(root, k) << endl;

    return 0;
}
