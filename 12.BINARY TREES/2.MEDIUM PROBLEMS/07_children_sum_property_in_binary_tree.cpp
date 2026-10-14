#include <iostream>
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

/*
2236. Root Equals Sum of Children

You are given the root of a binary tree that consists of exactly 3 nodes: the root, its left child, and its right child.

Return true if the value of the root is equal to the sum of the values of its two children, or false otherwise.

Example 1:
Input: root = [10,4,6]
Output: true
Explanation: The values of the root, its left child, and its right child are 10, 4, and 6, respectively.
10 is equal to 4 + 6, so we return true.

Example 2:
Input: root = [5,3,1]
Output: false
Explanation: The values of the root, its left child, and its right child are 5, 3, and 1, respectively.
5 is not equal to 3 + 1, so we return false.


Constraints:
The tree consists only of the root, its left child, and its right child.
-100 <= Node.val <= 100
*/

bool checkTree(TreeNode *root)
{
    if (root == nullptr || root->left == nullptr || root->right == nullptr)
        return false;

    return root->val == root->left->val + root->right->val;
}

int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(4);
    root->right = new TreeNode(6);

    cout << (checkTree(root) ? "The value of the root is equal to the sum." : "The value of the root is not equal to the sum.") << endl;

    return 0;
}

/*
Children Sum in a Binary Tree

Given a binary tree, find if it satisfies the Children Sum Property which has the following rules
    Each non-leaf node must have a value equal to the sum of its left and right children's values.
    A NULL child is considered to have a value of 0, and all leaf nodes are considered valid by default.

Examples:

Input: root = [35, 20, 15, 15, 5, 10, 5]
Output: True
Explanation: Here, every node is sum of its left and right child.

Input: root = [1, 4, 3, 5]
Output: False
Explanation: Here, 1 is the root node and 4, 3 are its child nodes. 4 + 3 = 7 which is not equal to the value of root node. Hence, this tree does not satisfy the given condition.

Constraints:
1 ≤ size of binary tree ≤ 105
0 ≤ node.data ≤ 109
*/

bool isSumProperty(TreeNode *root)
{
    if (root == nullptr || (root->left == nullptr && root->right == nullptr))
    {
        return true;
    }

    int left = (root->left != nullptr) ? root->left->val : 0;
    int right = (root->right != nullptr) ? root->right->val : 0;

    if (root->val != left + right)
    {
        return false;
    }

    return isSumProperty(root->left) && isSumProperty(root->right);
}

int main()
{
    TreeNode *root = new TreeNode(35);
    root->left = new TreeNode(20);
    root->right = new TreeNode(15);

    root->left->left = new TreeNode(15);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(5);

    if (isSumProperty(root))
        cout << "It satisfies the Children Sum Property." << endl;
    else
        cout << "It doesn't satisfies the Children Sum Property." << endl;

    return 0;
}

/*
Children Sum Property

Problem statement
Given a binary tree of nodes 'N', you need to modify the value of its nodes, such that the tree holds the Children sum property.

A binary tree is said to follow the children sum property if, for every node of that tree, the value of that node is equal to the sum of the value(s) of all of its children nodes( left child and the right child).

Note :
 1. You can only increment the value of the nodes, in other words, the modified value must be at least equal to the original value of that node.
 2. You can not change the structure of the original binary tree.
 3. A binary tree is a tree in which each node has at most two children.
 4. You can assume the value can be 0 for a NULL node and there can also be an empty tree.


Constraints :
1 <= T <= 10^2
0 <= N <= 10^2
1 <= node.Value <= 10^6

Time Limit : 1 sec

Sample Input 1 :
1
2 35 10 2 3 5 2 -1 -1 -1 -1 -1 -1 -1 -1
Sample Output 1 :
Valid ( One of the possible answers is : 45 35 10 32 3 8 2 -1 -1 -1 -1 -1, thus if the user modifies the given tree like this, the output printed will be valid).
Explanation For Sample Input 1 :
The value at the root node is 2 which is less than the sum of its children’s values (35 + 10). So we simply increase the value at the root node to 45. The node with value  = 35 has children with values 2 and 3 so their sum i.s 2 + 3 = 5 < 35. As we can't decrement any value, so instead we have to increase the sum of children and thus we update 35's children (2 and 3) as 30 and 5 so that 30 + 5 = 35 and the same is done for the children of the node with value = 10.

Note that there can be many other valid solutions.

Sample Input 2 :
1
10 5 5 -1 -1 -1 -1
Sample Output 2 :
Valid
*/

void changeTree(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    int childSum = 0;

    if (root->left != nullptr)
    {
        childSum += root->left->val;
    }

    if (root->right != nullptr)
    {
        childSum += root->right->val;
    }

    if (childSum >= root->val)
    {
        root->val = childSum;
    }
    else
    {
        if (root->left != nullptr)
        {
            root->left->val = root->val;
        }
        else if (root->right != nullptr)
        {
            root->right->val = root->val;
        }
    }

    changeTree(root->left);
    changeTree(root->right);

    int total = 0;

    if (root->left != nullptr)
    {
        total += root->left->val;
    }

    if (root->right != nullptr)
    {
        total += root->right->val;
    }

    if (root->left != nullptr || root->right != nullptr)
    {
        root->val = total;
    }
}

// Print tree in level order
void printTree(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *current = q.front();
        q.pop();

        cout << current->val << " ";

        if (current->left != nullptr)
        {
            q.push(current->left);
        }

        if (current->right != nullptr)
        {
            q.push(current->right);
        }
    }

    cout << endl;
}

int main()
{
    TreeNode *root = new TreeNode(2);

    root->left = new TreeNode(35);
    root->right = new TreeNode(10);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(3);

    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(2);

    cout << "Before modification: ";
    printTree(root);

    changeTree(root);

    cout << "After modification: ";
    printTree(root);

    return 0;
}