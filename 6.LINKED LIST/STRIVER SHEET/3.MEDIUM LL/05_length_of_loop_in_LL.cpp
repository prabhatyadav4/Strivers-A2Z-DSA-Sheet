/*
Length of Loop in Linked List

Problem Statement: Given the head of a linked list, determine the length of a loop present in the linked list. 
If there's no loop present, return 0.

Examples
Input: 

Output: 3
Explanation: A cycle exists in the linked list starting at node 3 -> 4 -> 5 and then back to 3. There are 3 nodes present in this cycle.
Input: 

Output: 0
Explanation: The linked list is linear and does not have a loop hence return 0.
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

int BruteLengthOfLoop(Node *head) {
    if(head == nullptr || head->next == nullptr) {
        return 0;
    }

    int timer = 0;
    Node *temp = head;
    unordered_map<Node*, int> nodeMap;

    while(temp != nullptr) {
        if(nodeMap.find(temp) != nodeMap.end()) {
            int length = timer - nodeMap[temp];
            return length;
        }

        nodeMap[temp] = timer;
        timer++;
        temp = temp->next;
    }

    return 0;
}

int OptimalLengthOfLoop(Node *head) {
    if(head == nullptr || head->next == nullptr) {
        return 0;
    }

    Node *slow = head, *fast = head;

    while(fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {
            int count = 1;
            fast = fast->next;

            while(slow != fast) {
                count++;
                fast = fast->next;
            }

            return count;
        }
    }

    return 0;
}

int main() {
     Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = head->next->next;

    // int result1 = BruteLengthOfLoop(head);
    // if (result1 > 0) {
    //     cout << "BRUTE: Length of the loop: " << result1 << endl;
    // } else {
    //     cout << "BRUTE: No loop found in the linked list." << endl;
    // }

    int result2 = OptimalLengthOfLoop(head);
    if (result2 > 0) {
        cout << "OPTIMAL: Length of the loop: " << result2 << endl;
    } else {
        cout << "OPTIMAL: No loop found in the linked list." << endl;
    }

    return 0;
}