/*
Insert an Element at the Bottom of a Stack

You are given a stack st of n integers and an element x. You have to insert x at the bottom of the given stack.

Note: Everywhere in this problem, the bottommost element of the stack is shown first while priniting the stack.

Example 1:
Input:
n = 5
x = 2
st = {4,3,2,1,8}

Output:
{2,4,3,2,1,8}

Explanation:
After insertion of 2, the final stack will be {2,4,3,2,1,8}.

Example 2:
Input:
n = 3
x = 4
st = {5,3,1}

Output:
{4,5,3,1}

Explanation:
After insertion of 4, the final stack will be {4,5,3,1}.

Your Task:

You don't need to read input or print anything. Your task is to complete the function insertAtBottom() which takes a stack st and an integer x as inputs and returns the modified stack after insertion.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 <= n <= 105
0 <= x, elements of stack <= 109
*/

#include <iostream>
#include <stack>
using namespace std;

stack<int> insertAtBottom(stack<int> st, int x)
{

    stack<int> temp;

    while (!st.empty())
    {
        temp.push(st.top());
        st.pop();
    }

    st.push(x);

    while (!temp.empty())
    {
        st.push(temp.top());
        temp.pop();
    }

    return st;
}

int main()
{
    stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    int x = 0;

    stack<int> ans = insertAtBottom(st, x);

    // Print bottom to top
    stack<int> temp;
    while (!ans.empty())
    {
        temp.push(ans.top());
        ans.pop();
    }

    cout << "Bottom -> ";
    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << "<- Top\n";

    return 0;
}