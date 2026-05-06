/*
Length of longest palindromic sub-string : Recursion

Given a string S, the task is to find the length of the longest substring which is a palindrome.

Examples: 

Input: S = "aaaabbaa" 
Output: 6 
Explanation: Substring "aabbaa" is the longest palindromic sub-string.

Input: S = "banana" 
Output: 5 
Explanation: Substring "anana" is the longest palindromic sub-string. 
*/

#include <iostream>
#include <vector>
using namespace std;

int LPS1(string &s, int i, int j) {
    if(i > j)   return 0;
    if(i == j)  return 1;

    if(s[i] == s[j]) {
        return 2 + LPS1(s, i + 1, j - 1);
    }

    return max(LPS1(s, i + 1, j), LPS1(s, i, j - 1));
}

int solve(string &s, int i, int j, vector<vector<int>> &dp) {
    if(i > j)   return 0;
    if(i == j)  return 1;
    if(dp[i][j] != -1)  return dp[i][j];

    if(s[i] == s[j]) {
        return dp[i][j] = 2 + solve(s, i + 1, j - 1, dp);
    }

    return dp[i][j] = max(solve(s, i + 1, j, dp), solve(s, i, j - 1, dp));
}

int LPS2(string &s) {
    int n = s.length();
    vector<vector<int>> dp(n, vector<int> (n, -1));

    return solve(s, 0, n - 1, dp);
}

int main() {
    string s1 = "aaaabbaa";
    int n = s1.length();
    cout << "RECURSION: The length of the LPS is: " << LPS1(s1, 0, n - 1);

    string s2 = "banana";
    cout << "\nMEMOIZATION: The length of the LPS is: " << LPS2(s2);

    return 0;
}