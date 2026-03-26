/*
214. Shortest Palindrome

You are given a string s. You can convert s to a palindrome by adding characters in front of it.

Return the shortest palindrome you can find by performing this transformation.

Example 1:

Input: s = "aacecaaa"
Output: "aaacecaaa"
Example 2:

Input: s = "abcd"
Output: "dcbabcd"
 
Constraints:

0 <= s.length <= 5 * 104
s consists of lowercase English letters only.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
    	reverse(rev.begin(), rev.end());
    
    	string temp = s + "$" + rev;
    
    	vector<int> lps(temp.size(), 0);
    
    	int pre = 0, suff = 1;
    	while(suff < temp.size()) {
    		if(temp[pre] == temp[suff]) {
    			lps[suff] = pre + 1;
    			pre++;
    			suff++;
    		}
    		else {
    			if(pre == 0)    suff++;
    			else pre = lps[pre - 1];
    		}
    	}
    
    	int size = s.size() - lps.back();
        string ans =  s.substr(s.size() - size, s.size());
        reverse(ans.begin(), ans.end());
        return ans + s;
    }
};

int main() {
    Solution obj;

    string s = "aacecaaa";

    cout << "The shortest palindrome is: " << obj.shortestPalindrome(s) << endl;

    return 0;
}