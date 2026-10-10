/*
182. Pre, Post, Inorder in one traversal
Given a binary tree with root node. Return the In-order,Pre-order and Post-order traversal of the binary tree.

Example 1:
Input : root = [1, 3, 4, 5, 2, 7, 6 ]

Output : [ [5, 3, 2, 1, 7, 4, 6] , [1, 3, 5, 2, 4, 7, 6] , [5, 2, 3, 7, 6, 4, 1] ]

Explanation : The In-order traversal is [5, 3, 2, 1, 7, 4, 6].

The Pre-order traversal is [1, 3, 5, 2, 4, 7, 6].

The Post-order traversal is [5, 2, 3, 7, 6, 4, 1].



Example 2:
Input : root = [1, 2, 3, null, null, null, 6 ]

Output : [ [2, 1, 3, 6] , [1, 2, 3, 6] , [2, 6, 3, 1] ]

Explanation : The In-order traversal is [2, 1, 3, 6].

The Pre-order traversal is [1, 2, 3, 6].

The Post-order traversal is [2, 6, 3, 1].

Constraints:
1 <= Number of Nodes <= 105
0 <= Node.val <= 105
*/

#include <iostream>
#include <vector>
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

// 1. Iterative Preorder: Root -> Left -> Right

vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> ans;

    if (root == nullptr)
    {
        return ans;
    }

    stack<TreeNode *> st;
    st.push(root);

    while (!st.empty())
    {
        TreeNode *node = st.top();
        st.pop();

        ans.push_back(node->val);

        if (node->right != nullptr)
        {
            st.push(node->right);
        }

        if (node->left != nullptr)
        {
            st.push(node->left);
        }
    }

    return ans;
}

// 2. Iterative Inorder: Left -> Root -> Right

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> ans;

    if (root == nullptr)
    {
        return ans;
    }

    stack<TreeNode *> st;
    TreeNode *curr = root;

    while (curr != nullptr || !st.empty())
    {
        while (curr != nullptr)
        {
            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        st.pop();

        ans.push_back(curr->val);
        curr = curr->right;
    }

    return ans;
}

// 3. Iterative Postorder using TWO stacks: Left -> Right -> Root

vector<int> postorderTwoStacks(TreeNode *root)
{
    vector<int> ans;

    if (root == nullptr)
    {
        return ans;
    }

    stack<TreeNode *> st1, st2;
    st1.push(root);

    while (!st1.empty())
    {
        TreeNode *node = st1.top();
        st1.pop();

        st2.push(node);

        if (node->left != nullptr)
        {
            st1.push(node->left);
        }

        if (node->right != nullptr)
        {
            st1.push(node->right);
        }
    }

    while (!st2.empty())
    {
        ans.push_back(st2.top()->val);
        st2.pop();
    }

    return ans;
}

// 4. Iterative Postorder using ONE stack

vector<int> postorderOneStack(TreeNode *root)
{
    vector<int> ans;

    if (root == nullptr)
    {
        return ans;
    }

    stack<TreeNode *> st;
    TreeNode *curr = root;
    TreeNode *lastVisited = nullptr;

    while (curr != nullptr || !st.empty())
    {
        if (curr != nullptr)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            TreeNode *node = st.top();

            if (node->right != nullptr && lastVisited != node->right)
            {
                curr = node->right;
            }
            else
            {
                ans.push_back(node->val);
                lastVisited = node;
                st.pop();
            }
        }
    }

    return ans;
}

vector<vector<int>> getTreeTraversal(TreeNode *root)
{
    vector<int> in = inorderTraversal(root);
    vector<int> pre = preorderTraversal(root);
    vector<int> post1 = postorderOneStack(root);
    vector<int> post2 = postorderTwoStacks(root);

    return {in, pre, post1, post2};
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(6);

    vector<vector<int>> ans = getTreeTraversal(root);

    cout << "Inorder: ";
    for (int x : ans[0])
        cout << x << " ";
    cout << "\n";

    cout << "Preorder: ";
    for (int x : ans[1])
        cout << x << " ";
    cout << "\n";

    cout << "Postorder (1-stack): ";
    for (int x : ans[2])
        cout << x << " ";
    cout << "\n";

    cout << "Postorder (2-stack): ";
    for (int x : ans[3])
        cout << x << " ";
    cout << "\n";

    return 0;
}