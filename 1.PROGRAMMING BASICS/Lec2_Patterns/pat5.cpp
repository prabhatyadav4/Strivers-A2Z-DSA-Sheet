#include <iostream>
using namespace std;

/*

Function to print a right-aligned triangle pattern of asterisks

Input: n = 4

Output:
* * * * 
* * * 
* * 
* 

*/

void pattern5(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n - i + 1; j++){
            cout << "* ";
        }
        cout << endl;
    }
}

int main(){
    int n;
    cout << "Enter the size of pattern: ";
    cin >> n;
    pattern5(n);

    return 0;
}