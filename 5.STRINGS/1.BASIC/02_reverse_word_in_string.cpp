/*
Reverse Words in a String

Problem Statement: Given an input string, containing upper-case and lower-case letters, digits, and spaces( ' ' ). 
A word is defined as a sequence of non-space characters. 
The words in s are separated by at least one space. 
Return a string with the words in reverse order, concatenated by a single space.

Examples
Input: s = "welcome to the jungle"
Output: "jungle the to welcome"
Explanation: The words in the input string are "welcome", "to", "the", and "jungle". 
Reversing the order of these words gives "jungle", "the", "to", and "welcome". 
The output string should have exactly one space between each word.

Input: s = " amazing coding skills "
Output: "skills coding amazing"
Explanation: The input string has leading and trailing spaces, as well as multiple spaces between the words "amazing", "coding", and "skills". 
After trimming the leading and trailing spaces and reducing the multiple spaces between words to a single space, the words are "amazing", "coding", and "skills". Reversing the order of these words gives "skills", "coding", and "amazing". 
The output string should not have any leading or trailing spaces and should have exactly one space between each word.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    string BruteReverseWords(string s) {
        vector<string> words;
        string word = "";

        for(int i = 0; i < s.size(); i++){
            if(s[i] != ' '){
                word += s[i];
            }
            else if(!word.empty()){
                words.push_back(word);
                word = "";
            }
        }

        if(!word.empty()){
            words.push_back(word);
        }

        reverse(words.begin(), words.end());

        string result = "";
        
        for(int i = 0; i < words.size(); i++){
            result += words[i];
            if(i < words.size() - 1){
                result += " ";   
            }
        }

        return result;
    }

    string OptimalReverseWords(string s) {
        int n = s.length();
        string ans = "";

        reverse(s.begin(), s.end());

        for(int i = 0; i < n; i++){
            string word = "";

            while(i < n && s[i] != ' '){
                word += s[i];
                i++;
            }

            reverse(word.begin(), word.end());
            
            if(!word.empty()) {
                if(!ans.empty())     ans += " ";
                ans += word;
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;

    string s = " amazing coding skills ";

    string result1 = obj.BruteReverseWords(s);
    cout << "Brute: The reversed string is: " << result1 << endl;

    string result2 = obj.OptimalReverseWords(s);
    cout << "Optimal: The reversed string is: " << result2 << endl;

    return 0;
}