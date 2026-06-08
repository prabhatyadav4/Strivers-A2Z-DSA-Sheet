/*
Sort a Stack using Recursion

Given a stack of integers st[], Sort the stack in ascending order (smallest element at the bottom and largest at the top).

Example:

Input: st[] = [1, 2, 3]
Output: [3, 2, 1]
Explanation: The stack is already sorted in ascending order.

Input: st[] = [41, 3, 32, 2, 11]
Output: [41, 32, 11, 3, 2]
Explanation: After sorting, the smallest element (2) is at the bottom and the largest element (41) is at the top.
*/

#include <iostream>
#include <stack>
using namespace std;

// Insert element into sorted stack
void sortedInsert(stack<int> &st, int x)
{

    // If stack is empty or
    // top element is smaller, push x
    if (st.empty() || st.top() <= x)
    {
        st.push(x);
        return;
    }

    int top = st.top();
    st.pop();

    // Recursively insert x in sorted order
    sortedInsert(st, x);

    st.push(top);
}

// Sort the stack recursively
void sortStack(stack<int> &st)
{
    if (st.empty())
        return;

    int top = st.top();
    st.pop();

    // Recursively sort the remaining stack
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

    cout << "The sorted stack is: ";
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}