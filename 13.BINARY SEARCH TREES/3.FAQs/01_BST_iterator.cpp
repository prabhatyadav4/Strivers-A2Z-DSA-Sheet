/*
173. Binary Search Tree Iterator

Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):

BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as part of the constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.
boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
int next() Moves the pointer to the right, then returns the number at the pointer.
Notice that by initializing the pointer to a non-existent smallest number, the first call to next() will return the smallest element in the BST.

You may assume that next() calls will always be valid. That is, there will be at least a next number in the in-order traversal when next() is called.

Example 1:

Input
["BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
[[[7, 3, 15, null, null, 9, 20]], [], [], [], [], [], [], [], [], []]

Output
[null, 3, 7, true, 9, true, 15, true, 20, false]

Explanation
BSTIterator bSTIterator = new BSTIterator([7, 3, 15, null, null, 9, 20]);
bSTIterator.next();    // return 3
bSTIterator.next();    // return 7
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 9
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 15
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 20
bSTIterator.hasNext(); // return False


Constraints:
The number of nodes in the tree is in the range [1, 105].
0 <= Node.val <= 106
At most 105 calls will be made to hasNext, and next.


Follow up:

Could you implement next() and hasNext() to run in average O(1) time and use O(h) memory, where h is the height of the tree?
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

class BruteBSTIterator
{
    vector<int> inorder;
    int index = 0;

    void traverse(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }

        traverse(root->left);
        inorder.push_back(root->val);
        traverse(root->right);
    }

public:
    BruteBSTIterator(TreeNode *root)
    {
        traverse(root);
    }

    int next()
    {
        return inorder[index++];
    }

    bool hasNext()
    {
        return index < inorder.size();
    }
};

class OptimalBSTIterator
{
    stack<TreeNode *> st;

    void pushLeft(TreeNode *root)
    {
        while (root != nullptr)
        {
            st.push(root);
            root = root->left;
        }
    }

public:
    OptimalBSTIterator(TreeNode *root)
    {
        pushLeft(root);
    }

    int next()
    {
        TreeNode *node = st.top();
        st.pop();

        pushLeft(node->right);

        return node->val;
    }

    bool hasNext()
    {
        return !st.empty();
    }
};

int main()
{
    TreeNode *root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    BruteBSTIterator brute(root);
    OptimalBSTIterator optimal(root);

    cout << "Brute iterator calls:\n";
    cout << "next(): " << brute.next() << '\n';
    cout << "next(): " << brute.next() << '\n';
    cout << "hasNext(): " << boolalpha << brute.hasNext() << '\n';
    cout << "next(): " << brute.next() << '\n';
    cout << "hasNext(): " << brute.hasNext() << '\n';
    cout << "next(): " << brute.next() << '\n';
    cout << "hasNext(): " << brute.hasNext() << '\n';
    cout << "next(): " << brute.next() << '\n';
    cout << "hasNext(): " << brute.hasNext() << '\n';

    cout << "\nOptimal iterator calls:\n";
    cout << "next(): " << optimal.next() << '\n';
    cout << "next(): " << optimal.next() << '\n';
    cout << "hasNext(): " << optimal.hasNext() << '\n';
    cout << "next(): " << optimal.next() << '\n';
    cout << "hasNext(): " << optimal.hasNext() << '\n';
    cout << "next(): " << optimal.next() << '\n';
    cout << "hasNext(): " << optimal.hasNext() << '\n';
    cout << "next(): " << optimal.next() << '\n';
    cout << "hasNext(): " << optimal.hasNext() << '\n';

    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}