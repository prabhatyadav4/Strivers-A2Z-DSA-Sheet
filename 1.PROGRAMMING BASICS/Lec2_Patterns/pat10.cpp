#include <iostream>
using namespace std;

/*

For n = 4 the output is:
*
**
***
****
***
**
*


- Time complexity: O(n^2) (total number of printed characters is proportional to n^2)
- Space complexity: O(1) additional space (only loop variables used)

*/

void pattern10(int n){
    for(int i = 1; i <= 2 * n -1; i++){
        int stars = i;
        if(i > n){
            stars = 2 * n - i;
        }
        for(int j = 1; j <= stars; j++){
            cout << "*";
        }
        cout << endl;
    }
}

int main(){
    int n;
    cout << "Enter the size of pattern: ";
    cin >> n;
    pattern10(n);
    
    return 0;
}