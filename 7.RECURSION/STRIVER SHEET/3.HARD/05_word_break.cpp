/*

*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <cstring>
using namespace std;

int n;
int dp[301];
int maxLen;
unordered_set<string> st;

bool solve(int index, string &word)
{
    if (index == n)
    {
        return true;
    }

    if (dp[index] != -1)
    {
        return dp[index];
    }

    for (int len = 1; maxLen <= n && len + index <= n; len++)
    {
        string temp = word.substr(index, len);

        if (st.count(temp) && solve(index + len, word))
        {
            return dp[index] = true;
        }
    }

    return dp[index] = false;
}

bool wordBreak(string &word, vector<string> &dict)
{
    n = word.size();
    memset(dp, -1, sizeof(dp));
    maxLen = 0;

    for (string &word : dict)
    {
        st.insert(word);
        maxLen = max(maxLen, (int)word.size());
    }

    return solve(0, word);
}

int main()
{
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};

    bool ans = wordBreak(s, wordDict);

    cout << (ans ? "true" : "false") << endl;

    return 0;
}