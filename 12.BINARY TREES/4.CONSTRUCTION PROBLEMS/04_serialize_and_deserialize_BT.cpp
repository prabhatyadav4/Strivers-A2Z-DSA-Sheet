/*
297. Serialize and Deserialize Binary Tree

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

Example 1:
Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]

Example 2:
Input: root = []
Output: []


Constraints:
The number of nodes in the tree is in the range [0, 104].
-1000 <= Node.val <= 1000
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
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

// Approach 1 — DFS preorder

void encode(TreeNode *root, string &result)
{
    if (root == nullptr)
    {
        result += "#,";
        return;
    }

    result += to_string(root->val) + ",";
    encode(root->left, result);
    encode(root->right, result);
}

string serializeI(TreeNode *root)
{
    string result = "";
    encode(root, result);
    return result;
}

TreeNode *decode(vector<string> &nodes, int &index)
{
    if (index >= (int)nodes.size() || nodes[index] == "#")
    {
        index++;
        return nullptr;
    }

    TreeNode *root = new TreeNode(stoi(nodes[index]));
    index++;

    root->left = decode(nodes, index);
    root->right = decode(nodes, index);

    return root;
}

TreeNode *deserializeI(string data)
{
    stringstream ss(data);
    string token;
    vector<string> nodes;

    while (getline(ss, token, ','))
    {
        if (!token.empty())
        {
            nodes.push_back(token);
        }
    }

    int index = 0;

    return decode(nodes, index);
}

// Approach 2 — BFS level-order traversal

string serializeII(TreeNode *root)
{
    if (!root)
        return "#";

    string result;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();

        if (!node)
        {
            result += "#,";
            continue;
        }

        result += to_string(node->val) + ",";
        q.push(node->left);
        q.push(node->right);
    }

    return result;
}

TreeNode *deserializeII(string data)
{
    stringstream ss(data);
    string token;
    vector<string> nodes;

    while (getline(ss, token, ','))
    {
        if (!token.empty())
        {
            nodes.push_back(token);
        }
    }

    if (nodes.empty() || nodes[0] == "#")
    {
        return nullptr;
    }

    TreeNode *root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode *> q;
    q.push(root);

    int index = 1;

    while (!q.empty() && index < (int)nodes.size())
    {
        TreeNode *node = q.front();
        q.pop();

        if (index < (int)nodes.size() && nodes[index] != "#")
        {
            node->left = new TreeNode(stoi(nodes[index]));
            q.push(node->left);
        }

        index++;

        if (index < (int)nodes.size() && nodes[index] != "#")
        {
            node->right = new TreeNode(stoi(nodes[index]));
            q.push(node->right);
        }

        index++;
    }

    return root;
}

int main()
{
    // Example tree: [1, 2, 3, null, null, 4, 5]
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    string dfsData = serializeI(root);
    TreeNode *dfsCopy = deserializeI(dfsData);
    cout << "DFS: " << dfsData << '\n';
    cout << "DFS round trip: " << serializeI(dfsCopy) << '\n';

    string bfsData = serializeII(root);
    TreeNode *bfsCopy = deserializeII(bfsData);
    cout << "BFS: " << bfsData << '\n';
    cout << "BFS round trip: " << serializeII(bfsCopy) << '\n';

    return 0;
}