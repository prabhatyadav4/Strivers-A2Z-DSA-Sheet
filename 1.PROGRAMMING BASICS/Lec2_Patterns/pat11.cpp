#include <iostream>
using namespace std;

/*
Example Output for n = 5:
1
0 1
1 0 1
0 1 0 1
1 0 1 0 1
*/

int start = 1;

void pattern11(int n){
    for(int i = 0; i < n; i++){
        
        // set starting value based on row index
        if(i % 2 == 0){
            start = 1;
        } else {
            start = 0;
        }

        // print alternating 1s and 0s
        for(int j = 0; j <= i; j++){
            cout << start << " ";
            start = 1 - start;  // flip between 1 and 0
        }

        cout << endl;  // next line
    }
}

int main(){
    int n;
    cout << "Enter the size of pattern: ";
    cin >> n;            // take input
    pattern11(n);        // print pattern

    return 0;
}