#include <iostream>
using namespace std;

/*

Example Output for n = 4:

4444444
4333334
4322234
4321234
4322234
4333334
4444444

*/


// Prints concentric number square pattern (Pattern 22)
void pattern22(int n){
    for(int i = 0; i < 2*n - 1; i++){
        for(int j = 0; j < 2*n - 1; j++){

            // distances from all four sides
            int top = i;
            int left = j;
            int bottom = (2*n - 2) - i; 
            int right = (2*n - 2) - j;

            // smallest distance determines the layer
            cout << (n - min(min(top, bottom), min(left, right)));
        }
        cout << endl; // next line
    }
}

int main(){
    int n;
    cout << "Enter the size of pattern: ";
    cin >> n;        // read input
    pattern22(n);    // print pattern
    return 0;
}