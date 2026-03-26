#include <iostream>
using namespace std;

/*
Longest Happy Prefix

Problem Statement: Given a string s, return the longest happy prefix of s. 
A happy prefix is a string that is both a proper prefix and a proper suffix.
If no such prefix exists, return an empty string .

Note: A proper prefix/proper suffix of a string is any prefix/suffix that is not equal to the entire string.

Examples
Input: s = "ababab"
Output: "abab"
Explanation:  "abab" is the longest prefix which is also suffix. They can overlap in the original string.
Input: s = "aaaa"
Output: "aaa"
Explanation: "aaa" is the longest proper prefix which is also a proper suffix in the string "aaaa".
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    
    string BruteLongestPrefix(string s) {
       int n = s.size();

       for(int len = n - 1; len >= 1; len--) {
        if(s.substr(0, len) == s.substr(n - len, len)) {
            return s.substr(0, len);
        }
       }

       return "";
    }

    string OptimalLongestPrefix(string s) {
        int n = s.size();
        vector<int> lps(n, 0);

        int pre = 0; 
        int suff = 1;

        while(suff < n) {
            if(s[pre] == s[suff]) {
                lps[suff] = pre + 1;
                pre++;
                suff++;
            }
            else{
                if(pre == 0)    suff++;
                else pre = lps[pre - 1];
            }
        }

        return s.substr(0, lps.back());
    }
};

int main() {
    Solution obj;
    string s = "ababab";
    cout << "BRUTE: The longest happy prefix is: " << obj.BruteLongestPrefix(s) << endl;
    cout << "OPTIMAL: The longest happy prefix is: " << obj.OptimalLongestPrefix(s) << endl;

    return 0;
}