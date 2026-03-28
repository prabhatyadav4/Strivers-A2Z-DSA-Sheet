/*
K-th element of two Arrays

Given two sorted arrays a[] and b[] and an element k, the task is to find the element that would be at the kth position of the combined sorted array.

Examples :

Input: a[] = [2, 3, 6, 7, 9], b[] = [1, 4, 8, 10], k = 5
Output: 6
Explanation: The final combined sorted array would be [1, 2, 3, 4, 6, 7, 8, 9, 10]. The 5th element of this array is 6.

Input: a[] = [1, 4, 8, 10, 12], b[] = [5, 7, 11, 15, 17], k = 6
Output: 10
Explanation: Combined sorted array is [1, 4, 5, 7, 8, 10, 11, 12, 15, 17]. The 6th element of this array is 10.


Constraints:
1 ≤ a.size(), b.size() ≤ 106
1 ≤ k ≤ a.size() + b.size()
0 ≤ a[i], b[i] ≤ 108
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:

    int BruteKthElement(vector<int> &a, vector<int> &b, int k) {
        int m = a.size();
        int n = b.size();
        
        vector<int> temp(m + n);
        
        int i = 0, j = 0, idx = 0;
        
        while(i < m && j < n) {
            if(a[i] < b[j]) {
                temp[idx++] = a[i++];
            }
            else {
                temp[idx++] = b[j++];
            }
        }
        
        while(i < m) {
            temp[idx++] = a[i++];
        }
        
        while(j < n) {
            temp[idx++] = b[j++];
        }
        
        return temp[k - 1];
    }

    int BetterKthElement(vector<int> &a, vector<int> &b, int k) {
        int m = a.size();
        int n = b.size();
        
        int i = 0, j = 0, count = 0;
        
        while(i < m && j < n) {
            int val = 0;
            
            if(a[i] < b[j])     val = a[i++];
            else                val = b[j++];
            
            count++;
            
            if(count == k)  return val;
        }
        
        while(i < m) {
            count++;
            if(count == k)   return a[i];
            i++;
        }
        
        while(j < n) {
            count++;
            if(count == k)   return b[j];
            j++;
        }
        
        return -1;
    }

    int OptimalKthElement(vector<int> &a, vector<int> &b, int k) {
        if(a.size() > b.size())     return OptimalKthElement(b, a, k);
        
        int m = a.size();
        int n = b.size();
        
        int low = max(0, k-n);
        int high = min(m, k);
        
        while(low <= high) {
            int cut1 = (low + high) / 2;
            int cut2 = k - cut1;
            
            int l1 = cut1 == 0 ? INT_MIN : a[cut1 - 1];
            int l2 = cut2 == 0 ? INT_MIN : b[cut2 - 1];
            int r1 = cut1 == m ? INT_MAX : a[cut1];
            int r2 = cut2 == n ? INT_MAX : b[cut2]; 
            
            if(l1 <= r2 && l2 <= r1) {
                return max(l1, l2);
            }
            
            else if(l1 > r2)    high = cut1 - 1;
            else                low = cut1 + 1;
        }
        
        return -1;
    }
};

int main() {
    Solution obj;

    vector<int> arr1 = {2, 3, 6, 7, 9};
    vector<int> arr2 = {1, 4, 8, 10};
    int k = 5;

    int ans1 = obj.BruteKthElement(arr1, arr2, k);
    cout << "BRUTE: The element at Kth position is: " << ans1 << endl;

    int ans2 = obj.BetterKthElement(arr1, arr2, k);
    cout << "BETTER: The element at Kth position is: " << ans2 << endl;

    int ans3 = obj.OptimalKthElement(arr1, arr2, k);
    cout << "OPTIMAL: The element at Kth position is: " << ans3 << endl;

    return 0;
}