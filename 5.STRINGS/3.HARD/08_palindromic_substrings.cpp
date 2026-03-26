/*
647. Palindromic Substrings

Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.

Example 1:

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:

Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

Constraints:

1 <= s.length <= 1000
s consists of lowercase English letters.
*/

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:

    // Approach 1: Brute Force using Recursion
    // Time: O(n^3) → n^2 substrings * O(n) palindrome check
    // Space: O(n) recursion stack

    bool checkI(const string &s, int i, int j) {
        if(i >= j) return true;
        
        if(s[i] == s[j]) {
            return checkI(s, i+1, j-1);
        }
        return false;
    }

    int BruteIcountSubstrings(string s) {
        int n = s.size();
        int count = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(checkI(s, i, j)) count++;
            }
        }
        return count;
    }


    // Approach 2: Recursion + Memoization (Top-Down DP)
    // Time: O(n^2)
    // Space: O(n^2)

    int t[1001][1001];

    bool checkII(const string &s, int i, int j) {
        if(i >= j) return true;

        if(t[i][j] != -1) return t[i][j];

        if(s[i] == s[j]) {
            return t[i][j] = checkII(s, i+1, j-1);
        }
        return t[i][j] = false;
    }

    int BruteIIcountSubstrings(string s) {
        int n = s.size();
        memset(t, -1, sizeof(t));

        int count = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(checkII(s, i, j)) count++;
            }
        }
        return count;
    }


    // Approach 3: Bottom-Up DP (Tabulation)
    // Time: O(n^2)
    // Space: O(n^2)

    int BetterCountSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> t(n, vector<bool>(n, false));

        int count = 0;

        for(int l = 1; l <= n; l++) {
            for(int i = 0; (i + l - 1) < n; i++) {
                int j = i + l - 1;

                if(i == j) {
                    t[i][j] = true;
                }
                else if(i + 1 == j) {
                    t[i][j] = (s[i] == s[j]);
                }
                else {
                    t[i][j] = (s[i] == s[j] && t[i+1][j-1]);
                }

                if(t[i][j]) count++;
            }
        }

        return count;
    }


    // Approach 4: Optimal (Expand Around Center)
    // Time: O(n^2)
    // Space: O(1)

    void check(const string &s, int i, int j, int n, int &count) {
        while(i >= 0 && j < n && s[i] == s[j]) {
            count++;
            i--;
            j++;
        }
    }

    int OptimalCountSubstrings(string s) {
        int n = s.size();
        int count = 0; 

        for(int i = 0; i < n; i++) {
            check(s, i, i, n, count);       // odd length
            check(s, i, i + 1, n, count);   // even length
        }

        return count;
    }
};


int main() {
    Solution obj;

    string s = "aaa";

    cout << "Input string: " << s << endl;
    cout << "The number of palindromic substrings are:-" << endl;

    cout << "Brute Force (Recursion): "
         << obj.BruteIcountSubstrings(s) << endl;

    cout << "Memoization (Top-Down DP): "
         << obj.BruteIIcountSubstrings(s) << endl;

    cout << "DP Tabulation (Bottom-Up): "
         << obj.BetterCountSubstrings(s) << endl;

    cout << "Optimal (Expand Around Center): "
         << obj.OptimalCountSubstrings(s) << endl;

    return 0;
}