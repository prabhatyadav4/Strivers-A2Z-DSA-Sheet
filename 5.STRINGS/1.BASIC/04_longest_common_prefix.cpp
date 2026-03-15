/*
Longest Common Prefix

Problem Statement: Write a function to find the longest common prefix string amongst an array of strings. 
If there is no common prefix, return an empty string "".

Examples
Example 1
Input:
 str = ["flower", "flow", "flight"]
Output:
 "fl"
Explanation:
 All strings in the array begin with the common prefix "fl".

Example 2
Input:
 str = ["apple", "banana", "grape", "mango"]
Output:
 ""
Explanation:
 None of the strings share a common starting sequence, so the result is an empty string.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:

    string longestCommonPrefix(vector<string> &str){
        if(str.empty())     return "";
        sort(str.begin(), str.end());
        string first = str[0];
        string last = str[str.size() - 1];
        string ans = "";
        int minLen = min(first.size(), last.size());

        for(int i = 0; i < minLen; i++){
            if(first[i] != last[i])     break;
            ans += first[i];
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<string> input = {"interview", "internet", "internal", "interval"};

    string result = obj.longestCommonPrefix(input);
    cout << "The Longest Common Prefix is: " << result << endl;

    return 0;
}