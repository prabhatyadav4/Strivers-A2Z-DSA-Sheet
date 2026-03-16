/*
451. Sort Characters By Frequency

Given a string s, sort it in decreasing order based on the frequency of the characters. 
The frequency of a character is the number of times it appears in the string.
Return the sorted string. If there are multiple answers, return any of them.

Example 1:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.


Constraints:

1 <= s.length <= 5 * 105
s consists of uppercase and lowercase English letters and digits.
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    static bool comparator(pair<int, char> p1, pair<int, char> p2)
    {
        if (p1.first > p2.first)
            return true;
        if (p1.first < p2.first)
            return false;
        return p1.second < p2.second;
    }

    string frequencySort(string s)
    {
        pair<int, char> freq[128];

        for (int i = 0; i < 128; i++)
        {
            freq[i] = {0, (char)i};
        }

        for (char ch : s)
        {
            freq[ch].first++;
        }

        sort(freq, freq + 128, comparator);

        string ans;
        for (int i = 0; i < 128; i++)
        {
            if (freq[i].first > 0)
                for(int j = 0; j < freq[i].first; j++){
                    ans.push_back(freq[i].second);
                }
        }

        return ans;
    }
};

int main()
{
    Solution obj;

    string s = "tree";

    cout << "The valid answer is: " << obj.frequencySort(s) << endl;

    return 0;
}