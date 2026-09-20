/*
424. Longest Repeating Character Replacement

You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

Example 1:
Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.

Example 2:
Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.


Constraints:
1 <= s.length <= 105
s consists of only uppercase English letters.
0 <= k <= s.length
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int BruteCharacterReplacement(string s, int k)
{
    int n = s.length();
    int maxLength = 0;

    for (int i = 0; i < n; i++)
    {

        vector<int> freq(26, 0);
        int maxFreq = 0;

        for (int j = i; j < n; j++)
        {
            freq[s[j] - 'A']++;

            maxFreq = max(maxFreq, freq[s[j] - 'A']);

            int change = (j - i + 1) - maxFreq;

            if (change <= k)
            {
                maxLength = max(maxLength, j - i + 1);
            }
        }
    }

    return maxLength;
}

int BetterCharacterReplacement(string s, int k)
{
    int n = s.length();

    int hash[26] = {0};

    int l = 0, r = 0, maxFreq = 0, maxLength = 0;

    while (r < n)
    {
        hash[s[r] - 'A']++;

        maxFreq = max(maxFreq, hash[s[r] - 'A']);

        int change = (r - l + 1) - maxFreq;

        while (change > k)
        {
            hash[s[l] - 'A']--;
            l++;

            change = (r - l + 1) - maxFreq;
        }

        maxLength = max(maxLength, r - l + 1);

        r++;
    }

    return maxLength;
}

int OptimalCharacterReplacement(string s, int k)
{
    int n = s.length();
    int hash[26] = {0};
    int l = 0, r = 0, maxFreq = 0, maxLength = 0;

    while (r < n)
    {
        hash[s[r] - 'A']++;

        maxFreq = max(maxFreq, hash[s[r] - 'A']);

        if ((r - l + 1) - maxFreq > k)
        {
            hash[s[l] - 'A']--;
            l++;
        }

        maxLength = max(maxLength, r - l + 1);
        r++;
    }

    return maxLength;
}

int main()
{

    string s = "AABABBA";
    int k = 1;

    int ans1 = BruteCharacterReplacement(s, k);
    cout << "BRUTE: The length of the longest substring is: " << ans1 << endl;

    int ans2 = BetterCharacterReplacement(s, k);
    cout << "BETTER: The length of the longest substring is: " << ans2 << endl;

    int ans3 = OptimalCharacterReplacement(s, k);
    cout << "OPTIMAL: The length of the longest substring is: " << ans3 << endl;

    return 0;
}