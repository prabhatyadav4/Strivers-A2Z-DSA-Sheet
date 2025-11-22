#include <iostream>
using namespace std;

// Output for n=4:
// A 
// A B 
// A B C 
// A B C D 

void pattern14(int n){
    // Loop for each row
    for(int i = 1; i <= n; i++){
        // Print characters from A to A+i-1
        for(char ch= 'A'; ch < 'A' + i; ch++){
            cout << ch << " ";
        }
        cout << endl; // Move to next line
    }
}

int main(){
    int n;
    cout << "Enter the size of pattern: ";
    cin >> n;
    pattern14(n); // Generate the pattern

    return 0;
}