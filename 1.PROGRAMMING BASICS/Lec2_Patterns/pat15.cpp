#include <iostream>
using namespace std;

/*
Output for n=5:

A B C D 
A B C
A B
A

*/

void pattern15(int n){
    // Iterate through each row
    for(int i = 0; i < n; i++){
        // Print characters from A to A+(n-i-1)
        for(char ch = 'A'; ch <= 'A' + (n - i - 1); ch++){
            cout << ch << " ";
        }
        cout << endl;
    }
}

int main(){
    int n;
    cout << "Enter the size of pattern: ";
    cin >> n;
    pattern15(n);

    return 0;
}