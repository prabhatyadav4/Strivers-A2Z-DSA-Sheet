/*
Merge two sorted arrays without extra space

Given two integer arrays nums1 and nums2. Both arrays are sorted in non-decreasing order.

Merge both the arrays into a single array sorted in non-decreasing order.

The final sorted array should be stored inside the array nums1 and it should be done in-place.

nums1 has a length of m + n, where the first m elements denote the elements of nums1 and rest are 0s.

nums2 has a length of n.

Example 1

Input: nums1 = [-5, -2, 4, 5], nums2 = [-3, 1, 8]

Output: [-5, -3, -2, 1, 4, 5, 8]

Explanation:

The merged array is: [-5, -3, -2, 1, 4, 5, 8], where [-5, -2, 4, 5] are from nums1 and [-3, 1, 8] are from nums2

Example 2

Input: nums1 = [0, 2, 7, 8], nums2 = [-7, -3, -1]

Output: [-7, -3, -1, 0, 2, 7, 8]

Explanation:

The merged array is: [-7, -3, -1, 0, 2, 7, 8], where [0, 2, 7, 8] are from nums1 and [-7, -3, -1] are from nums2
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
    public:
    void BruteMerge(long long arr1[], long long arr2[], int n, int m) {
        long long arr3[n + m];
        int left = 0;
        int right = 0;
        int index = 0;

        while (left < n && right < m) {
            if (arr1[left] <= arr2[right]) {
                arr3[index] = arr1[left];
                left++;
                index++;
            }
            else {
                arr3[index] = arr2[right];
                right++;
                index++;
            }
        }

        while (left < n) {
            arr3[index++] = arr1[left++];
        }

        while (right < m) {
            arr3[index++] = arr2[right++];
        }

        for (int i = 0; i < n + m; i++) {
            if (i < n)
                arr1[i] = arr3[i];
            else
                arr2[i - n] = arr3[i];
        }
    }

    void BetterMerge(long long arr1[], long long arr2[], int n, int m) {
        int left = n - 1;
        int right = 0;

        while(left >=0 && right < m){
            if(arr1[left] > arr2[right]){
                swap(arr1[left], arr2[right]);
                left--, right++;
            }
            else{
                break;
            }
        }

        sort(arr1, arr1 + n);
        sort(arr2, arr2 + m);
    }
};
int main() {
    Solution obj;

    long long arr1[] = {1, 3, 5, 7};
    long long arr2[] = {0, 2, 6, 8, 9};
    int n = 4, m = 5;

    obj.BruteMerge(arr1, arr2, n, m);

    cout << "After merging (Brute Solution):\n" << endl;
    cout << "arr1[] = ";
    for (int i = 0; i < n; i++) cout << arr1[i] << " ";
    cout << endl;

    cout << "arr2[] = ";
    for (int i = 0; i < m; i++) cout << arr2[i] << " ";
    cout << endl;

    obj.BetterMerge(arr1, arr2, n, m);

    cout << "After merging (Better Solution):\n";

    cout << "arr1: ";
    for(int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    cout << "arr2: ";
    for(int i = 0; i < m; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    return 0;
}