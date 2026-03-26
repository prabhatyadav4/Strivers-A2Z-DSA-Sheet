/*
686. Repeated String Match

Given two strings a and b, return the minimum number of times you should repeat string a so that string b is a substring of it. 
If it is impossible for b​​​​​​ to be a substring of a after repeating it, return -1.

Notice: string "abc" repeated 0 times is "", repeated 1 time is "abc" and repeated 2 times is "abcabc".

Example 1:

Input: a = "abcd", b = "cdabcdab"
Output: 3
Explanation: We return 3 because by repeating a three times "abcdabcdabcd", b is a substring of it.
Example 2:

Input: a = "a", b = "aa"
Output: 2
 

Constraints:

1 <= a.length, b.length <= 104
a and b consist of lowercase English letters.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int repeatedStringMatchBrute(string a, string b) {
        string temp = a;
        int repeat  = 1;

        while(temp.size() < b.size()) {
            temp += a;
            repeat++;
        }

        if(temp.find(b) != string::npos) return repeat;

        temp += a;
        if(temp.find(b) != string::npos) return repeat + 1;

        return -1; 
    }

    vector<int> buildLPS(string &s) {
        int n = s.size();
        vector<int> lps(n, 0);

        int pre = 0, suff = 1;
        while(suff < n) {
            if(s[pre] == s[suff]) {
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

    int kmpMatch(string &text, string &pat) {
        int n = text.size();
        int m = pat.size();

        vector<int> lps = buildLPS(pat);
        int i = 0, j = 0;

        while(i < n) {
            if(text[i] == pat[j]) {
                i++;
                j++;
                if(j == m) return 1;
            }
            else {
                if(j == 0) i++;
                else       j = lps[j-1];
            }
        }
        return 0;
    }

    int repeatedStringMatch(string a, string b) {
        string temp = a;
        int repeat  = 1;

        while(temp.size() < b.size()) {  
            temp += a;
            repeat++;
        }

        if(kmpMatch(temp, b) == 1)  return repeat;

        temp += a;                        
        if(kmpMatch(temp, b) == 1)  return repeat + 1;

        return -1;
    }
};

int main() {
    Solution obj;
    string a = "abcd";
    string b = "cdabcdab";

    cout << "\nBRUTE: The minimun number of times string repeated: " << obj.repeatedStringMatchBrute(a, b) << endl;
    cout << "OPTIMAL: The minimun number of times string repeated: " << obj.repeatedStringMatch(a, b) << endl;

    return 0;
}