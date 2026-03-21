/*
38. Count and Say

The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

countAndSay(1) = "1"
countAndSay(n) is the run-length encoding of countAndSay(n - 1).
Run-length encoding (RLE) is a string compression method that works by replacing consecutive identical characters (repeated 2 or more times) with the concatenation of the character and the number marking the count of the characters (length of the run). 
For example, to compress the string "3322251" we replace "33" with "23", replace "222" with "32", replace "5" with "15" and replace "1" with "11". Thus the compressed string becomes "23321511".

Given a positive integer n, return the nth element of the count-and-say sequence.

Example 1:

Input: n = 4

Output: "1211"

Explanation:

countAndSay(1) = "1"
countAndSay(2) = RLE of "1" = "11"
countAndSay(3) = RLE of "11" = "21"
countAndSay(4) = RLE of "21" = "1211"
Example 2:

Input: n = 1

Output: "1"

Explanation:

This is the base case.

Constraints:

1 <= n <= 30
*/

#include <iostream>
using namespace std;

class Solution {
public:

    // =============================================
    // APPROACH 1: Recursion (Brute)
    // Time: O(N×M)  Space: O(N×M)
    // =============================================
    string countAndSayBrute(int n) {
        if(n == 1) return "1";

        string say = countAndSayBrute(n - 1);

        string result = "";
        for(int i = 0; i < say.length(); i++){
            int count = 1;
            char ch = say[i];

            while(i < say.length() - 1 && say[i] == say[i + 1]){
                count++;
                i++;
            }
            result += to_string(count) + string(1, ch);
        }
        return result;
    }

    // =============================================
    // APPROACH 2: Iteration (Better)
    // Time: O(N×M)  Space: O(M)
    // =============================================
    string countAndSayBetter(int n) {
        string result = "1";

        for(int i = 1; i < n; i++){
            string temp = "";
            int len = result.length();

            for(int j = 0; j < len; j++){
                int count = 1;
                char ch = result[j];

                while(j < len - 1 && result[j] == result[j + 1]){
                    count++;
                    j++;
                }
                temp += to_string(count) + string(1, ch);
            }
            result = temp;
        }
        return result;
    }

    // =============================================
    // APPROACH 3: Two String Swap (Optimal)
    // Time: O(N×M)  Space: O(M)
    // =============================================
    string countAndSayOptimal(int n) {
        string curr = "1";
        string next = "";

        for(int i = 1; i < n; i++){
            next = "";
            int len = curr.length();

            for(int j = 0; j < len; j++){
                int count = 1;
                char ch = curr[j];

                while(j < len - 1 && curr[j] == curr[j + 1]){
                    count++;
                    j++;
                }
                next += to_string(count) + string(1, ch);
            }
            curr = next;  // swap to next term
        }
        return curr;
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter the count: ";
    cin >> n;

    cout << "\nBRUTE   (Recursion):       " << obj.countAndSayBrute(n)   << endl;
    cout << "BETTER  (Iteration):       " << obj.countAndSayBetter(n)  << endl;
    cout << "OPTIMAL (Two String Swap): " << obj.countAndSayOptimal(n) << endl;

    return 0;
}