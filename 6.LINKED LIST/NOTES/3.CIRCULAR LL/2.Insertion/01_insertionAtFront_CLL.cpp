// Insertion at the beginning in circular linked list

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

Node *insertAtStart(Node *last, int val) {
    Node *newNode = new Node(val);

    if(last == nullptr) {
        newNode->next = newNode;
        return newNode;
    }

    newNode->next = last->next;
    last->next = newNode;

    return last;
}

void printList(Node *last) {
    if(last == nullptr) return;

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
    Node *first = new Node(2);
    first->next = new Node(3);
    first->next->next = new Node(4);
    
    Node *last = first->next->next;
    last->next = first;

    last = insertAtStart(last, 1);
    printList(last);

    return 0;
}