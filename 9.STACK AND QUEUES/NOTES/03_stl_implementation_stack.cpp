/*
STL Stack Implementation (C++)

In C++, a stack is already provided by the Standard Template Library (STL) in the header <stack>.
It implements the LIFO (Last-In-First-Out) structure.
*/

#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> st;

    // Push elements
    st.push(1);
    cout << "Pushed 1 into the stack" << endl;
    st.push(2);
    cout << "Pushed 2 into the stack" << endl;
    st.push(3);
    cout << "Pushed 3 into the stack" << endl;
    st.push(4);
    cout << "Pushed 4 into the stack" << endl;

    // Access top element
    cout << "Top element: " << st.top() << endl;

    // Pop element
    st.pop();
    cout << "Top after pop: " << st.top() << endl;

    // Check if empty
    if (st.empty())
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack is not empty" << endl;
    }

    // Size of stack
    cout << "Size: " << st.size() << endl;

    return 0;
}