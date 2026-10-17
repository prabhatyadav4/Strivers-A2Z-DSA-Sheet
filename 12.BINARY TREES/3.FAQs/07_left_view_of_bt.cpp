/*
Left View of Binary Tree

Given the root of a binary tree. Return the left view of the binary tree. The left view of a binary tree is the set of nodes visible when the tree is viewed from the left side.

Note: If the tree is empty, return an empty list.

Examples :
Input: root = [1, 2, 3, 4, 5, N, N] 
Output:[1, 2, 4]
Explanation: From the left side of the tree, only the nodes 1, 2, and 4 are visible.

Input: root = [1, 2, 3, N, N, 4, N, N, 5, N, N]
Output: [1, 2, 4, 5]
Explanation: From the left side of the tree, only the nodes 1, 2, 4, and 5 are visible.

Constraints:
0 ≤ size of binary tree, node.data ≤ 105
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

vector<int> BruteLeftView(TreeNode *root) {
    vector<int> ans;

    if(root == nullptr) {
        return ans;
    }

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        int size = q.size();

        for(int i = 0; i < size; i++) {
            TreeNode *node = q.front();
            q.pop();

            if(i == 0) {
                ans.push_back(node->val);
            }

            if(node->left) {
                q.push(node->left);
            }

            if(node->right) {
                q.push(node->right);
            }
        }
    }

    return ans;
} 

void solve(TreeNode* node, int level, vector<int> &ans) {
    if(node == nullptr) {
        return;
    }

    if(level == ans.size()) {
        ans.push_back(node->val);
    }

    solve(node->left, level + 1, ans);
    solve(node->right, level + 1, ans);
}

vector<int> OptimalLeftView(TreeNode *root) {
    vector<int> ans;

    solve(root, 0, ans);
    
    return ans;
}

int main() {
    // Example tree: [1, 2, 3, 4, 5, N, N]
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<int> brute = BruteLeftView(root);
    vector<int> optimal = OptimalLeftView(root);

    cout << "Brute left view: ";
    for(int value : brute) {
        cout << value << " ";
    }
    cout << endl;

    cout << "Optimal left view: ";
    for(int value : optimal) {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}