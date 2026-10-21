/*
885. Requirements needed to construct a unique BT

Given a pair of tree traversal, return true if a unique binary tree can be constructed otherwise false. Each traversal is represented with integer: 1 -> Preorder , 2 -> Inorder , 3 -> Postorder.

Example 1:
Input : 1 2
Output : true 
Explanation : Answer is True.

It is possible to construct a unique binary tree. This is because the preorder traversal provides the root of the tree, and the inorder traversal helps determine the left and right subtrees.

Example 2:
Input : 2 2
Output : false
Explanation : Two inorder traversals are insufficient to uniquely determine a binary tree.

Constraints:
1 <= a, b <= 3
*/

#include <iostream>
using namespace std;

bool isPossible(int a, int b) {
    if (a == b) {
        return false;
    }

    if (a == 2 || b == 2) {
        return true;
    }

    return false;
}

int main() {
    int a, b;
    cin >> a >> b;

    cout << boolalpha << isPossible(a, b) << endl;
    return 0;
}