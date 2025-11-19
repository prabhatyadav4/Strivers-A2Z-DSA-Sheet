// If ElseIf - Easy Problem
// Problem: Given marks of a student, print the grade:
//   Grade A if marks >= 90
//   Grade B if marks >= 70
//   Grade C if marks >= 50
//   Grade D if marks >= 35
//   Fail otherwise
// Example: marks = 95 -> "Grade A", marks = 14 -> "Fail"

#include <iostream>
using namespace std;

class Solution {
public:
    // Print the student's grade based on the marks provided.
    void studentGrade(int marks) {
        // If marks are 90 or above -> Grade A
        if (marks >= 90) {
            cout << "Grade A";
        }
        // Else if marks are 70 or above (but less than 90) -> Grade B
        else if (marks >= 70) {
            cout << "Grade B";
        }
        // Else if marks are 50 or above (but less than 70) -> Grade C
        else if (marks >= 50) {
            cout << "Grade C";
        }
        // Else if marks are 35 or above (but less than 50) -> Grade D
        else if (marks >= 35) {
            cout << "Grade D";
        }
        // Otherwise, the student has failed
        else {
            cout << "Fail";
        }
    }
};

int main() {
    Solution obj;
    int marks = 59; // Example input; change this value to test other cases
    obj.studentGrade(marks); // Output: Grade C for marks = 59
    return 0;
}
