#include <iostream>
using namespace std;

/*

Function to print a right-angled decreasing numeric triangle pattern.

Given an integer n, the function prints n rows. On the i-th row (1-based),
it prints the numbers from 1 up to (n - i + 1), each followed by a space.

Input: n = 4

Output:
1 2 3 4 
1 2 3 
1 2 
1 

Time Complexity: O(n^2)
Space Complexity: O(1)

*/

void pattern6(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n - i + 1; j++){
            cout << j << " ";
        }
        cout << endl;
    }
}

int main(){
    int n;
    cout << "Enter the size of pattern: ";
    cin >> n;
    pattern6(n);

    return 0;
}