/*
Check if two Strings are anagrams of each other

Problem Statement: Given two strings, check if two strings are anagrams of each other or not.

Examples
Example 1:
Input: CAT, ACT
Output: true
Explanation: Since the count of every letter of both strings are equal.

Example 2:
Input: RULES, LESRT 
Output: false
Explanation: Since the count of U and T  is not equal in both strings.
*/

#include <iostream>
#include <algorithm>
using namespace std;

class Solution{
    public:
    
    bool BruteIsAnagram(string s, string t){
        if(s.length() != t.length())        return false;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        for(int i = 0; i < s.length(); i++){
            if(s[i] != t[i])    return false;
        }

        return true;
    }

    bool OptimalIsAnagram(string s, string t){
        if(s.length() != s.length())        return false;

        int ch[26] = {0};

        for(int i = 0; i < s.length(); i++){
            ch[s[i] - 'A']++;
        }

        for(int i = 0; i < t.length(); i++){
            ch[t[i] - 'A']--;
        }

        for(int i = 0; i < 26; i++){
            if(ch[i] != 0){
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution obj;

    string s = "INTEGER";
    string t = "TEGERNI";

    bool result1 = obj.BruteIsAnagram(s, t);
    cout << "BRUTE: " << (result1 ? "They are anagrams." : "They are not anagrams.") << endl;

    bool result2 = obj.OptimalIsAnagram(s, t);
    cout << "OPTIMAL: " << (result2 ? "They are anagrams." : "They are not anagrams.") << endl;

    return 0;
}