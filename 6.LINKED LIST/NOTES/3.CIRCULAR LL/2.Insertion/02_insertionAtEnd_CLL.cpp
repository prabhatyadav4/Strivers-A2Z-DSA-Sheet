// Insertion at the end in circular linked list

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

Node *insertAtEnd(Node *last, int val) {
    Node *newNode = new Node(val);

    if(last == nullptr) {
        last = newNode;
        newNode->next = newNode;
    }
    else{
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }

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
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = head;

    Node *last = head->next->next;
    last = insertAtEnd(last, 4);
    
    printList(last);

    return 0;
}