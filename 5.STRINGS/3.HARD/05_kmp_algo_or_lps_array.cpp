/*
KMP Algorithm or LPS array

OR, 
Find the Index of the First Occurrence in a String 
(Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.)

Given two strings, one is a text string, text, and the other is a pattern string, pattern. 
Find and print the indices of all the occurrences of the pattern string within the text string. 
Use 0-based indexing for the indices, and ensure that the indices are in ascending order. 
If the pattern does not occur in the text, return an empty list.

Implement this solution using the Knuth-Morris-Pratt (KMP) algorithm for efficient pattern matching.

Example 1

Input: text = "abracadabra", pattern = "abra"

Output: 0 7

Expalanation : The pattern "abra" appears at the 0st and 7th positions in the text "abracadabra".

Example 2

Input: text = "abcabcabc", pattern = "abc"

Output: 0 3 6

Expalanation : The pattern "abc" appears at the 0st, 3th, and 6th positions in the text "abcabcabc".
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> buildLPS(string& pat) {
        int m = pat.size();
        vector<int> lps(m, 0);

        int pre  = 0;
        int suff = 1;

        while(suff < m) {
            if(pat[pre] == pat[suff]) {
                lps[suff] = pre + 1;
                pre++;
                suff++;
            }
            else {
                if(pre == 0) suff++;
                else         pre = lps[pre-1];
            }
        }
        return lps;
    }

    vector<int> search(string pat, string txt) {
        vector<int> result;
        int n = txt.size();
        int m = pat.size();

        if(m > n) return result;

        vector<int> lps = buildLPS(pat);

        int i = 0;  
        int j = 0;  

        while(i < n) {
            if(txt[i] == pat[j]) {
                i++;
                j++;

                if(j == m) {
                    result.push_back(i - m);  
                    j = lps[j-1];            
                }
            }
            else {
                if(j == 0) i++;
                else       j = lps[j-1];
            }
        }
        return result;
    }
};

int main() {
    Solution obj;
    string text = "abracadabra";
    string pat = "abra";

    vector<int> ans = obj.search(pat, text);

    if(ans.empty()) {
        cout << "Pattern not found" << endl;
    } else {
        cout << "Found at indices: ";
        for(int idx : ans) cout << idx << " ";
        cout << endl;
    }

    return 0;
}