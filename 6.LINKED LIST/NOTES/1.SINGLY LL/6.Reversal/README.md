# Reverse a Linked List

Given the head of a linked list, reverse the list and return the new head.

Examples: 

Input: ![Reverse1](https://media.geeksforgeeks.org/wp-content/uploads/20250818122256177473/2.webp)

Output: ![Reverse2](https://media.geeksforgeeks.org/wp-content/uploads/20250818122043965532/409842930.webp)

## Approach: Using Iterative Method - O(n) Time and O(1) Space

The idea is to reverse the linked list by changing the direction of links using three pointers: prev, curr, and next. At each step, point the current node to its previous node and then move all three pointers forward until the list is fully reversed.