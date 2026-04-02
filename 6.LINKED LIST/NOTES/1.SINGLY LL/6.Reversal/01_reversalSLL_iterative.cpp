// Reverse a Linked List

#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(int x) {
            this->data = x;
            this->next = nullptr;
        }
};

Node* reverseList(Node* head) {
    Node* curr = head, *prev = nullptr, *next;

    while(curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

void printList(Node* head) {
    while(head != nullptr) {
        cout << head->data;
        if(head->next != nullptr) {
            cout << " -> ";
        }
        head = head->next;
    }

    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    head = reverseList(head);

    printList(head);

    return 0;
}