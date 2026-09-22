/*
1423. Maximum Points You Can Obtain from Cards

There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

Example 1:
Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.

Example 2:
Input: cardPoints = [2,2,2], k = 2
Output: 4
Explanation: Regardless of which two cards you take, your score will always be 4.

Example 3:
Input: cardPoints = [9,7,7,9,7,7,9], k = 7
Output: 55
Explanation: You have to take all the cards. Your score is the sum of points of all cards.


Constraints:
1 <= cardPoints.length <= 105
1 <= cardPoints[i] <= 104
1 <= k <= cardPoints.length
*/

#include <iostream>
#include <algorithm>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;

int BruteMaxScore(vector<int> &cardPoints, int k)
{
    int n = cardPoints.size();

    if (k < 0 || k > n)
    {
        return -1;
    }

    if (k == 0)
    {
        return 0;
    }

    if (k == n)
    {
        return accumulate(cardPoints.begin(), cardPoints.end(), 0);
    }

    int maxScore = INT_MIN;

    for (int leftCount = 0; leftCount <= k; leftCount++)
    {
        int rightCount = k - leftCount;
        int currentScore = 0;

        for (int i = 0; i < leftCount; i++)
        {
            currentScore += cardPoints[i];
        }

        for (int i = 0; i < rightCount; i++)
        {
            currentScore += cardPoints[n - i - 1];
        }

        maxScore = max(currentScore, maxScore);
    }

    return maxScore;
}

int BetterMaxScore(vector<int> &cardPoints, int k) {
    int n = cardPoints.size();

    if(k < 0 || k > n) {
        return -1;
    }

    if(k == 0) {
        return 0;
    }

    if(k == n) {
        return accumulate(cardPoints.begin(), cardPoints.end(), 0);
    }

    vector<int> leftSum(k + 1, 0);
    vector<int> rightSum(k + 1, 0);

    for(int i = 1; i <= k; i++) {
        leftSum[i] = leftSum[i - 1] + cardPoints[i - 1];
        rightSum[i] = rightSum[i - 1] + cardPoints[n - i];
    }

    int maxScore = INT_MIN;

    for(int leftCount = 0; leftCount <= k; leftCount++) {
        int rightCount = k - leftCount;

        int currentScore = leftSum[leftCount] + rightSum[rightCount];
        
        maxScore = max(maxScore, currentScore);
    }

    return maxScore;
}

int OptimalMaxScore(vector<int> &cardPoints, int k) {
    int n = cardPoints.size();

    if(k < 0 || k > n) {
        return -1;
    }

    if(k == 0) {
        return 0;
    }

    if(k == n) {
        return accumulate(cardPoints.begin(), cardPoints.end(), 0); 
    }

    int currentScore = 0;

    for(int i = 0; i < k; i++) {
        currentScore += cardPoints[i];
    }

    int maxScore = currentScore;
    int rightIndex = n - 1;

    for(int leftIndex = k - 1; leftIndex >= 0; leftIndex--) {
        currentScore -= cardPoints[leftIndex];
        currentScore += cardPoints[rightIndex];
        rightIndex--;

        maxScore = max(maxScore, currentScore);
    }


    return maxScore;
}

int main()
{
    vector<int> cardPoints = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;

    int ans1 = BruteMaxScore(cardPoints, k);
    cout << "BRUTE: The maximum points are: " << ans1 << endl;

    int ans2 = BetterMaxScore(cardPoints, k);
    cout << "BETTER: The maximum points are: " << ans2 << endl;

    int ans3 = OptimalMaxScore(cardPoints, k);
    cout << "OPTIMAL: The maximum points are: " << ans3 << endl;

    return 0;
}