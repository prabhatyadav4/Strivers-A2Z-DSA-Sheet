/*
Median of 2 sorted arrays

Given two sorted arrays arr1 and arr2 of size m and n respectively, return the median of the two sorted arrays.

The median is defined as the middle value of a sorted list of numbers. In case the length of the list is even, the median is the average of the two middle elements.

Example 1

Input: arr1 = [2, 4, 6], arr2 = [1, 3, 5]

Output: 3.5

Explanation: The array after merging arr1 and arr2 will be [ 1, 2, 3, 4, 5, 6 ]. As the length of the merged list is even, the median is the average of the two middle elements. Here two medians are 3 and 4. So the median will be the average of 3 and 4, which is 3.5.

Example 2

Input: arr1 = [2, 4, 6], arr2 = [1, 3]

Output: 3.0

Explanation: The array after merging arr1 and arr2 will be [ 1, 2, 3, 4, 6 ]. The median is simply 3.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double BruteMedian(vector<int> &arr1, vector<int> &arr2) {
        vector<int> arr3;
        int n1 = arr1.size();
        int n2 = arr2.size();
        int i = 0, j = 0;

        while(i < n1 && j < n2){
            if(arr1[i] < arr2[j])   arr3.push_back(arr1[i++]);
            else    arr3.push_back(arr2[j++]);

        }
        while(i < n1)   arr3.push_back(arr1[i++]);
        while(j < n2)   arr3.push_back(arr2[j++]);

        int n = n1 + n2;

        if(n % 2 == 1)  return arr3[n/2];

        return (double)((double)(arr3[n/2]) + (double)(arr3[n/2 - 1])) / 2.0;
    }

    double OptimalMedian(vector<int> &arr1, vector<int> &arr2) {
        int n1 = arr1.size();
        int n2 = arr2.size();
        int i = 0, j = 0;
        int n = (n1 + n2);
        int idx2 = n / 2;
        int idx1 = idx2 - 1;
        int cnt = 0;
        int idx1el = -1, idx2el = -1;

        while(i < n1 && j < n2) {
            if(arr1[i] < arr2[j]){
                if(cnt == idx1)     idx1el = arr1[i];
                if(cnt == idx2)     idx2el = arr1[i];
                cnt++;
                i++;
            }
            else{
                if(cnt == idx1)     idx1el = arr2[j];
                if(cnt == idx2)     idx2el = arr2[j];
                cnt++;
                j++;
            }
        }

        while(i < n1){
            if(cnt == idx1)     idx1el = arr1[i];
            if(cnt == idx2)     idx2el = arr1[i];
            cnt++;
            i++;
        }

        while(j < n2){
            if(cnt == idx1)     idx1el = arr2[j];
            if(cnt == idx2)     idx2el = arr2[j];
            cnt++;
            j++;    
        }

        if(n % 2 == 1)  return idx2el;

        return (double)((double)(idx1el + idx2el)) / 2.0;
    }
};

int main() {
    Solution obj;

    vector<int> arr1 = {2, 4, 6};
    vector<int> arr2 = {1, 3, 5};

    double result1 = obj.BruteMedian(arr1, arr2);
    cout << "The median (Brute) is: " << result1 << endl;

    double result2 = obj.OptimalMedian(arr1, arr2);
    cout << "The median (Optimal) is: " << result2 << endl;

    return 0;
}