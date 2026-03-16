/*
Check if one string is rotation of another

Problem Statement: Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.
A shift on s consists of moving the leftmost character of s to the rightmost position. 
For example, if s = "abcde", then it will be "bcdea" after one shift.

Examples
Example 1:
Input:
 s = "rotation", goal = "tionrota"
Output:
 true
Explanation:
 After multiple left shifts on "rotation", we get:
    1st shift → "otationr"
    2nd shift → "tationro"
    3rd shift → "ationrot"
    4th shift → "tionrota"
    So the goal string can be obtained by rotating the original string.

Example 2:
Input:
 s = "hello", goal = "lohelx"
Output:
 false
Explanation:
Even after all possible rotations of "hello", we cannot form "lohelx" due to the presence of an extra character 'x'. Hence, it's not possible.
*/

#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
    public: 

    bool BruteRotateString(string s, string goal) {
        if(s.length() != goal.length())     return false;

        for(int i = 0; i < s.length(); i++){
            string rotated = s.substr(i) + s.substr(0, i);
            if(rotated == goal) return true;
        }

        return false;
    }

    bool BetterRotateString(string s, string goal) {
        if(s.length() != goal.length())     return false;

        for(int i = 0; i < s.length(); i++){
            rotate(s.begin(), s.begin() + 1, s.end());

            if(s == goal)   return true;
        }

        return false;
    }

    bool OptimalRotateString(string s, string goal) {
        if(s.length() != goal.length())     return false;
        
        string doubledS = s + s;
        
        return doubledS.find(goal) != string::npos;
    }
};

int main() {
    Solution obj;

    string s = "rotation";
    string goal = "tionrota";

    bool result1 = obj.BruteRotateString(s, goal);
    cout << (result1 ? "BRUTE: Rotation is possible." : "BRUTE: Rotation is not possible") << endl;

    bool result2 = obj.BetterRotateString(s, goal);
    cout << (result2 ? "BETTER: Rotation is possible." : "BETTER: Rotation is not possible") << endl;

    bool result3 = obj.OptimalRotateString(s, goal);
    cout << (result3 ? "OPTIMAL: Rotation is possible." : "OPTIMAL: Rotation is not possible") << endl;
}