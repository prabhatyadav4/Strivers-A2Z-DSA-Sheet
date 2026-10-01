/*
411. Minimum Window Subsequence

Given strings s1 and s2, return the minimum contiguous substring part of s1, so that s2 is a subsequence of the part.

If there is no such window in s1 that covers all characters in s2, return the empty string "". If there are multiple such minimum-length windows, return the one with the left-most starting index.

Example 1:
Input: s1 = "abcdebdde", s2 = "bde"

Output: "bcde"

Explanation:

"bcde" is the answer because it occurs before "bdde" which has the same length.

"deb" is not a smaller window because the elements of s2 in the window must occur in order.

Example 2:
Input: s1 = "jmeqsiwvaovvnbstl", s2 = "u"

Output: ""

Constraints:
1 <= s1.length <= 2 * 104
1 <= s2.length <= 100
s1 and s2 consist of lowercase English letters.
*/

#include <iostream>
#include <climits>
#include <string>
using namespace std;

bool isSubsequence(string &sub, string &s2)
{
    int i = 0, j = 0;

    while (i < sub.size() && j < s2.size())
    {
        if (sub[i] == s2[j])
        {
            j++;
        }
        i++;
    }

    return j == s2.size();
}

string BruteMinWindow(string &s1, string &s2)
{
    int n = s1.length();
    string ans = "";
    int minLen = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            string sub = s1.substr(i, j - i + 1);

            if (isSubsequence(sub, s2))
            {
                if (sub.size() < minLen)
                {
                    minLen = sub.size();
                    ans = sub;
                }

                break;
            }
        }
    }

    return ans;
}

string OptimalMinWindow(string &s1, string &s2)
{
    int n = s1.length();
    int m = s2.length();

    int i = 0, j = 0, k = 0, minLen = INT_MAX;

    string ans = "";

    while (j < n)
    {
        if (s1[j] == s2[k])
        {
            k++;
        }

        if (k == m)
        {
            i = j;
            k = m - 1;

            while (i >= 0)
            {
                if (s1[i] == s2[k])
                {
                    k--;
                }

                if (k < 0)
                {
                    break;
                }

                i--;
            }

            if (j - i + 1 < minLen)
            {
                minLen = j - i + 1;
                ans = s1.substr(i, minLen);
            }

            j = i + 1;
            k = 0;

            continue;
        }

        j++;
    }

    return ans;
}

int main()
{
    string s1 = "abcdebdde";
    string s2 = "bde";

    string ans1 = BruteMinWindow(s1, s2);
    cout << "BRUTE: The minimum window subsequence is: " << ans1 << endl;

    string ans2 = OptimalMinWindow(s1, s2);
    cout << "OPTIMAL: The minimum window subsequence is: " << ans2 << endl;

    return 0;
}