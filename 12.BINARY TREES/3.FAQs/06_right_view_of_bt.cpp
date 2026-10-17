/*
199. Binary Tree Right Side View

Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example 1:

Input: root = [1,2,3,null,5,null,4]

Output: [1,3,4]

Example 2:

Input: root = [1,2,3,4,null,null,null,5]

Output: [1,3,4,5]

Example 3:

Input: root = [1,null,3]

Output: [1,3]

Example 4:

Input: root = []

Output: []

Constraints:
The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *right;
    TreeNode *left;

    TreeNode(int val) {
        this->val = val;
        this->right = nullptr;
        this->left = nullptr;
    }
};

vector<int> BruteRightView(TreeNode *root) {
    vector<int> ans;

    if(root == nullptr) {
        return ans;
    }

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        int size = q.size();

        for(int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();

            if(i == size - 1) {
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

    solve(node->right, level + 1, ans);
    solve(node->left, level + 1, ans);
}

vector<int> OptimalRightView(TreeNode *root) {
    vector<int> ans;

    solve(root, 0, ans);

    return ans;
}

int main() {
    // Example tree: [1, 2, 3, null, 5, null, 4]
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    vector<int> bruteView = BruteRightView(root);
    vector<int> optimalView = OptimalRightView(root);

    cout << "Brute right view: ";
    for(int value : bruteView) {
        cout << value << " ";
    }

    cout << "\nOptimal right view: ";
    for(int value : optimalView) {
        cout << value << " ";
    }
    cout << '\n';

    return 0;
}