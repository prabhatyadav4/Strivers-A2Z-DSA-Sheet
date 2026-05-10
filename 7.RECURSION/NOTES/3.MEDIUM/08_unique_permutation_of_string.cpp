/*
Permutations of a String

Given a string s, which may contain duplicate characters, your task is to generate and return an array of all unique permutations of the string. You can return your answer in any order.

Examples:
Input: s = "ABC"
Output: ["ABC", "ACB", "BAC", "BCA", "CAB", "CBA"]
Explanation: Given string ABC has 6 unique permutations.

Input: s = "ABSG"
Output: ["ABGS", "ABSG", "AGBS", "AGSB", "ASBG", "ASGB", "BAGS", "BASG", "BGAS", "BGSA", "BSAG", "BSGA", "GABS", "GASB", "GBAS", "GBSA", "GSAB", "GSBA", "SABG", "SAGB", "SBAG", "SBGA", "SGAB", "SGBA"]
Explanation: Given string ABSG has 24 unique permutations.

Input: s = "AAA"
Output: ["AAA"]
Explanation: No other unique permutations can be formed as all the characters are same.
x
Constraints:
1 <= s.size() <= 9
s contains only Uppercase english alphabets
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

void recurPermute(string &s, int index, set<string> &unique)
{
    if (index == s.size())
    {
        unique.insert(s);
        return;
    }

    for (int i = index; i < s.size(); i++)
    {
        swap(s[index], s[i]);
        recurPermute(s, index + 1, unique);
        swap(s[index], s[i]);
    }
}

vector<string> findPermutation(string &s)
{
    set<string> unique;
    vector<string> ans;
    recurPermute(s, 0, unique);

    for (auto &perm : unique)
    {
        ans.push_back(perm);
    }

    return ans;
}

int main()
{
    string s = "ABC";

    vector<string> res = findPermutation(s);

    for (auto x : res)
        cout << x << " ";

    return 0;
}