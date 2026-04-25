/*
21. Merge Two Sorted Lists

You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.

Example 1:
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:
Input: list1 = [], list2 = []
Output: []

Example 3:
Input: list1 = [], list2 = [0]
Output: [0]
 

Constraints:
The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Node class for linked list
class Node {
    public:
        int data;
        Node *next;
        Node(int x) {
            this->data = x;
            this->next = nullptr;
        }
};

// Brute force approach: collect all elements, sort, and create new list
Node *BruteSortTwoLists(Node *list1, Node *list2) {
    vector<int> res;
    Node *temp1 = list1;
    Node *temp2 = list2;

    // Collect all elements from list1
    while(temp1) {
        res.push_back(temp1->data);
        temp1 = temp1->next;
    }

    // Collect all elements from list2
    while(temp2) {
        res.push_back(temp2->data);
        temp2 = temp2->next;
    }

    // Sort all elements
    sort(res.begin(), res.end());

    // Create new merged list with sorted elements
    Node *dummy = new Node(-1);
    Node *temp = dummy;
    for(int i = 0; i < res.size(); i++) {
        temp->next = new Node(res[i]);
        temp = temp->next;
    }

    Node *newHead = dummy->next;
    delete dummy;
    return newHead;
}

// Optimal approach: use two pointers to merge while iterating
Node *OptimalSortTwoLists(Node *list1, Node *list2) {
    Node *temp1 = list1;
    Node *temp2 = list2;
    Node *dummy = new Node(-1);
    Node *res = dummy;

    // Compare nodes from both lists and attach smaller one
    while(temp1 && temp2) {
        if(temp1->data < temp2->data) {
            res->next = temp1;
            res = temp1;
            temp1 = temp1->next;
        }
        else {
            res->next = temp2;
            res = temp2;
            temp2 = temp2->next;
        }
    }

    // Attach remaining nodes
    if(temp1)   res->next = temp1;
    else        res->next = temp2;

    Node *newHead = dummy->next;
    delete dummy;
    return newHead;
}

// Utility function to print linked list
void printList(Node *head) {
    while(head) {
        cout << head->data;
        if(head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create list1 = 1 -> 2 -> 4
    Node *list1 = new Node(1);
    list1->next = new Node(2);
    list1->next->next = new Node(4);

    // Create list2 = 1 -> 3 -> 4
    Node *list2 = new Node(1);
    list2->next = new Node(3);
    list2->next->next = new Node(4);

    cout << "List1: ";
    printList(list1);

    cout << "List2: ";
    printList(list2);

    cout << "\nBrute Merge: ";
    Node *brute = BruteSortTwoLists(list1, list2);
    printList(brute);

    cout << "Optimal Merge: ";
    Node *optimal = OptimalSortTwoLists(list1, list2);
    printList(optimal);

    return 0;
}