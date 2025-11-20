#include <iostream>
using namespace std;

/* 

Function to print a right-angled triangular numeric pattern where the i-th row contains the integer i repeated i times.

Input: n = 5

Output:
1 
2 2 
3 3 3 
4 4 4 4 
5 5 5 5 5 

*/

void pattern4(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cout << i << " ";
        }
        cout << endl;
    }
}

int main(){
    int n;
    cout << "Enter the size of pattern: ";
    cin >> n;
    pattern4(n);

    return 0;
}