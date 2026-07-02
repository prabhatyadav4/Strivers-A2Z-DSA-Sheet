/*
Print Bracket Number

Given a string s, the task is to find the bracket numbers, i.e., for each bracket in s, return i if the bracket is the ith opening or closing bracket to appear in the string.

Note : s contains lowercase English alphabets, and '(', ')' characters at any index, the number of opening brackets is greater than or equal to closing brackets

Examples:

Input:  s = "(aa(bdc))p(dee)"
Output: 1 2 2 1 3 3
Explanation: The highlighted brackets in the given string (aa(bdc))p(dee) are assigned the numbers as: 1 2 2 1 3 3.

Input:  s = "(((()("
Output: 1 2 3 4 4 5
Explanation: The highlighted brackets in the given string (((()( are assigned the numbers as: 1 2 3 4 4 5

Constraints:
1 ≤ |s| ≤ 105
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> bracketNumber(string &s)
{
    vector<int> ans;
    stack<int> st;
    int count = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            count++;
            st.push(count);
            ans.push_back(count);
        }
        else if (s[i] == ')')
        {
            ans.push_back(st.top());
            st.pop();
        }
    }

    return ans;
}

int main()
{
    string s = "(aa(bdc))p(dee)";

    vector<int> ans = bracketNumber(s);

    for (int res : ans)
    {
        cout << res << " ";
    }

    return 0;
}