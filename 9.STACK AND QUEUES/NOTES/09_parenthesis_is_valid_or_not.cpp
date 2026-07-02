/*
String = ((())())
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool parenthesisValidOrNot(string s)
{

    stack<char> st;

    for (int i = 0; i < s.size(); i++)
    {

        if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else
        {
            if (st.empty())
            {
                return false;
            }
            else
            {
                st.pop();
            }
        }
    }

    return st.empty();
}

int main()
{
    string s = "((())())";

    cout << (parenthesisValidOrNot(s) ? "Parenthesis is Valid" : "Parenthesis is not valid");

    return 0;
}