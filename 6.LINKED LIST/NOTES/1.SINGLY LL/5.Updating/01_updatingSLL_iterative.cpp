// Modify contents of Linked List

#include <iostream>
#include <vector>
using namespace std;

class Node {
    public:

        int data;
        Node* next;

        Node(int x) {
            this->data = x;
            this->next = nullptr;
        }
};

int countNodes(Node* head) {
    int count = 0;
    Node* curr = head;

    while(curr != nullptr) {
        count++;
        curr = curr->next;
    }

    return count;
}

void linkedListToVector(Node* head, vector<int>& vec) {
    Node* curr = head;

    for(int i = 0; i < vec.size(); i++) {
        vec[i] = curr->data;
        curr = curr->next;
    }
}

void vectorToLinkedList(const vector<int> & vec, Node* head) {
    Node* curr = head;

    for(int i = 0; i < vec.size(); i++) {
        curr->data = vec[i];
        curr = curr->next;
    }
}

void modifyVector(vector<int>& vec) {
    for(int i = 0; i < vec.size() / 2; i++) {
        int x = vec[i];
        vec[i] = vec[vec.size() - i - 1] - x;
        vec[vec.size() - i - 1] = x;
    }
}

Node* modifyTheList(Node* head) {
    if(!head->next) return nullptr;

    int n = countNodes(head);

    vector<int> vec(n);

    linkedListToVector(head, vec);

    modifyVector(vec);

    vectorToLinkedList(vec, head);

    return head;
}

void printList(Node* head) {
    Node* curr = head;
    while(curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(10);
    head -> next = new Node(4);
    head -> next -> next = new Node(5);
    head -> next -> next -> next = new Node(3);
    head -> next -> next -> next -> next = new Node(6);

    head = modifyTheList(head);

    printList(head);

    return 0;
}