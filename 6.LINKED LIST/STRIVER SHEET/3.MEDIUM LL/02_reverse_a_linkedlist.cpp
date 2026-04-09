/*
206. Reverse Linked List

Given the head of a singly linked list, reverse the list, and return the reversed list.

Example 1:
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Example 2:
Input: head = [1,2]
Output: [2,1]

Example 3:
Input: head = []
Output: []
 
Constraints:

The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000
 
*/

#include <iostream>
#include <stack>
using namespace std;

class Node {
    public: 
        int data;
        Node *next;

        Node (int x) {
            this->data = x;
            this->next = nullptr;
        }
};

Node *BruteReverseList(Node *head) {
    if(head == nullptr || head->next == nullptr) {
        return head;
    }

    stack<int> st;
    Node *temp = head;

    while(temp != nullptr) {
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;

    while(temp != nullptr) {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }

    return head;
}

Node *OptimalReverseList(Node *head) {
    if(head == nullptr || head->next == nullptr) {
        return head;
    }

    Node *curr = head, *prev = nullptr, *front = nullptr;

    while(curr != nullptr) {
        front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
    }

    return prev;
}

Node *RecursiveReverseList(Node *head) {
    if(head == nullptr || head->next == nullptr) {
        return head;
    }

    Node *newHead = RecursiveReverseList(head->next);

    Node* front = head->next;
    front->next = head;
    head->next = nullptr;

    return newHead;
}

void printList(Node *head) {
    Node *temp = head;
    
    while(temp != nullptr) {
        cout << temp->data;
        if(temp->next != nullptr) {
            cout << " -> ";
        }
        temp = temp->next;
    }

    cout << endl;
}

int main() {
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    head = BruteReverseList(head);
    cout << "BRUTE: The reversed list is: ";
    printList(head);

    head = OptimalReverseList(head);
    cout << "OPTIMAL: The reversed list is: ";
    printList(head);

    head = RecursiveReverseList(head);
    cout << "RECURSIVE: The reversed list is: ";
    printList(head);

    return 0;
}