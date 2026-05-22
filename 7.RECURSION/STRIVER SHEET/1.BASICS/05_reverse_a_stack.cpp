#include <iostream>
#include <stack>
using namespace std;

void reverseInsert(stack<int> &st, int x)
{
    if (st.empty())
    {
        st.push(x);
        return;
    };

    int top = st.top();
    st.pop();

    reverseInsert(st, x);
    st.push(top);
}

void reverseStack(stack<int> &st)
{
    if (st.empty())
        return;

    int top = st.top();
    st.pop();
    reverseStack(st);
    reverseInsert(st, top);
}

int main()
{
    stack<int> st;
    st.push(6);
    st.push(7);
    st.push(1);
    st.push(2);
    st.push(3);

    reverseStack(st);

    cout << "The stack elements in reversed order are: ";
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}