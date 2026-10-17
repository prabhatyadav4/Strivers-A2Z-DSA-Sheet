/*
404. Sum of Left Leaves

Given the root of a binary tree, return the sum of all left leaves.

A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: 24
Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.

Example 2:
Input: root = [1]
Output: 0
 

Constraints:
The number of nodes in the tree is in the range [1, 1000].
-1000 <= Node.val <= 1000
*/

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

int BruteSumOfLeftLeaves(TreeNode *root) {
    int ans = 0;

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

            if(node->left != nullptr) {
                if(node->left->left == nullptr && node->left->right == nullptr) {
                    ans += node->left->val;
                }
                q.push(node->left);
            }

            if(node->right != nullptr) {
                q.push(node->right);
            }
        }
    }

    return ans;
}

int OptimalSumOfLeftLeaves(TreeNode *root) {
    if(root == nullptr) {
        return 0;
    }

    int sum = 0;

    if(root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr) {
        sum += root->left->val;
    }

    sum += OptimalSumOfLeftLeaves(root->left);
    sum += OptimalSumOfLeftLeaves(root->right);

    return sum;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << "Brute sum: " << BruteSumOfLeftLeaves(root) << '\n';
    cout << "Optimal sum: " << OptimalSumOfLeftLeaves(root) << '\n';

    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}