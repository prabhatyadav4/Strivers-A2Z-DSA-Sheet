/*
Palindrome String

You are given a string s. Your task is to determine if the string is a palindrome. A string is considered a palindrome if it reads the same forwards and backwards.

Examples :

Input: s = "abba"
Output: true
Explanation: "abba" reads the same forwards and backwards, so it is a palindrome.

Input: s = "abc" 
Output: false
Explanation: "abc" does not read the same forwards and backwards, so it is not a palindrome.

Constraints:
1 ≤ s.size() ≤ 106
The string s contains only lowercase english letters (a-z).
*/

#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string &s, int left, int right) {
    if(left >= right)   return true;
    if(s[left] != s[right]) return false;

    return isPalindrome(s, left + 1, right - 1);
}

int main() {
    string s = "abba";
    isPalindrome(s, 0, s.size() - 1) ? cout << "String is Palindrome" : cout << "String is not Palindrome";

    return 0;
}