#include <iostream>
using namespace std;

/*
Output for n = 5:
1
2 3
4 5 6
7 8 9 10
11 12 13 14 15
*/

void pattern13(int n){
    int num = 1;              // starting number
    for(int i = 1; i <= n; i++){      // loop for each row
        for(int j = 1; j <= i; j++){  // print numbers in each row
            cout << num << " ";
            num++;                    // increment number
        }
        cout << endl;                 // new line after each row
    }
}

int main(){
    int n;
    cout << "Enter the size of pattern: ";
    cin >> n;              // take input
    pattern13(n);          // print pattern

    return 0;
}