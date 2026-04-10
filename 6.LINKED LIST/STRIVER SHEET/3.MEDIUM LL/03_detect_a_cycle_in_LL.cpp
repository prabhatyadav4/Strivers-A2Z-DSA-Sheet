/*
Detect a Cycle in a Linked List

Problem Statement: Given a Linked List, determine whether the linked list contains a cycle or not.

Examples
Input: LL: 1 2 3 4 5

Output: True
Explanation: The last node with the value of 5 has its 'next' pointer pointing back to a previous node with the value of 3. 
This has resulted in a loop, hence we return true.
Input: LL: 1 2 3 4 9 9

Output: False
Explanation:  In this example, the linked list does not have a loop hence returns false.
*/

#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
    public:
        int data;
        Node *next;

        Node(int x) {
            this->data = x;
            this->next = nullptr;
        }
};

bool BruteDetectACycle(Node *head) {
    if(head == nullptr || head->next == nullptr) {
            return false;   
    }
    
    Node *temp = head;
    unordered_map<Node*, int> nodeMap;

    while(temp != nullptr) {
        if(nodeMap.find(temp) != nodeMap.end()) {
            return true;
        }

        nodeMap[temp] = 1;
        temp = temp->next;
    }

    return false;
}

bool OptimalDetectACycle(Node *head) {
    if(head == nullptr || head->next == nullptr) {
            return false;
    }

    Node *slow = head, *fast = head;

    while(fast != nullptr || fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {
            return true;
        }
    }

    return false;
}

int main() {
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = head->next->next;

    // if(BruteDetectACycle(head)) {
    //     cout << "BRUTE: Cycle detected in the linked list.";
    // }
    // else {
    //     cout << "BRUTE: Cycle not detected in the linked list.";
    // }

    if(OptimalDetectACycle(head)) {
        cout << "OPTIMAL: Cycle detected in the linked list.";
    }
    else {
        cout << "OPTIMAL: Cycle not detected in the linked list.";
    }

    return 0;
}