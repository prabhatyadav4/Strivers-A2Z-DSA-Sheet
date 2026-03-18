/*
5. Longest Palindromic Substring

Given a string s, return the longest palindromic substring in s.

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.
*/

#include <iostream>
#include <cstring>
using namespace std;

int t[1001][1001];

class Solution {
    public: 

    bool solve(string &s, int i, int j) {
        if(i >= j)  return 1;

        if(t[i][j] != -1)   return t[i][j];

        if(s[i] == s[j]){
            return t[i][j] = solve(s, i + 1, j - 1);
        }

        return t[i][j] = 0;
    }

    string longestPalindromic(string s) {
        int n = s.size();
        memset(t, -1, sizeof(t));
        int maxLen = INT_MIN;
        int sp = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(solve(s, i, j)){
                    if(j - i + 1 > maxLen) {
                        maxLen = j - i + 1;
                        sp = i;
                    }
                }
            }
        }

        return s.substr(sp, maxLen);
    }
};

int main() {
    Solution obj;

    string s = "babad";

    cout << "The longest palindromic substring is: " << obj.longestPalindromic(s) << endl;

    return 0;
}