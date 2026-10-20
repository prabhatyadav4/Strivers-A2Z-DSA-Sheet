/*
2385. Amount of Time for Binary Tree to Be Infected

You are given the root of a binary tree with unique values, and an integer start. At minute 0, an infection starts from the node with value start.

Each minute, a node becomes infected if:
    The node is currently uninfected.
    The node is adjacent to an infected node.
    Return the number of minutes needed for the entire tree to be infected.


Example 1:
Input: root = [1,5,3,null,4,10,6,9,2], start = 3
Output: 4
Explanation: The following nodes are infected during:
- Minute 0: Node 3
- Minute 1: Nodes 1, 10 and 6
- Minute 2: Node 5
- Minute 3: Node 4
- Minute 4: Nodes 9 and 2
It takes 4 minutes for the whole tree to be infected so we return 4.

Example 2:
Input: root = [1], start = 1
Output: 0
Explanation: At minute 0, the only node in the tree is infected so we return 0.


Constraints:
The number of nodes in the tree is in the range [1, 105].
1 <= Node.val <= 105
Each node has a unique value.
A node with a value of start exists in the tree.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
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

int amountOfTime(TreeNode *root, int start)
{
    unordered_map<TreeNode *, TreeNode *> parent;
    queue<TreeNode *> q;

    q.push(root);
    TreeNode *target = nullptr;
    parent[root] = nullptr;

    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();

        if (node->val == start)
        {
            target = node;
        }

        if (node->left)
        {
            parent[node->left] = node;
            q.push(node->left);
        }

        if (node->right)
        {
            parent[node->right] = node;
            q.push(node->right);
        }
    }

    queue<TreeNode *> infected;
    unordered_set<TreeNode *> visited;

    infected.push(target);
    visited.insert(target);

    int minutes = -1;

    while (!infected.empty())
    {
        int size = infected.size();
        minutes++;

        for (int i = 0; i < size; i++)
        {
            TreeNode *node = infected.front();
            infected.pop();

            if (node->left && !visited.count(node->left))
            {
                infected.push(node->left);
                visited.insert(node->left);
            }

            if (node->right && !visited.count(node->right))
            {
                infected.push(node->right);
                visited.insert(node->right);
            }

            if (parent[node] && !visited.count(parent[node]))
            {
                infected.push(parent[node]);
                visited.insert(parent[node]);
            }
        }
    }

    return minutes;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(5);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(6);
    root->left->right->left = new TreeNode(9);
    root->left->right->right = new TreeNode(2);

    cout << "Minutes needed: " << amountOfTime(root, 3) << endl;

    return 0;
}