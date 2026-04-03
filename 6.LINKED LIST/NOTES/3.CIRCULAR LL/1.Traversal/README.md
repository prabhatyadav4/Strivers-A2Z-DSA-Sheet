# Traversal of Circular Linked List

Given a circular linked list, print all the elements of this circular linked list.

**Example:**

Input: ![Traversal1](https://media.geeksforgeeks.org/wp-content/uploads/20240912131328/Traversal-of-Circular-Linked-List.webp)

Output: 1 2 3 4 5 6

## Approach 1: Using Iterative Method - O(n) Time and O(1) Space:

To idea is to traverse a circular linked list iteratively, starting at the head node and repeatedly printing the value of the current node while moving to its next node. Continue this process until we return back to the head node, indicating that the full cycle of the circular linked list has been completed.

## Approach 1: Using Recursion - O(n) Time and O(n) Space:

To idea is to traverse a circular linked list recursively, we will start by printing the value of the current node. Then, recursively call the function to handle the next node. If the next node is the same as the head node, indicating that a full cycle has been completed, we will end the recursion call. 