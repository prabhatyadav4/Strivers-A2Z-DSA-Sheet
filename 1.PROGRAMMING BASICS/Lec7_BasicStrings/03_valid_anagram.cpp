/*
242. Valid Anagram

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

Example 1:

Input: s = "anagram", t = "nagaram"

Output: true

Example 2:

Input: s = "rat", t = "car"

Output: false



Constraints:
1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.

Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?kk
*/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool isAnagramI(string s, string t)
{
    if (s.length() != t.length())
    {
        return false;
    }

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    return s == t;
}

bool isAnagramII(string s, string t)
{
    if (s.length() != t.length())
    {
        return false;
    }

    int ch[26] = {0};

    for (int i = 0; i < s.length(); i++)
    {
        ch[s[i] - 'a']++;
    }

    for (int i = 0; i < t.length(); i++)
    {
        ch[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++)
    {
        if (ch[i] != 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    string s1 = "anagram";
    string t1 = "nagaram";
    string s2 = "rat";
    string t2 = "car";

    cout << boolalpha;
    cout << "isAnagramI (anagram, nagaram) -> " << isAnagramI(s1, t1) << endl;
    cout << "isAnagramII (anagram, nagaram) -> " << isAnagramII(s1, t1) << endl;
    cout << "isAnagramI (rat, car) -> " << isAnagramI(s2, t2) << endl;
    cout << "isAnagramII (rat, car) -> " << isAnagramII(s2, t2) << endl;

    return 0;
}