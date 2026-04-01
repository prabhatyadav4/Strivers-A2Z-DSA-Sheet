# Search an element in a Linked List

Given a head of linked list and a key, determine whether the key exists by traversing through the nodes sequentially.

Examples:

Input: key = 5

![Search](https://media.geeksforgeeks.org/wp-content/uploads/20250823113103002217/link1.webp)

Output: true
Explanation: 5 is present in the linked list.

## Approach 1: Iterative Approach - O(n) Time and O(1) Space

The idea is to traverse all the nodes of the linked list, starting from the head. While traversing, if we find a node whose value is equal to key then print "Yes", otherwise print "No".

Step by Step Approach:

- Initialize a node pointer, curr = head.
- Do following while current is not NULL
=> If the current value (i.e., curr->key) is equal to the key being searched return true.
=> Otherwise, move to the next node (curr = curr->next).
- If the key is not found, return false 

## Approach 2: Recursive Approach - O(n) Time and O(n) Space

The idea is to recursively traverse all the nodes starting from the head of linked list. For any node, if the value is equal to key, then return true. Otherwise, recursively search the next node. If at any point the head reaches NULL, it means that we have reached the end of linked list so return false.

Step by Step Approach:

- If the head is NULL, return false.
- If the head's key is the same as X, return true;
- Else recursively search in the next node. 