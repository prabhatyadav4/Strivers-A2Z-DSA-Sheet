/*
Infix to Prefix Conversion

Given a valid arithmetic expression in infix notation, return its equivalent prefix (Polish) notation.

The expression can contain:

lowercase letters a–z as operands

the four binary operators + - * /

and round parentheses ( ) that enforce evaluation order

No whitespace appears in the input.

The input is guaranteed to be syntactically correct (parentheses are balanced, every operator has two operands, etc.).


Example 1

Input: "(a+b)*c"

Output: "*+abc"

Explanation:

Infix  : (a + b) * c

Prefix : * + a b c

Example 2

Input: "a+b*c"

Output: "+a*bc"

Explanation:

Infix : a + (b * c)

Prefix : + a * b c


Constraints
1 ≤ infix.length ≤ 1000
infix contains only characters {a–z, +, -, *, /, (, )}.
The expression is valid.
*/

#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int prec(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

void infixToPrefix(string s)
{
    int n = s.size();

    reverse(s.begin(), s.end());

    for (char &c : s)
    {
        if (c == '(')
            c = ')';
        else if (c == ')')
            c = '(';
    }

    stack<char> st;
    string ans;
    int i = 0;

    while (i < n)
    {
        char c = s[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            ans += c;
        }
        else if (c == '(')
        {
            st.push(c);
        }
        else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            if (c == '^')
            {
                while (!st.empty() && prec(c) <= prec(st.top()))
                {
                    ans += st.top();
                    st.pop();
                }
                st.push(c);
            }
            else
            {
                while (!st.empty() && prec(c) < prec(st.top()))
                {
                    ans += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }

        i++;
    }

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    cout << "Prefix Expression: " << ans << endl;
}

int main()
{
    string exp = "(p+q)*(m-n)"; // Infix expression
    cout << "Infix expression: " << exp << endl;
    infixToPrefix(exp); // Convert the infix expression to prefix
    return 0;
}