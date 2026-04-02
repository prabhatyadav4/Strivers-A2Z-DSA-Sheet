// Deletion at beginning (Removal of first node) in a Doubly Linked List

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

Node *deletionAtFront(Node *head) {
    if(head == nullptr) {
        return nullptr;
    }

    Node *temp = head;

    head = head->next;

    if(head != nullptr) {
        head->prev = nullptr;
    }

    delete temp;
    
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

    cout << "After Deletion at the beginning: ";
    head = deletionAtFront(head);
    printList(head);

    return 0;
}