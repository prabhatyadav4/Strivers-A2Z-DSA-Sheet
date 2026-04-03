// Insertion at specific position in circular linked list

#include <iostream>
using namespace std;

class Node {
    public: 
        int data;
        Node *next;

        Node(int val) {
            this->data = val;
            this->next = nullptr;
        }
};

;Node *insertAtMiddle(Node *last, int pos, int val) {
    if(last == nullptr) {
        if(pos != 1) {
            cout << "Invalid Position" << endl;
            return last;
        }
        Node *newNode = new Node(val);
        last = newNode;
        last->next = last;

        return last;
    }

    Node *newNode = new Node(val);
    Node *curr = last->next;

    if(pos == 1) {
        newNode->next = curr;
        last->next = newNode;
        return last;
    }

    for(int i = 1; i < pos - 1; i++) {
        curr = curr->next;

        if(curr == last->next) {
            cout << "Invalid position" << endl;
            return last;
        }
    }

    newNode->next = curr->next;
    curr->next = newNode;

    if(curr == last) {
        last = newNode;
    }

    return last;
}

void printList(Node *last) {
    Node *head = last->next;
    Node *temp = head;

    do {
        cout << temp->data;
        if(temp->next != head) {
            cout << " -> ";
        }
        temp = temp->next;
    }
    while(temp != head);

    cout << endl;
}

int main() {
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(4);

    Node *last = head->next->next->next;
    last->next = head;

    int pos = 4;

    last = insertAtMiddle(last, pos, 3);

    printList(last);

    return 0;
}