/*
76. Minimum Window Substring

Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.



Example 1:
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

Example 2:
Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.

Example 3:
Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.


Constraints:
m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.
*/

#include <iostream>
#include <climits>
#include <string>
using namespace std;

string BruteMinWindow(string s, string t)
{
    int n = s.length();
    int m = t.length();

    if (n == 0 || m == 0 || n < m)
    {
        return "";
    }

    int hash[256] = {0};

    for (int i = 0; i < m; i++)
    {
        hash[(unsigned char)t[i]]++;
    }

    int minLen = INT_MAX;
    int startIdx = -1;

    for (int i = 0; i < n; i++)
    {

        int temp[256] = {0};

        for (int j = i; j < n; j++)
        {

            temp[(unsigned char)s[j]]++;

            bool valid = true;

            for (int i = 0; i < 256; i++)
            {

                if (temp[i] < hash[i])
                {
                    valid = false;
                    break;
                }
            }

            if (valid)
            {

                int len = j - i + 1;

                if (len < minLen)
                {
                    minLen = len;
                    startIdx = i;
                }
            }
        }
    }

    return startIdx == -1 ? "" : s.substr(startIdx, minLen);
}

string OptimalMinWindow(string s, string t)
{
    int n = s.length();
    int m = t.length();

    if (n == 0 || m == 0 || n < m)
    {
        return "";
    }

    int hash[256] = {0};

    for (int i = 0; i < m; i++)
    {
        hash[(unsigned char)t[i]]++;
    }

    int left = 0, right = 0, count = m, startIdx = -1, minLen = INT_MAX;

    while (right < n)
    {

        hash[(unsigned char)s[right]]--;

        if (hash[(unsigned char)s[right]] >= 0)
        {
            count--;
        }

        while (count == 0)
        {

            if (right - left + 1 < minLen)
            {
                minLen = right - left + 1;
                startIdx = left;
            }

            hash[(unsigned char)s[left]]++;

            if (hash[(unsigned char)s[left]] > 0)
            {
                count++;
            }

            left++;
        }

        right++;
    }

    return startIdx == -1 ? "" : s.substr(startIdx, minLen);
}

int main()
{

    string s = "ADOBECODEBANC";
    string t = "ABC";

    string ans1 = BruteMinWindow(s, t);
    cout << "BRUTE: The minimum window substring is: " << ans1 << endl;

    string ans2 = OptimalMinWindow(s, t);
    cout << "OPTIMAL: The minimum window substring is: " << ans2 << endl;

    return 0;
}