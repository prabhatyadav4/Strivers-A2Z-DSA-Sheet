/*
1358. Number of Substrings Containing All Three Characters

Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.

Example 1:
Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again).

Example 2:
Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb".

Example 3:
Input: s = "abc"
Output: 1

Constraints:
3 <= s.length <= 5 x 104
s only consists of 'a', 'b' or 'c' characters.
*/

#include <iostream>
using namespace std;

bool containsAllThree(string &s, int start, int end)
{
    bool hasA = false, hasB = false, hasC = false;

    for (int i = start; i <= end; i++)
    {
        if (s[i] == 'a')
        {
            hasA = true;
        }
        else if (s[i] == 'b')
        {
            hasB = true;
        }
        else
        {
            hasC = true;
        }
    }

    return hasA && hasB && hasC;
}

int BruteNumberOfSubstrings(string &s)
{
    int n = s.length();

    if (n < 3)
    {
        return 0;
    }

    int count = 0;

    for (int i = 0; i < n; i++)
    {

        for (int j = i; j < n; j++)
        {

            if (containsAllThree(s, i, j))
            {
                count++;
            }
        }
    }

    return count;
}

int BetterNumberOfSubstrings(string &s)
{
    int n = s.length();

    if (n < 3)
    {
        return 0;
    }

    int count = 0;

    for (int i = 0; i < n; i++)
    {

        bool hasA = false;
        bool hasB = false;
        bool hasC = false;

        for (int j = i; j < n; j++)
        {

            if (s[j] == 'a')
            {
                hasA = true;
            }
            else if (s[j] == 'b')
            {
                hasB = true;
            }
            else
            {
                hasC = true;
            }

            if (hasA && hasB && hasC)
            {
                count += n - j;
                break;
            }
        }
    }

    return count;
}

int OptimalNumberOfSubstrings(string &s)
{
    int n = s.length();

    if (n < 3)
    {
        return 0;
    }

    int count = 0;
    int lastSeen[3] = {-1, -1, -1};

    for (int i = 0; i < n; i++)
    {

        lastSeen[s[i] - 'a'] = i;

        if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1)
        {
            count += 1 + min(lastSeen[0], min(lastSeen[1], lastSeen[2]));
        }
    }

    return count;
}

int main()
{

    string s = "abcabc";

    int ans1 = BruteNumberOfSubstrings(s);
    cout << "BRUTE: Count of substrings: " << ans1 << endl;

    int ans2 = BetterNumberOfSubstrings(s);
    cout << "BETTER: Count of substrings: " << ans2 << endl;

    int ans3 = OptimalNumberOfSubstrings(s);
    cout << "OPTIMAL: Count of substrings: " << ans3 << endl;

    return 0;
}