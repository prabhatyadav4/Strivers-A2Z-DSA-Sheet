# Modify contents of Linked List

Given a Singly linked list. The task is to modify the value of the first half of nodes such that 1st node's new value is equal to the value of the last node minus the first node's current value, 2nd node's new value is equal to the second last node's value minus 2nd nodes current value, likewise for first half nodes, then replace the second half of nodes with the initial values of the first half of nodes (values before modifying the nodes).

Note: If the size of it is odd then the value of the middle node remains unchanged.

Examples:

Input: head: 10 -> 4 -> 5 -> 3 -> 6

Output: -4 -> -1 -> 5 -> 4 -> 10

![Mofification](https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/715242/Web/Other/blobid0_1723399856.png)

Explanation: After modifying first half, list will be: -4 -> -1 -> 5 -> 3 -> 6

After modifying Second half also, list will be: -4 -> -1 -> 5 -> 4 -> 10

## Change Linked List to Array - O(n) Time and O(n) Space

The idea is to take out all elements from LinkedList add them into an array and apply the required operations:  

- For each node in the first half of the list, its value is changed by subtracting it from the corresponding value in the second half of the list (from the end towards the center). 

- After performing these modifications, the values in the first half of the array are swapped with the corresponding values in the second half on the array and then put back all elements into the LinkedList.