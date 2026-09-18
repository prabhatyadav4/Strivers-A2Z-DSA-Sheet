/*
3. Longest Substring Without Repeating Characters

Given a string s, find the length of the longest substring without duplicate characters.



Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.


Constraints:
0 <= s.length <= 105
s consists of English letters, digits, symbols and spaces.
*/

#include <iostream>
#include <vector>
using namespace std;

int BruteLongestNonRepeatingSubstring(string &s)
{

    int n = s.size();
    int maxLen = 0;

    for (int i = 0; i < n; i++)
    {

        vector<int> hash(256, 0);

        for (int j = i; j < n; j++)
        {

            if (hash[s[j]] == 1)
                break;

            hash[s[j]] = 1;

            int len = j - i + 1;

            maxLen = max(maxLen, len);
        }
    }

    return maxLen;
}

int main()
{
    string input = "cadbzabcd";

    int length1 = BruteLongestNonRepeatingSubstring(input);

    cout << "BRUTE: Length of longest substring without repeating characters: " << length1 << endl;

    return 0;
}
