/*
846. Hand of Straights

Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.

Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.

Example 1:
Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
Output: true
Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]

Example 2:
Input: hand = [1,2,3,4,5], groupSize = 4
Output: false
Explanation: Alice's hand can not be rearranged into groups of 4.

 

Constraints:
1 <= hand.length <= 104
0 <= hand[i] <= 109
1 <= groupSize <= hand.length

Note: This question is the same as 1296: https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/
*/

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
using namespace std;

bool isNStraightHandI(vector<int>& hand, int groupSize) {
    int n = hand.size();

    if(n % groupSize) {
        return false;
    }

    map<int, int> mp;

    for(int &handNumber : hand) {
        mp[handNumber]++;
    }

    while(!mp.empty()) {
        int curr = mp.begin()->first;

        for(int i = 0; i < groupSize; i++) {
            if(mp[curr + i] == 0) {
                return false;
            }

            mp[curr + i]--;

            if(mp[curr + i] < 1) {
                mp.erase(curr + i);
            }
        }
    }

    return true;
}

bool isNStraightHandII(vector<int>& hand, int groupSize) {
    int n = hand.size();

    if(n % groupSize != 0) {
        return false;
    }

    unordered_map<int, int> freq;

    for(int card : hand) {
        freq[card]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;

    for(auto &it : freq) {
        pq.push(it.first);
    }

    while(!pq.empty()) {
        int curr = pq.top();
        pq.pop();

        if(freq[curr] == 0) {
            continue;
        }

        int count = freq[curr];

        for(int i = 0; i < groupSize; i++) {
            int required = curr + i;

            if(freq[required] < count) {
                return false;
            }

            freq[required] -= count;
        }
    }

    return true;
}

int main() {
    vector<int> hand1 = {1, 2, 3, 6, 2, 3, 4, 7, 8};
    int groupSize1 = 3;

    vector<int> hand2 = {1, 2, 3, 4, 5};
    int groupSize2 = 4;

    cout << boolalpha;

    cout << "Example 1 (map approach): "
        << isNStraightHandI(hand1, groupSize1) << '\n';
    cout << "Example 1 (min-heap approach): "
        << isNStraightHandII(hand1, groupSize1) << '\n';

    cout << "Example 2 (map approach): "
        << isNStraightHandI(hand2, groupSize2) << '\n';
    cout << "Example 2 (min-heap approach): "
        << isNStraightHandII(hand2, groupSize2) << '\n';

    return 0;
}