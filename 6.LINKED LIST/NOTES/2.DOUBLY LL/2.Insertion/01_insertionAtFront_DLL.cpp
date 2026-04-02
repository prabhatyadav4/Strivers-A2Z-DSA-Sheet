// Insert a Node at Front/Beginning of Doubly Linked List

#include <iostream>
using namespace std;

class Node {
    public:

        int data;
        Node *next;
        Node *prev;

        Node(int value) {
            this->data = value;
            this->next = nullptr;
            this->next = nullptr;
        }
};

Node *insertionAtFront(Node *head, int val) {
    Node *new_node = new Node(val);

    new_node->next = head;

    if(head != nullptr) {
        head->prev = new_node;
    }

    return new_node;
}

void printList(Node *head) {
    Node *curr = head;

    while(curr != nullptr) {
        cout << curr->data;
        if(curr->next != nullptr) {
            cout << " <-> ";
        }
        curr = curr->next;
    }

    cout << endl;
}

int main() {
    Node *head = new Node(2);
    head->next = new Node(3);
    head->next->prev = head;
    head->next->next = new Node(4);
    head->next->next->prev = head->next;

    int val = 1;
    
    head = insertionAtFront(head, val);

    printList(head);

    return 0;
}