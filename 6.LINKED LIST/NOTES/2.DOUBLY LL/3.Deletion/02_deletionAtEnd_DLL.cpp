// Deletion at end (Removal of last node) in a Doubly Linked List

#include <iostream>
using namespace std;

class Node {
    public: 
        int data;
        Node *next;
        Node *prev;

        Node(int val) {
            this->data = val;
            this->next = nullptr;
            this->prev = nullptr;
        }
};

Node *deletionAtEnd(Node *head) {
    if(head == nullptr) {
        return nullptr;
    }

    if(head->next == nullptr) {
        delete head;
        return nullptr;
    }

    Node *curr = head;

    while(curr->next != nullptr) {
        curr = curr->next;
    }

    curr->prev->next = nullptr;

    delete curr;

    return head;
}

void printList(Node *head) {
    while(head != nullptr) {
        cout << head->data;
        if(head->next != nullptr) {
            cout << " <-> ";
        }
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;

    cout << "Original Linked List: ";
    printList(head);

    cout << "After deletion at the end: ";
    head = deletionAtEnd(head);
    printList(head);

    return 0;
}