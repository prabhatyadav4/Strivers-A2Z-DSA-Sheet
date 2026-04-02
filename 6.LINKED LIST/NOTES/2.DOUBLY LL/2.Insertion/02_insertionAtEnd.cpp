// Insert a Node at the end of Doubly Linked List

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

Node *insetionAtEnd(Node *head, int val) {
    Node *new_node = new Node(val);

    if(head == nullptr) {
        head = new_node;
    }
    else {
        Node *curr = head;

        while(curr->next != nullptr) {
            curr = curr->next;
        }

        curr->next = new_node;
        new_node->prev = curr;
    }

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

    int val = 4;

    head = insetionAtEnd(head, val);

    printList(head);

    return 0;
}