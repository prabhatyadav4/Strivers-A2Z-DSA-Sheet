/*
Implement Queue using Arrays

Implement a First-In-First-Out (FIFO) queue using an array. The implemented queue should support the following operations: push, peek, pop, and isEmpty.

Implement the ArrayQueue class:

void push(int x): Adds element x to the end of the queue.

int pop(): Removes and returns the front element of the queue.

int peek(): Returns the front element of the queue without removing it.

boolean isEmpty(): Returns true if the queue is empty, false otherwise.

Example 1

Input:

["ArrayQueue", "push", "push", "peek", "pop", "isEmpty"]

[[], [5], [10], [], [], []]

Output: [null, null, null, 5, 5, false]

Explanation:

ArrayQueue queue = new ArrayQueue();

queue.push(5);

queue.push(10);

queue.peek(); // returns 5

queue.pop(); // returns 5

queue.isEmpty(); // returns false

Example 2

Input:

["ArrayQueue", "isEmpty"]

[[]]

Output:[null, true]

Explanation:

ArrayQueue queue = new ArrayQueue();

queue.isEmpty(); // returns true
*/

#include <iostream>
using namespace std;

class myQueue
{
private:
    int *arr;
    int capacity;
    int size;

public:
    myQueue(int c)
    {
        capacity = c;
        arr = new int[capacity];
        size = 0;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == capacity;
    }

    // Adds an element x at the rear of the queue
    void enqueue(int x)
    {
        if (isFull())
        {
            cout << "Queue is full" << endl;
            return;
        }

        arr[size++] = x;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }

        for (int i = 1; i < size; i++)
        {
            arr[i - 1] = arr[i];
        }
        size--;
    }

    int getFront()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[0];
    }

    int getRear()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[size - 1];
    }
};

int main()
{
    myQueue q(3);

    // Insert element into the queue
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    // Get the front element
    cout << q.getFront() << endl;

    // Remove the front element
    q.dequeue();

    // Get the new front element
    cout << q.getFront() << endl;

    // Get the rear element
    cout << q.getRear() << endl;

    q.enqueue(40);

    // Check if the queue is empty()
    cout << (q.isEmpty() ? "Yes" : "No") << endl;

    // Check if the queue is full()
    cout << (q.isFull() ? "Yes" : "No") << endl;

    return 0;
}