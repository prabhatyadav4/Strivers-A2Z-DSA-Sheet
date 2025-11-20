#include <iostream>
using namespace std;

/*

Function to print a right-angled numeric triangle pattern.

Signature:
void pattern3(int n)

Description:
Prints n rows where the i-th row (1-based) contains the numbers 1 through i separated by a space, then a newline. Each row grows by one number compared to the previous row.

Input: n = 5

Output:
1 
1 2 
1 2 3 
1 2 3 4 
1 2 3 4 5 

Notes:
- n should be a positive integer; if n <= 0 the function produces no output.
- The implementation prints a space after each printed number (including the last number in a row).

Time complexity: O(n^2)
Space complexity: O(1) (excluding output)
*/

void pattern3(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cout << j << " ";
        }
        cout << endl;
    }
}

int main(){
    int n;
    cout << "Enter the size of pattern: ";
    cin >> n;
    pattern3(n);

    return 0;
}