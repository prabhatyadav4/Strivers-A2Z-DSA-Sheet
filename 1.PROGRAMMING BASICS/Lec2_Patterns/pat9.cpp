#include <iostream>
using namespace std;


/*

Function to print a diamond pattern of asterisks

Input: n = 4

Output:
     *
    ***
   *****
  *******
   *****
    ***
     *

*/

void pattern9(int n){
    for(int i = 0; i < n; i++){
        // Space
        for(int j = 0; j < n - i - 1 ; j++){
            cout << " ";
        }
        // Star
        for(int k = 0; k < 2 * i + 1; k++){
            cout << "*";
        }
        // Space
        for(int l = 0; l < n - i - 1; l++){
            cout << " ";
        }
        cout << endl;
    }
    for(int v = 0; v < n; v++){
        // Space
        for(int x = 0; x < v; x++){
            cout << " ";
        }
        // Star
        for(int y = 0; y < 2*n-(2*v+1); y++){
            cout << "*";
        }
        // Space
        for(int z = 0; z < v; z++){
            cout << " ";
        }
        cout << endl;
    }
}

int main(){
    int n;
    cout << "Enter the size of pattern: ";
    cin >> n;
    pattern9(n);

    return 0;
}