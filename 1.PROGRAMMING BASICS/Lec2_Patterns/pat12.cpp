#include <iostream>
using namespace std;

/*
Example Output for n = 5:
1        1
12      21
123    321
1234  4321
1234554321
*/

void pattern12(int n){
    int space = 2*(n-1);             // initial spaces between the number sets
    
    for(int i = 1; i <= n; i++){
        
        for(int j = 1; j <= i; j++){ // left increasing numbers
            cout << j;
        }
        
        for(int k = 1; k <= space; k++){ // middle spaces
            cout << " ";
        }
        
        for(int l = i; l >= 1; l--){     // right decreasing numbers
            cout << l;
        }
        
        cout << endl;                // next line
        space -= 2;                  // reduce spaces each row
    }
}

int main(){
    int n;
    cout << "Enter the size of pattern: ";
    cin >> n;        // take input
    pattern12(n);    // print pattern
    
    return 0;
}