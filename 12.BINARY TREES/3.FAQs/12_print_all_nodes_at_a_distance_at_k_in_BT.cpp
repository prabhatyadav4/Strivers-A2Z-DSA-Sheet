/*
863. All Nodes Distance K in Binary Tree

Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.



Example 1:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.

Example 2:
Input: root = [1], target = 1, k = 3
Output: []


Constraints:
The number of nodes in the tree is in the range [1, 500].
0 <= Node.val <= 500
All the values Node.val are unique.
target is the value of one of the nodes in the tree.
0 <= k <= 1000
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
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

unordered_map<TreeNode *, TreeNode *> parent;

void buildParent(TreeNode *node, TreeNode *par)
{
    if (node == nullptr)
    {
        return;
    }

    parent[node] = par;

    buildParent(node->left, node);
    buildParent(node->right, node);
}

vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
    parent.clear();
    buildParent(root, nullptr);

    queue<TreeNode *> q;
    unordered_set<TreeNode *> visited;

    q.push(target);
    visited.insert(target);

    int distance = 0;

    while (!q.empty())
    {
        int size = q.size();

        if (distance == k)
        {
            vector<int> ans;

            while (!q.empty())
            {
                ans.push_back(q.front()->val);
                q.pop();
            }

            return ans;
        }

        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();

            if (node->left && !visited.count(node->left))
            {
                q.push(node->left);
                visited.insert(node->left);
            }

            if (node->right && !visited.count(node->right))
            {
                q.push(node->right);
                visited.insert(node->right);
            }

            TreeNode *par = parent[node];

            if (par && !visited.count(par))
            {
                q.push(par);
                visited.insert(par);
            }
        }

        distance++;
    }

    return {};
}

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode *target = root->left;
    int k = 2;
    vector<int> result = distanceK(root, target, k);

    cout << "Nodes at distance " << k << " from " << target->val << ": ";
    for (int value : result)
    {
        cout << value << " ";
    }
    cout << '\n';

    return 0;
}
