/*
 * Switch Case
 * Difficulty: Easy | Points: 100
 *
 * Problem:
 * Given the integer 'day' denoting the day number, print which day of the week it is.
 * Week starts from Monday. For values greater than 7 or less than 1, print "Invalid".
 *
 * Requirements:
 * - Ensure only the first letter of the answer is capitalised.
 *
 * Print instructions:
 * - C++       : cout << variable_name;
 * - Java      : System.out.print();
 * - Python    : print()
 * - JavaScript: console.log()
 *
 * Examples:
 * Input:  day = 3
 * Output: Wednesday
 *
 * Input:  day = 8
 * Output: Invalid
 */

#include <iostream>
using namespace std;

class Solution {
public:
    void whichWeekDay(int day) {
        // Switch statement to map day number to day name
        switch(day){
            case 1:
                cout << "Monday";
                break;
            case 2:
                cout << "Tuesday";
                break;
            case 3:
                cout << "Wednesday";
                break;
            case 4:
                cout << "Thursday";
                break;
            case 5:
                cout << "Friday";
                break;
            case 6:
                cout << "Saturday";
                break;
            case 7:
                cout << "Sunday";
                break;
            default:
                // Handle invalid day numbers
                cout << "Invalid";
                break;
        }
    }
};

int main(){
    int day;
    // Get day number from user
    cout << "Enter the day number: ";
    cin >> day;
    
    // Create solution object and call function
    Solution obj;
    obj.whichWeekDay(day);
    return 0;
}