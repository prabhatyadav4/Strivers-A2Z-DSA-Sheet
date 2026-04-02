// Insert a Node at a specific position in Doubly Linked List

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

Node *insertionAtMiddle(Node *head, int val, int pos) {
    Node *new_node = new Node(val);

    if(pos == 1) {
        new_node->next = head;
        if(head != nullptr) {
            head->prev = new_node;
        }

        head = new_node;

        return head;
    }

    Node *curr = head;

    for(int i = 1; i < pos - 1 && curr != nullptr; i++) {
        curr = curr->next;
    }

    if(curr == nullptr) {
        delete new_node;
        return head;
    }

    new_node->prev = curr;
    new_node->next = curr->next;
    curr->next = new_node;

    if(new_node->next != nullptr) {
        new_node->next->prev = new_node;
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
    head->next->next = new Node(4);
    head->next->next->prev = head->next;

    int val = 3;
    int pos = 3;

    head = insertionAtMiddle(head, val, pos);

    printList(head);

    return 0;
}