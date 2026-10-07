/*
678. Valid Parenthesis String

Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".


Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "(*)"
Output: true

Example 3:
Input: s = "(*))"
Output: true

Example 4:
Input: s = "("
Output: false

Constraints:
1 <= s.length <= 100
s[i] is '(', ')' or '*'.
*/

#include <iostream>
#include <stack>
using namespace std;

bool solve(string &s, int index, int balance)
{
    if (balance < 0)
    {
        return false;
    }

    if (index == s.length())
    {
        return balance == 0;
    }

    if (s[index] == '(')
    {
        return solve(s, index + 1, balance + 1);
    }

    if (s[index] == ')')
    {
        return solve(s, index + 1, balance - 1);
    }

    if (solve(s, index + 1, balance + 1))
    {
        return true;
    }

    if (solve(s, index + 1, balance - 1))
    {
        return true;
    }

    if (solve(s, index + 1, balance))
    {
        return true;
    }

    return false;
}

bool BruteCheckValidString(string s)
{
    return solve(s, 0, 0);
}

bool BetterCheckValidString(string s)
{
    stack<int> openStack;
    stack<int> starStack;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            openStack.push(i);
        }
        else if (s[i] == '*')
        {
            starStack.push(i);
        }
        else
        {
            if (!openStack.empty())
            {
                openStack.pop();
            }
            else if (!starStack.empty())
            {
                starStack.pop();
            }
            else
            {
                return false;
            }
        }
    }

    while (!openStack.empty() && !starStack.empty())
    {
        int openPos = openStack.top();
        int starPos = starStack.top();

        if (starPos > openPos)
        {
            openStack.pop();
            starStack.pop();
        }

        else
        {
            return false;
        }
    }

    return openStack.empty();
}

bool OptimalCheckValidString(string s)
{
    int low = 0;
    int high = 0;

    for (char c : s)
    {
        if (c == '(')
        {
            low++;
            high++;
        }
        else if (c == ')')
        {
            low--;
            high--;
        }
        else
        {
            low--;
            high++;
        }

        if (high < 0)
        {
            return false;
        }

        low = max(low, 0);
    }

    return low == 0;
}

int main()
{
    string s = "(*)";

    cout << "Input: " << s << endl;

    cout << "Brute: ";
    cout << (BruteCheckValidString(s) ? "true" : "false") << endl;

    cout << "Better: ";
    cout << (BetterCheckValidString(s) ? "true" : "false") << endl;

    cout << "Optimal: ";
    cout << (OptimalCheckValidString(s) ? "true" : "false") << endl;

    return 0;
}