#include <iostream>
using namespace std;

int start = 1;
void pattern11(int n){
    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            start = 1;
        }
        else{
            start = 0;
        }
        for(int j = 0; j <= i; j++){
            cout << start << " ";
            start = 1 - start;
        }
        cout << endl;
    }
}

int main(){
    int n;
    cout << "Enter the size of pattern: ";
    cin >> n;
    pattern11(n);

    return 0;
}