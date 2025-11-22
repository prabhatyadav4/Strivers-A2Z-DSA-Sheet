#include <iostream>
using namespace std;

/*

Example Output for n = 5:

*****
*   *
*   *
*   *
*****

*/

// Prints a hollow square of size n
void pattern21(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            
            // Print stars on borders only
            if(i == 0 || i == n-1 || j == 0 || j == n-1)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl; // next line
    }
}

int main(){
    int n;
    cout << "Enter the size of pattern: ";
    cin >> n;          // read input
    pattern21(n);      // draw pattern
    return 0;
}