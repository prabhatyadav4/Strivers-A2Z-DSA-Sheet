// Deletion at the end of Circular linked list - O(n) Time and O(1) Space

#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next;

        Node(int x) {
            this->data = x;
            this->next = nullptr;
        }
};

Node *deleteAtEnd(Node *last) {
    if(last == nullptr) {
        return nullptr;
    }

    Node *head = last->next;

    if(head == last) {
        delete last;
        last = nullptr;
        return last;
    }

    Node *curr = head;

    while(curr->next != last) {
        curr = curr->next;
    }

    curr->next = head;
    delete last;
    last = curr;
    
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
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    Node *last = head->next->next->next;
    last->next = head;

    last = deleteAtEnd(last);

    printList(last);

    return 0;
}