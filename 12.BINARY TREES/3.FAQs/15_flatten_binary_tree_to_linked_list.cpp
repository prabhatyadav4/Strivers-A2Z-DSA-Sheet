/*
114. Flatten Binary Tree to Linked List

Given the root of a binary tree, flatten the tree into a "linked list":
    The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
    The "linked list" should be in the same order as a pre-order traversal of the binary tree.


Example 1:
Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]

Example 2:
Input: root = []
Output: []

Example 3:
Input: root = [0]
Output: [0]


Constraints:
The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100
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

void preorder(TreeNode *node, vector<TreeNode *> &nodes)
{
    if (node == nullptr)
    {
        return;
    }

    nodes.push_back(node);
    preorder(node->left, nodes);
    preorder(node->right, nodes);
}

void flattenRecursiveI(TreeNode *root)
{
    vector<TreeNode *> nodes;
    preorder(root, nodes);

    for (size_t i = 0; i + 1 < nodes.size(); i++)
    {
        nodes[i]->left = nullptr;
        nodes[i]->right = nodes[i + 1];
    }

    if (!nodes.empty())
    {
        nodes.back()->left = nullptr;
        nodes.back()->right = nullptr;
    }
}

TreeNode *previousNode = nullptr;

void flattenRecursiveII(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    flattenRecursiveII(root->right);
    flattenRecursiveII(root->left);

    root->right = previousNode;
    root->left = nullptr;

    previousNode = root;
}

void flattenStack(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    stack<TreeNode *> st;
    st.push(root);

    TreeNode *prev = nullptr;

    while (!st.empty())
    {
        TreeNode *curr = st.top();
        st.pop();

        if (prev != nullptr)
        {
            prev->left = nullptr;
            prev->right = curr;
        }

        if (curr->right)
        {
            st.push(curr->right);
        }

        if (curr->left)
        {
            st.push(curr->left);
        }

        prev = curr;
    }

    prev->left = nullptr;
    prev->right = nullptr;
}

void flattenOptimal(TreeNode *root)
{
    TreeNode *curr = root;

    while (curr != nullptr)
    {
        if (curr->left)
        {
            TreeNode *predecessor = curr->left;

            while (predecessor->right)
            {
                predecessor = predecessor->right;
            }

            predecessor->right = curr->right;

            curr->right = curr->left;
            curr->left = nullptr;
        }

        curr = curr->right;
    }
}

int main()
{
    auto buildSampleTree = []()
    {
        TreeNode *root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(5);
        root->left->left = new TreeNode(3);
        root->left->right = new TreeNode(4);
        root->right->right = new TreeNode(6);
        return root;
    };

    auto printFlattened = [](TreeNode *root)
    {
        while (root != nullptr)
        {
            cout << root->val;
            root = root->right;
            if (root != nullptr)
            {
                cout << " -> ";
            }
        }
        cout << '\n';
    };

    TreeNode *root1 = buildSampleTree();
    flattenRecursiveI(root1);
    cout << "Recursive with preorder list: ";
    printFlattened(root1);

    TreeNode *root2 = buildSampleTree();
    previousNode = nullptr;
    flattenRecursiveII(root2);
    cout << "Reverse recursive: ";
    printFlattened(root2);

    TreeNode *root3 = buildSampleTree();
    flattenStack(root3);
    cout << "Stack: ";
    printFlattened(root3);

    TreeNode *root4 = buildSampleTree();
    flattenOptimal(root4);
    cout << "Optimal: ";
    printFlattened(root4);
}