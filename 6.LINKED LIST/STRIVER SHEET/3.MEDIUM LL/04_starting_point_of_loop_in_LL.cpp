/*
Starting point of loop in a Linked List

Problem Statement: Given the head of a linked list that may contain a cycle, return the starting point of that cycle. 
If there is no cycle in the linked list return null.

Examples
Input: LL: 1  2  3  4  5
Output: 3
Explanation: This linked list contains a loop of size 3 starting at node with value 3.


Input: LL: 1 -> 2 -> 3 -> 4 -> 9 -> 9
Output:NULL
Explanation: This linked list does not contain a loop hence has no starting point
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

Node *BruteDetectCycle(Node *head) {
    if(head == nullptr || head->next == nullptr) {
        return nullptr;
    }

    Node *temp = head;
    unordered_map<Node*, int> nodeMap;

    while(temp != nullptr) {
        if(nodeMap.find(temp) != nodeMap.end()) {
            return temp;
        }

        nodeMap[temp] = 1;
        temp = temp->next;
    }

    return nullptr;
}

Node *OptimalDetectCycle(Node *head) {
    if(head == nullptr || head->next == nullptr) {
        return nullptr;
    }

    Node *slow = head, *fast = head;
    
    while(fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {
            slow = head;
            
            while(slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }

            return slow;
        }
    }

    return nullptr;
}

int main() {
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = head->next->next->next;

    // Node *result1 = BruteDetectCycle(head);
    // if(result1 != nullptr) {
    //     cout << "BRUTE: Cycle starts at node with value: " << result1->data << endl;
    // }
    // else {
    //     cout << "BRUTE: No cycle found." << endl;
    // }

    Node *result2 = OptimalDetectCycle(head);
    if(result2 != nullptr) {
        cout << "OPTIMAL: Cycle starts at node with value: " << result2->data << endl;
    }
    else {
        cout << "OPTIMAL: No cycle found." << endl;
    }

    return 0;
}