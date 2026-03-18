/*
1358. Number of Substrings Containing All Three Characters

Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.

Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
Example 2:

Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
Example 3:

Input: s = "abc"
Output: 1
 

Constraints:

3 <= s.length <= 5 x 10^4
s only consists of a, b or c characters.
*/

#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
    public: 

    int BruteNumOfSubstrings(string s) {
        int n = s.size();
        int cnt = 0;
        
        for(int i = 0; i < n; i++){
            int hash[3] = {0};
            for(int j = i; j < n; j++){
                hash[s[j] - 'a'] = 1;
                if(hash[0] + hash[1] + hash[2] == 3){
                    cnt++;
                }
            }
        }

        return cnt;
    }

    int BetterNumOfSubstrings(string s) {
        int n = s.size();
        int cnt = 0;

        for(int i = 0; i < n; i++){
            int hash[3] = {0};
            for(int j = i; j < n; j++){
                hash[s[j] - 'a'] = 1;
                if(hash[0] + hash[1] + hash[2] == 3){
                    cnt += (n - j);
                    break;
                }
            }
        }

        return cnt;
    }

    int OptimalNumOfSubstrings(string s) {
        int n = s.size();
        int lastSeen[3] = {-1,-1,-1};
        int cnt = 0;

        for(int i = 0; i < n; i++){
            lastSeen[s[i] - 'a'] = i;
            if(lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1){
                cnt += 1 + min(lastSeen[0], min(lastSeen[1], lastSeen[2]));
            } 
        }

        return cnt;
    }
};

int main() {
    Solution obj;

    string s = "abcabc";

    int result1 = obj.BruteNumOfSubstrings(s);
    cout << "BRUTE: No. of Strings: " << result1 << endl;
    
    int result2 = obj.BetterNumOfSubstrings(s);
    cout << "BETTER: No. of Strings: " << result2 << endl;

    int result3 = obj.OptimalNumOfSubstrings(s);
    cout << "OPTIMAL: No. of Strings: " << result3 << endl;

    return 0;
}