/*
844. Backspace String Compare

Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

Example 1:

Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".

Example 2:

Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".

Example 3:

Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".


Constraints:
1 <= s.length, t.length <= 200
s and t only contain lowercase letters and '#' characters.
*/

#include <iostream>
#include <stack>
using namespace std;

bool backspaceCompare(string s, string t)
{
    stack<int> st1;
    stack<int> st2;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '#')
        {
            if (!st1.empty())
            {
                st1.pop();
            }
        }
        else
        {
            st1.push(s[i]);
        }
    }

    for (int i = 0; i < s.size(); i++)
    {
        if (t[i] == '#')
        {
            if (!st2.empty())
            {
                st2.pop();
            }
        }
        else
        {
            st2.push(t[i]);
        }
    }

    return st1 == st2;
}

int main()
{
    string s = "ab#c", t = "ad#c";

    cout << (backspaceCompare(s, t) ? "They are equal" : "They are not equal");

    return 0;
}