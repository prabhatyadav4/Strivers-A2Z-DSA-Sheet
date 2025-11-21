#include <iostream>
using namespace std;

void pattern17(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            cout << " ";
        }
        char ch = 'A';
        int breakpoint = (2 * i + 1) / 2;
        for(int k = 1; k <= 2 * i + 1; k++){
            cout << ch;
            if(k <= breakpoint){
                ch++;
            }
            else{
                ch--;
            }
        }
        for(int l = 0; l < n - i - 1; l++){
            cout << " ";
        }
        cout << endl;
    }
}

int main(){
    int n;
    cout << "Enter the size of pattern: ";
    cin >> n;
    pattern17(n);

    return 0;
}