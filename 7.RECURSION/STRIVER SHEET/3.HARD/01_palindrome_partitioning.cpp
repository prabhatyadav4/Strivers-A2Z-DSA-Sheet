/*
131. Palindrome Partitioning

Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

Example 1:
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]

Example 2:
Input: s = "a"
Output: [["a"]]


Constraints:
1 <= s.length <= 16
s contains only lowercase English letters.
*/

#include <iostream>
#include <vector>
using namespace std;

bool isPalindrome(string &s, int l, int r)
{
    while (l < r)
    {
        if (s[l] != s[r])
        {
            return false;
        }

        l++;
        r--;
    }

    return true;
}

void solve(string &s, int index, vector<string> &curr, vector<vector<string>> &res)
{
    if (index == s.length())
    {
        res.push_back(curr);
        return;
    }

    for (int i = index; i < s.length(); i++)
    {
        if (isPalindrome(s, index, i))
        {
            curr.push_back(s.substr(index, i - index + 1));
            solve(s, i + 1, curr, res);
            curr.pop_back();
        }
    }
}

vector<vector<string>> palindromePartitioning(string s)
{
    vector<vector<string>> res;
    vector<string> curr;

    solve(s, 0, curr, res);

    return res;
}

int main()
{
    string s = "aabaa";

    vector<vector<string>> res = palindromePartitioning(s);

    cout << "[\n";
    for (int i = 0; i < res.size(); i++)
    {
        cout << "  [";
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << "\"" << res[i][j] << "\"";
            if (j < res[i].size() - 1)
            {
                cout << ", ";
            }
        }
        cout << "]";
        if (i < res.size() - 1)
        {
            cout << ",";
        }
        cout << "\n";
    }
    cout << "]\n";

    return 0;
}