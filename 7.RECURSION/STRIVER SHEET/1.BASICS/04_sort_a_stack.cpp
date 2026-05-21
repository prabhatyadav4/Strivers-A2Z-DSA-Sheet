/*
Sort a stack

Given a stack of integers st[]. Sort the stack in ascending order (smallest element at the bottom and largest at the top).

Examples:
Input: st[] = [41, 3, 32, 2, 11]
Output: [41, 32, 11, 3, 2]
Explanation: After sorting, the smallest element (2) is at the bottom and the largest element (41) is at the top.

Input: st[] = [3, 2, 1]
Output: [3, 2, 1]
Explanation: The stack is already sorted in ascending order.

Constraints:
1 ≤ st.size() ≤ 103
0 ≤ stack element ≤ 103
*/

#include <iostream>
#include <stack>
using namespace std;

void sortedInsert(stack<int> &st, int x)
{
    if (st.empty() || st.top() <= x)
    {
        st.push(x);
        return;
    }

    int top = st.top();
    st.pop();

    sortedInsert(st, x);

    st.push(top);
}

void sortStack(stack<int> &st)
{
    if (st.empty())
        return;

    int top = st.top();
    st.pop();

    sortStack(st);

    sortedInsert(st, top);
}

int main()
{
    stack<int> st;
    st.push(41);
    st.push(3);
    st.push(32);
    st.push(2);
    st.push(11);

    sortStack(st);

    cout << "The sorted stack elements are: ";
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}