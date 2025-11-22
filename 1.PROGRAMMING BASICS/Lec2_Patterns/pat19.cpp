#include <iostream>
using namespace std;

/*
Example Output for n = 5:

**********
****  ****
***    ***
**      **
*        *
*        *
**      **
***    ***
****  ****
**********

*/

void pattern19(int n){
    int spaces = 0;                   // spaces between star blocks (upper half)

    // Upper half
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i; j++){   // left stars
            cout << "*";
        }
        for(int j = 0; j < spaces; j++){  // middle spaces
            cout << " ";
        }
        for(int j = 0; j < n - i; j++){   // right stars
            cout << "*";
        }
        spaces += 2;                       // increase spaces
        cout << endl;
    }

    // Reset spaces for lower half (must be 2*(n−1))
    spaces = 2 * (n - 1);

    // Lower half
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){       // left stars
            cout << "*";
        }
        for(int j = 0; j < spaces; j++){   // spaces
            cout << " ";
        }
        for(int j = 0; j <= i; j++){       // right stars
            cout << "*";
        }
        spaces -= 2;                       // decrease spaces
        cout << endl;
    }
}

int main(){
    int n;
    cout << "Enter the size of pattern: ";
    cin >> n;              // user input
    pattern19(n);          // print pattern

    return 0;
}