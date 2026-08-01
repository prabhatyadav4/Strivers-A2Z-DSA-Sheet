/*
155. Min Stack

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int value) pushes the element value onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.



Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2


Constraints:

-231 <= val <= 231 - 1
Methods pop, top and getMin operations will always be called on non-empty stacks.
At most 3 * 104 calls will be made to push, pop, top, and getMin.
*/

// Brute Approach

#include <iostream>
#include <stack>
using namespace std;

class Stack{

    private:
        stack<pair<int,int>> st;

    public:

        void push(int val) {

            if(st.empty()) {
                st.push({val, val});
                return;
            }

            int mini = min(val, st.top().second);
            st.push({val, mini});
        }

        void pop() {
            st.pop();
        }

        int top() {
            return st.top().first;
        }

        int getMin() {
            return st.top().second;
        }
};

int main() {
    Stack st;

    st.push(-2); // first element
    st.push(0);  // second element
    st.push(-3); // third element sets new minimum

    cout << st.getMin() << "\n"; // print current minimum
    st.pop();
    cout << st.top() << "\n";    // print current top
    cout << st.getMin() << "\n"; // print current minimum after pop

    return 0;
}

// Optimal Approach

#include <iostream>
#include <stack>
using namespace std;

class Stack
{
private:
    stack<long long int> st;
    long long int minVal;

public:
    void push(int val)
    {
        if (st.empty())
        {
            st.push(val);
            minVal = val;
        }
        else
        {
            if (val < minVal)
            {
                st.push((long long)2 * val - minVal);
                minVal = val;
            }
            else
            {
                st.push(val);
            }
        }
    }

    void pop()
    {
        if (st.top() < minVal)
        {
            minVal = 2 * minVal - st.top();
        }

        st.pop();
    }

    int top()
    {
        if (st.top() < minVal)
        {
            return minVal;
        }

        return st.top();
    }

    int getMin()
    {
        return minVal;
    }
};

int main()
{
    Stack st;

    st.push(-2);
    st.push(0);
    st.push(-3);
    cout << st.getMin() << " ";
    st.pop();
    cout << st.top() << " ";
    st.pop();
    cout << st.getMin();

    return 0;
}