/*
22. Generate Parentheses

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:
Input: n = 1
Output: ["()"]


Constraints:
1 <= n <= 8
*/

#include <iostream>
#include <vector>
using namespace std;

bool isValid(string &curr)
{
    int count = 0;
    for (char &ch : curr)
    {
        if (ch == '(')
        {
            count++;
        }
        else
        {
            count--;
        }
        if (count < 0)
        {
            return false;
        }
    }

    return count == 0;
}

void helper(int n, string &curr, vector<string> &res)
{
    if (curr.length() == 2 * n)
    {
        if (isValid(curr))
        {
            res.push_back(curr);
        }
        return;
    }

    curr.push_back('(');
    helper(n, curr, res);
    curr.pop_back();

    curr.push_back(')');
    helper(n, curr, res);
    curr.pop_back();
}

vector<string> BruteGenerateParenthesis(int n)
{
    string curr = "";
    vector<string> res;

    helper(n, curr, res);

    return res;
}

void solve(string &curr, int n, int open, int close, vector<string> &res)
{
    if (curr.length() == 2 * n)
    {
        res.push_back(curr);
        return;
    }

    if (open < n)
    {
        curr.push_back('(');
        solve(curr, n, open + 1, close, res);
        curr.pop_back();
    }

    if (close < open)
    {
        curr.push_back(')');
        solve(curr, n, open, close + 1, res);
        curr.pop_back();
    }
}

vector<string> OptimalGenerateParenthesis(int n)
{
    vector<string> res;
    string curr = "";
    int open = 0;
    int close = 0;

    solve(curr, n, open, close, res);

    return res;
}

int main()
{
    int n = 2;

    vector<string> ans = BruteGenerateParenthesis(n);
    cout << "BRUTE: All combinations of parenthesis are: ";
    for (const auto &it : ans)
    {
        cout << it << " ";
    }

    int m = 3;

    vector<string> res = OptimalGenerateParenthesis(m);
    cout << "\nOPTIMAL: All combinations of parenthesis are: ";
    for (const auto &it : res)
    {
        cout << it << " ";
    }

    return 0;
}