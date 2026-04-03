# Insertion at the beginning in circular linked list

Given a Circular Linked List and an integer key representing a node. Insert the given key node at the beginning of the circular linked list.

Input: key = 5

![Insertion1](https://media.geeksforgeeks.org/wp-content/uploads/20250830123325699998/blobid0_1756106050.webp)

Output: 5 -> 1 -> 7 -> 8 -> 10

Explanation: After inserting 5 at the beginning of the given circular linked list, it has elements as 5, 1, 7, 8, 10.

![Insertion2](https://media.geeksforgeeks.org/wp-content/uploads/20250830123325596855/blobid2_1756115062.webp)

## Insertion at the beginning in circular linked list

To insert a new node at the beginning of a circular linked list, we first create the new node and allocate memory for it. If the list is empty (indicated by the last pointer being NULL), we make the new node point to itself. If the list already contains nodes then we set the new node’s next pointer to point to the current head of the list (which is last->next), and then update the last node’s next pointer to point to the new node. This maintains the circular structure of the list.

## Step-by-step approach:

- Create a new node with the given value.
- Check Empty List (last == nullptr):
    - Make newNode->next point to itself.
- Insert at Beginning:
    - Set newNode->next to last->next.
    - Update last->next to newNode.

**Time Complexity:** O(1)

**Auxiliary Space:** O(1)

# Insertion at the end in circular linked list

A circular linked list is a data structure where each node points to the next, and the last node connects back to the first, creating a loop. Insertion at the end in circular linked list is an important operation. Understanding how to perform this insertion is essential for effectively manage and use circular linked lists in various applications.

## Insertion at the end in circular linked list

To insert a new node at the end of a circular linked list, we first create the new node and allocate memory for it. If the list is empty (mean, last or tail pointer being NULL), we initialize the list with the new node and making it point to itself to form a circular structure. If the list already contains nodes then we set the new node’s next pointer to point to the current head (which is tail->next), then update the current tail's next pointer to point to the new node. Finally, we update the tail pointer to the new node. This will ensure that the new node is now the last node in the list while maintaining the circular linkage.

## Step-by-step approach:

- Create a new node with the given value.
- Check Empty List, If last is nullptr then initialize the list with the new node and make it point to itself.
- Otherwise, Set the new node's next to the head node.
- Update the current last's next to point to the new node.
- Update last to the new node.

**Time Complexity:** O(1)

**Auxiliary Space:** O(1)

# Insertion at specific position in circular linked list

Inserting an element at a specific position in a circular linked list is a common operation that involves adjusting pointers in a circular structure. Unlike a regular linked list, where the last node points to NULL, a circular linked list’s last node points back to the head, forming a loop. This property makes insertion at various positions, including the beginning, middle, and end, slightly different compared to a linear linked list.

**Examples:**

Input: data = 5, pos = 2

Output: Original list: 2 3 4 

               List after insertions: 2 5 3 4

Explanation: The new node with data 5 is inserted at position 2. The list becomes 2 -> 5 -> 3 -> 4.

Input: data = 1, pos = 1

Output: Original list: 2 3 4 

               List after insertions: 1 2 3 4

Explanation: The new node with data 1 is inserted at the beginning (position 1). The list becomes 1 -> 2 -> 3 -> 4.

## Steps for Insertion at a Specific Position in a Circular Linked List

- Check if the list is empty
    - If the position is not 1, print an error message (since the position doesn’t exist in an empty list).
    - If the position is 1, create the new node and make its next pointer point to itself (since it is the only node).

- If the list is not empty: Create the new node with the given data.

- For insertion at position 1 (insert at the beginning):
    - Traverse the list to find the last node (the node whose next pointer points to the head).
    - Set the new node’s next pointer to the current head.
    - Set the next pointer of the last node to the new node.
    - Update the head to point to the new node.

- For insertion at positions other than 1
    - Traverse the list to reach the node just before the desired position (position - 1).
    - Once you reach that node, set the new node’s next pointer to point to the node that was previously at the desired position.
    - Set the (position-1)-th node’s next pointer to the new node.

- If the new node is inserted at the end
    - Update the last node’s next pointer to point to the new node, maintaining the circular nature of the list.
    - Ensure the new node’s next pointer points to the head, completing the circle.
    - This process ensures that the circular structure of the linked list is preserved after every insertion.

**Time Complexity:** O(n), we have to traverse the list to find the specific position.

**Auxiliary Space:** O(1)