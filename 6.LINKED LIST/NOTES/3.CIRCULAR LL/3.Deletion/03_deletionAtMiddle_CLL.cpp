// Deletion at specific position in circular linked list - O(n) Time and O(1) Space

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

Node *deleteAtMiddle(Node *last, int key) {
    if(last == nullptr) {
        return nullptr;
    }

    Node *curr = last->next;
    Node *prev = last;

    if(curr == last && curr->data == key) {
        delete curr;
        last = nullptr;

        return last;
    }

    if(curr->data == key) {
        last->next = curr->next;
        delete curr;

        return last;
    }

    while(curr != last && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    if(curr->data == key) { 

        prev->next = curr->next;

        if(curr == last) {
            last = prev;
        }
        
        delete curr;
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
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    Node *last = head->next->next->next->next;
    last->next = head;

    last = deleteAtMiddle(last, 3);

    printList(last);

    return 0;
}