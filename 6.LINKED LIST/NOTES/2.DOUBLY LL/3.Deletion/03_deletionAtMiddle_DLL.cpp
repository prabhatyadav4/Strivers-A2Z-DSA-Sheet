// Delete a Doubly Linked List node at a given position

#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next;
        Node *prev;

        Node (int val) {
            this->data = val;
            this->next = nullptr;
            this->prev = nullptr;
        }
};

Node *deleteAtMiddle(Node *head, int pos) {
    if(head == nullptr) {
        return head;
    }

    Node *curr = head;

    for(int i = 1; i < pos && curr != nullptr; i++) {
        curr = curr->next;
    }

    if(curr == nullptr) {
        return head;
    }

    if(curr->prev != nullptr) {
        curr->prev->next = curr->next;
    }

    if(curr->next != nullptr) {
        curr->next->prev = curr->prev;
    }

    if(curr == head) {
        head = curr->next;
    }

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
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;

    cout << "Original Linked List: ";
    printList(head);

    int pos = 3;
    cout << "After deletion at position: ";
    head = deleteAtMiddle(head, pos);
    printList(head);

    return 0;
}