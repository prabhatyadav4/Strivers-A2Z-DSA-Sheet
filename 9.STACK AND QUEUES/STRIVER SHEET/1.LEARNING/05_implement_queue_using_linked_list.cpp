/*
Implement queue using Linkedlist

Implement a First-In-First-Out (FIFO) queue using a singly linked list. The implemented queue should support the following operations: push, pop, peek, and isEmpty.

Implement the LinkedListQueue class:

void push(int x): Adds element x to the end of the queue.

int pop(): Removes and returns the front element of the queue.

int peek(): Returns the front element of the queue without removing it.

boolean isEmpty(): Returns true if the queue is empty, false otherwise.


Example 1

Input:

["LinkedListQueue", "push", "push", "peek", "pop", "isEmpty"]

[[], [3], [7], [], [], []]

Output:[null, null, null, 3, 3, false]

Explanation:

LinkedListQueue queue = new LinkedListQueue();

queue.push(3);

queue.push(7);

queue.peek(); // returns 3

queue.pop(); // returns 3

queue.isEmpty(); // returns false

Example 2

Input:

["LinkedListQueue", "push", "pop", "isEmpty"]

[[], [2], [], []]

Output: [null, null, 2, true]

Explanation:

LinkedListQueue queue = new LinkedListQueue();

queue.push(2);

queue.pop(); // returns 2

queue.isEmpty(); // returns true
*/

#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *next;

    Node(int data)
    {
        this->val = data;
        this->next = nullptr;
    }
};

class LinkedListQueue
{
private:
    Node *start;
    Node *end;
    int size;

public:
    LinkedListQueue()
    {
        start = nullptr;
        end = nullptr;
        size = 0;
    }

    void push(int x)
    {
        Node *newNode = new Node(x);

        if (start == nullptr)
        {
            start = newNode;
            end = newNode;
        }
        else
        {
            end->next = newNode;
            end = newNode;
        }
        size++;
    }

    int pop()
    {
        if (start == nullptr)
        {
            return -1;
        }

        Node *temp = start;
        int value = start->val;

        start = start->next;
        delete temp;
        size--;

        if (start == nullptr)
        {
            end = nullptr;
        }

        return value;
    }

    int peek()
    {
        if (start == nullptr)
        {
            return -1;
        }

        return start->val;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    int getSize()
    {
        return size;
    }

    void display()
    {
        Node *temp = start;

        while (temp != nullptr)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    LinkedListQueue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Queue: ";
    q.display();

    cout << "Front element: " << q.peek() << endl;

    cout << "Removed element: " << q.pop() << endl;

    cout << "Queue after pop: ";
    q.display();

    cout << "Queue size: " << q.getSize() << endl;

    if (q.isEmpty())
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Queue is not empty" << endl;
    }

    return 0;
}