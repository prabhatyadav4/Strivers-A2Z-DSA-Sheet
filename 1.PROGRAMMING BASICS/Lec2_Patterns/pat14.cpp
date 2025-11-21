#include <iostream>
using namespace std;

void pattern14(int n){
    for(int i = 1; i <= n; i++){
        for(char ch= 'A'; ch < 'A' + i; ch++){
            cout << ch << " ";
        }
        cout << endl;
    }
}

int main(){
    int n;
    cout << "Enter the size of pattern: ";
    cin >> n;
    pattern14(n);

    return 0;
}