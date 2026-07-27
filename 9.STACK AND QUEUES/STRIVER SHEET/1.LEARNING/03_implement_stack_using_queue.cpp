/*
Implement Stack using Queue

Implement a Last-In-First-Out (LIFO) stack using a single queue. The implemented stack should support the following operations: push, pop, top, and isEmpty.

Implement the QueueStack class:

void push(int x): Pushes element x onto the stack.

int pop(): Removes and returns the top element of the stack.

int top(): Returns the top element of the stack without removing it.

boolean isEmpty(): Returns true if the stack is empty, false otherwise.

Example 1

Input:

["QueueStack", "push", "push", "pop", "top", "isEmpty"]

[[], [4], [8], [], [], []]

Output: [null, null, null, 8, 4, false]

Explanation:

QueueStack stack = new QueueStack();

stack.push(4);

stack.push(8);

stack.pop(); // returns 8

stack.top(); // returns 4

stack.isEmpty(); // returns false

Example 2

Input:

["QueueStack", "isEmpty"]

[[]]

Output:[null, true]

Explanation:

 QueueStack stack = new QueueStack();

stack.isEmpty(); // returns true
*/

#include <iostream>
#include <queue>
using namespace std;

class QueueStack
{
private:
    queue<int> q;

public:
    void push(int x)
    {
        int s = q.size();
        q.push(x);

        for (int i = 0; i < s; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow" << endl;
            return -1;
        }

        int topElement = q.front();
        q.pop();

        return topElement;
    }

    int top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return q.front();
    }

    bool isEmpty()
    {
        return q.empty();
    }

    int size()
    {
        return q.size();
    }
};

int main()
{
    QueueStack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top element: " << stack.top() << endl;
    cout << "Stack size: " << stack.size() << endl;

    cout << "Popped element: " << stack.pop() << endl;
    cout << "Popped element: " << stack.pop() << endl;

    cout << "Top element: " << stack.top() << endl;

    cout << "Popped element: " << stack.pop() << endl;

    if (stack.isEmpty())
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack is not empty" << endl;
    }

    return 0;
}