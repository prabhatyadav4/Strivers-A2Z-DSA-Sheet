/*
23. Merge k Sorted Lists

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

Example 1:
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted linked list:
1->1->2->3->4->4->5->6

Example 2:
Input: lists = []
Output: []

Example 3:
Input: lists = [[]]
Output: []


Constraints:
k == lists.length
0 <= k <= 104
0 <= lists[i].length <= 500
-104 <= lists[i][j] <= 104
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 104.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int val)
    {
        this->val = val;
        this->next = nullptr;
    }
};

ListNode *BruteMergeKLists(vector<ListNode *> &lists)
{
    vector<int> ans;

    for (auto head : lists)
    {
        while (head != nullptr)
        {
            ans.push_back(head->val);
            head = head->next;
        }
    }

    sort(ans.begin(), ans.end());

    ListNode *dummy = new ListNode(0);
    ListNode *tail = dummy;

    for (int x : ans)
    {
        tail->next = new ListNode(x);
        tail = tail->next;
    }

    return dummy->next;
}

class Compare
{
public:
    bool operator()(ListNode *first, ListNode *second)
    {
        return first->val > second->val;
    }
};

ListNode *OptimalMergeKLists(vector<ListNode *> &lists)
{
    priority_queue<ListNode *, vector<ListNode *>, Compare> pq;

    for (ListNode *head : lists)
    {
        if (head != nullptr)
        {
            pq.push(head);
        }
    }

    ListNode *dummy = new ListNode(0);
    ListNode *tail = dummy;

    while (!pq.empty())
    {
        ListNode *smallest = pq.top();
        pq.pop();

        tail->next = smallest;
        tail = tail->next;

        if (smallest->next != nullptr)
        {
            pq.push(smallest->next);
        }
    }

    tail->next = nullptr;

    return dummy->next;
}

int main()
{
    vector<vector<int>> values = {{1, 4, 5}, {1, 3, 4}, {2, 6}};

    auto buildLists = [&]()
    {
        vector<ListNode *> lists;
        for (const auto &valuesInList : values)
        {
            ListNode *head = nullptr;
            ListNode *tail = nullptr;

            for (int value : valuesInList)
            {
                ListNode *node = new ListNode(value);
                if (head == nullptr)
                {
                    head = node;
                }
                else
                {
                    tail->next = node;
                }
                tail = node;
            }
            lists.push_back(head);
        }
        return lists;
    };

    auto printList = [](ListNode *head)
    {
        while (head != nullptr)
        {
            cout << head->val;
            if (head->next != nullptr)
                cout << " -> ";
            head = head->next;
        }
        cout << '\n';
    };

    vector<ListNode *> bruteLists = buildLists();
    cout << "Brute: ";
    printList(BruteMergeKLists(bruteLists));

    vector<ListNode *> optimalLists = buildLists();
    cout << "Optimal: ";
    printList(OptimalMergeKLists(optimalLists));
}