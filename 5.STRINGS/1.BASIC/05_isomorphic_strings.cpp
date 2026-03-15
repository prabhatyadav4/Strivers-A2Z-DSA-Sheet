/*
Isomorphic String

Problem Statement: Given two strings s and t, determine if they are isomorphic. 
Two strings s and t are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters. 
No two characters may map to the same character, but a character may map to itself.

Examples

Example 1
Input:
 s = "paper", t = "title"
Output:
 true
Explanation:
 The characters in "s" can be mapped one-to-one to characters in "t": 
'p' → 't', 'a' → 'i', 'e' → 'l', 'r' → 'e'
Since the mapping is consistent and unique for each character, the strings are isomorphic.

Example 2
Input:
 s = "foo", t = "bar"
Output:
 false
Explanation:
 'f' → 'b' is fine, 'o' → 'a' for the first 'o', But the second 'o' in "s" would need to map to 'r' in "t", which conflicts with the earlier mapping of 'o' → 'a'
This inconsistency makes it impossible to convert "s" to "t" using a one-to-one character mapping.
*/

#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
    public:

    // Index Method
    bool IndexIsomorphicString(string s, string t){
        int m1[256] = {0}, m2[256] = {0};

        for(int i = 0; i < s.size(); i++){
            if(m1[s[i]] != m2[t[i]])  return false;
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1; 
        }

        return true;
    }

    // Hashmap Method
    bool MapIsomorphicString(string s, string t){
        unordered_map<char, char> mp1;
        unordered_map<char, char> mp2;

        for(int i = 0; i < s.size(); i++){
            char ch1 = s[i];
            char ch2 = t[i];

            if((mp1.find(ch1) != mp1.end() && mp1[ch1] != ch2) ||
                (mp2.find(ch2) != mp2.end() && mp2[ch2] != ch1)) {
                    return false;
            }

            mp1[ch1] = ch2;
            mp2[ch2] = ch1;
        }

        return true;
    }
};

int main() {
    Solution obj;

    string s = "paper";
      string t = "title";
      
      bool result1 = obj.IndexIsomorphicString(s, t);
      if (result1) {
          cout << "INDEX: Strings are isomorphic." << endl;
      } else {
          cout << "INDEX: Strings are not isomorphic." << endl;
      }

      bool result2 = obj.MapIsomorphicString(s, t);
      if (result2) {
          cout << "MAP: Strings are isomorphic." << endl;
      } else {
          cout << "MAP: Strings are not isomorphic." << endl;
      }
      
      return 0;
}