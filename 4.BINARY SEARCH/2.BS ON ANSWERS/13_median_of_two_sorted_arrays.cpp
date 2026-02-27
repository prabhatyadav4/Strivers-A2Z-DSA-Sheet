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

    double BetterMedian(vector<int> &arr1, vector<int> &arr2) {
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

    double Optimal1Median(vector<int> &arr1, vector<int> &arr2) {
        if(arr1.size() > arr2.size())   return Optimal1Median(arr2, arr1);

        int m = arr1.size();
        int n = arr2.size();
        
        int left = 0;
        int right = m;

        while(left <= right){
            int Px = left + (right - left) / 2;
            int Py = (m + n + 1) / 2 - Px;

            int x1 = (Px == 0) ? INT_MIN : arr1[Px - 1];
            int x2 = (Py == 0) ? INT_MIN : arr2[Py - 1];
            int x3 = (Px == m) ? INT_MAX : arr1[Px];
            int x4 = (Py == n) ? INT_MAX : arr2[Py];

            if(x1 <= x4 && x2 <= x3){
                if((m + n) % 2 == 1)    return max(x1,x2);

                return (max(x1, x2) + min(x3, x4)) / 2.0;
            }

            if(x1 > x4) right = Px - 1;
            else        left = Px + 1;  
        }

        return -1;
    }

    double Optimal2Median(vector<int>& a, vector<int>& b) {
    int n1 = a.size();
    int n2 = b.size();

    if (n1 > n2) return Optimal2Median(b, a);

    int low = 0, high = n1;
    int left = (n1 + n2 + 1) / 2;
    int n = n1 + n2;

    while (low <= high) {
        int mid1 = (low + high) >> 1;
        int mid2 = left - mid1;

        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;

        if (mid1 < n1) r1 = a[mid1];
        if (mid2 < n2) r2 = b[mid2];
        if (mid1 - 1 >= 0) l1 = a[mid1 - 1];
        if (mid2 - 1 >= 0) l2 = b[mid2 - 1];

        if (l1 <= r2 && l2 <= r1) {
            if (n % 2 == 1) return max(l1, l2);
            return (max(l1, l2) + min(r1, r2)) / 2.0;  
        }
        else if (l1 > r2) high = mid1 - 1;  
        else              low  = mid1 + 1;  
    }

    return 0;
}
};

int main() {
    Solution obj;

    vector<int> arr1 = {2, 4, 6};
    vector<int> arr2 = {1, 3, 5};

    double result1 = obj.BruteMedian(arr1, arr2);
    cout << "The median (Brute) is: " << result1 << endl;

    double result2 = obj.BetterMedian(arr1, arr2);
    cout << "The median (Better) is: " << result2 << endl;

    double result3 = obj.Optimal1Median(arr1, arr2);
    cout << "The median (Optimal-1) is: " << result3 << endl;

    double result4 = obj.Optimal2Median(arr1, arr2);
    cout << "The median (Optimal-2) is: " << result4 << endl;

    return 0;
}