/*
Intersection Of Two Sorted Arrays

Problem statement
You are given two arrays 'A' and 'B' of size 'N' and 'M' respectively. Both these arrays are sorted in non-decreasing order. 
You have to find the intersection of these two arrays.
Intersection of two arrays is an array that consists of all the common elements occurring in both arrays.

Note :
1. The length of each array is greater than zero.
2. Both the arrays are sorted in non-decreasing order.
3. The output should be in the order of elements that occur in the original arrays.
4. If there is no intersection present then return an empty array.

Constraints :
1 <= T <= 100
1 <= N, M <= 10^4
0 <= A[i] <= 10^5
0 <= B[i] <= 10^5

Time Limit: 1 sec
Sample Input 1 :
2
6 4
1 2 2 2 3 4
2 2 3 3
3 2
1 2 3
3 4  
Sample Output 1 :
2 2 3
3   
Explanation for Sample Input 1 :
For the first test case, the common elements are 2 2 3 in both the arrays, so we print it.

For the second test case, only 3 is common so we print 3.
*/

#include <iostream>
#include <vector>
using namespace std; 

vector<int> BrutefindArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	// Write your code here.
	vector<int> ans;
	vector<int> vis(m, 0);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(arr1[i] == arr2[j] && vis[j] == 0){
				ans.push_back(arr1[i]);
				vis[j] = 1;
				break;
			}
			if(arr2[j] > arr1[i]){
				break;
			}	
		}
	}
	return ans;
}

vector<int> OptimalfindArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	// Write your code here.
	int i = 0; 
	int j = 0;
	vector<int> ans;

	while(i < n && j < m){
		if(arr1[i] < arr2[j]) {
			i++;
		}
		else if(arr2[j] < arr1[i]) {
			j++;
		}
		else{
			ans.push_back(arr1[i]);
			i++;
			j++;
		}
	}
	
	return ans;
}

int main() {

    vector<int> a = {1,1,2,3,3,4,5,6};
    vector<int> b = {1,2,2,3,4,6,7};
    vector<int> c = {1,1,2,3,3,4,5,7};
    vector<int> d = {1,2,3,4,6,7,8};
    int n = 8;
    int m = 7;
    vector<int> IntersectionArray1 = BrutefindArrayIntersection(a, n, b, m);
    cout << "Intesection Array (Brute): ";
    for(auto x : IntersectionArray1){
        cout << x << " ";
    }

    vector<int> IntersectionArray2 = OptimalfindArrayIntersection(c, n, d, m);
    cout << "\nIntesection Array (Optimal): ";
    for(auto y : IntersectionArray2){
        cout << y << " ";
    }

    return 0;
}