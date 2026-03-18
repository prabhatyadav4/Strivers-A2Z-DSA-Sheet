/*
1781. Sum of Beauty of All Substrings

The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.

For example, the beauty of "abaacc" is 3 - 1 = 2.
Given a string s, return the sum of beauty of all of its substrings.

Example 1:

Input: s = "aabcb"
Output: 5
Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.
Example 2:

Input: s = "aabcbaa"
Output: 17
 
Constraints:

1 <= s.length <= 500
s consists of only lowercase English letters.
*/

#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
    public:

    int beautySum(string s) {
        int n = s.length();
        int sum = 0;

        for(int i = 0; i < n; i++){
            unordered_map<char, int> freq;
            for(int j = i; j < n; j++){
                freq[s[j]]++;

                int maxi = INT_MIN;
                int mini = INT_MAX;

                for(auto it : freq){
                    mini = min(mini, it.second);
                    maxi = max(maxi, it.second);
                }

                sum += (maxi - mini);
            }
        }

        return sum;
    }
};

int main() {
    Solution obj;

    string s = "aabcbaa";

    cout << "The sum of beauty substrings: " << obj.beautySum(s) << endl;

    return 0;
}