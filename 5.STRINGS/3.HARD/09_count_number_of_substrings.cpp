/*
Count Number of Substrings

You are given a string s consisting of lowercase English letters from 'a' to 'j'.

A substring is considered valid if at most one character occurs an odd number of times in that substring.

Return the total number of valid substrings in s.

A substring is a contiguous, non-empty sequence of characters within a string.

Example 1:
Input: s = "aba"

Output: 4

Explanation: The valid substrings are "a", "b", "a", and "aba". Each contains at most one character with an odd frequency.

Example 2:
Input: s = "aabb"

Output: 9

Explanation: There are 10 substrings in total. The only invalid substring is "ab", where both 'a' and 'b' occur an odd number of times. Hence, the answer is 9.

Constraints:
1 <= s.length <= 105
s consists only of lowercase English letters from 'a' to 'j'.
*/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

long long BruteCountSubstrings(string s)
{
    int n = s.size();
    long long ans = 0;

    for (int i = 0; i < n; i++)
    {
        int freq[10] = {0};

        for (int j = i; j < n; j++)
        {
            freq[s[j] - 'a']++;

            int oddCount = 0;

            for (int k = 0; k < 10; k++)
            {
                if (freq[k] % 2 != 0)
                {
                    oddCount++;
                }
            }

            if (oddCount <= 1)
            {
                ans++;
            }
        }
    }

    return ans;
}

long long OptimalCountSubstrings(string s)
{
    unordered_map<int, long long> mp;

    int mask = 0;
    long long ans = 0;

    mp[0] = 1;

    for (char ch : s)
    {
        mask ^= (1 << (ch - 'a'));

        ans += mp[mask];

        for (int i = 0; i < 10; i++)
        {
            int newMask = mask ^ (1 << i);

            ans += mp[newMask];
        }

        mp[mask]++;
    }

    return ans;
}

int main()
{
    string s = "abca";

    cout << "BRUTE: The total number of valid substrings in s is: " << BruteCountSubstrings(s) << endl;
    cout << "OPTIMAL: The total number of valid substrings in s is: " << OptimalCountSubstrings(s) << endl;

    return 0;
}