/*
Infix to Postfix Conversion

You are given a string expression representing a valid infix mathematical expression. Your task is to convert this expression into its equivalent postfix notation, also known as Reverse Polish Notation (RPN).

The expression may include:

Operands: single lowercase English letters (a to z) or single-digit numbers (0 to 9)

Binary operators: +, -, *, /, ^

Parentheses: ( and ) to indicate grouping and precedence

Operator precedence (from highest to lowest):

^ (exponentiation)

*, / (multiplication and division)

+, - (addition and subtraction)


Associativity:

^ is right-associative

All other operators are left-associative

Parentheses override standard precedence

You must return the corresponding postfix expression as a string.

The result must not contain any spaces or separators between characters.


Example 1

Input: expression = "a+b*c"

Output: "abc*+"

Explanation:

Multiplication has higher precedence than addition, so b * c is evaluated first, then added to a.

Example 2

Input: expression = "(a+b)*c"

Output: "ab+c*"

Explanation:

The parentheses ensure that a + b is evaluated before multiplying with c.
*/

#include <iostream>
#include <stack>
using namespace std;

int prec(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '/' || c == '*')
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

void infixToPostfix(string s)
{
    stack<char> st;
    string ans;

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            ans += c;
        }

        else if (c == '(')
        {
            st.push('(');
        }

        else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            if (!st.empty())
            {
                st.pop();
            }
        }

        else
        {
            while (!st.empty() && st.top() != '(' &&
                   (prec(st.top()) > prec(c) ||
                    (prec(st.top()) == prec(c) && c != '^')))
            {
                ans += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    cout << "Postfix Expression: " << ans << endl;
}

int main()
{
    string exp = "(p+q)*(m-n)"; // Infix expression
    cout << "Infix expression: " << exp << endl;
    infixToPostfix(exp); // Convert the infix expression to postfix
    return 0;
}