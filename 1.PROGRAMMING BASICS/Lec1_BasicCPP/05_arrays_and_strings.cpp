#include <iostream>
using namespace std;

// Array

int main(){
    // Initialize array with 5 elements
    int arr[5] = {1,2,3,4,5};
    // Print all elements
    for(int i = 0; i < 5; i++){
        cout << arr[i] << " ";
    }
    // Print element at index 2
    cout << "\n" << arr[2] << endl;
    return 0;
}

// 2D Array

int main(){
    // Declare 2D array (2x3)
    int arr[2][3];
    // Input elements
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            cin >> arr[i][j];
        }
    }
    // Print elements in grid format
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    // Print last element
    cout << arr[1][2] << endl;

    return 0;
}

// String

int main(){
    // Initialize string
    string s = "Striver";
    // Print each character
    for(int i = 0; i < s.size(); i++){
        cout << s[i] << endl;
    }

    // Print last character
    cout << s[s.size()-1] << endl;
    // Replace last character with 'z'
    s[s.size()-1] = 'z';
    // Print modified string
    for(int i = 0; i < s.size(); i++){
        cout << s[i];
    }
    return 0;
}