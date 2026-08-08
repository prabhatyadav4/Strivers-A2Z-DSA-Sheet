/*
Prefix to Postfix Conversion

You are given a valid prefix expression consisting of binary operators and single-character operands. Your task is to convert it into a valid postfix expression.

Prefix (Polish) notation places the operator before operands.

Postfix (Reverse Polish) notation places the operator after operands.

Example 1

Input: expression = "+ab"

Output: "ab+"

Example 2

Input: expression = "*+ab-cd"

Output: "ab+cd-*"

Constraints
1 <= expression.length <= 104
Expression contains only valid prefix characters (a-z, 0-9, +, -, *, /, ^)
Expression is guaranteed to be a valid prefix expression
*/

#include <iostream>
#include <stack>
using namespace std;

string prefixToPostfix(string s)
{
    int n = s.length();

    stack<string> st;

    for (int i = n - 1; i >= 0; i--)
    {
        char c = s[i];

        if (isalnum(c))
        {
            st.push(string(1, c));
        }

        else
        {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();

            st.push(t1 + t2 + c);
        }
    }

    return st.top();
}

int main()
{
    string prefix = "*+ab-cd";
    cout << "Prefix Expression: " << prefix << endl;
    cout << "Postfix Expression: " << prefixToPostfix(prefix) << endl;

    return 0;
}