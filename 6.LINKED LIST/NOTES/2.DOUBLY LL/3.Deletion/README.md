# Deletion in Doubly Linked List

## Deletion at beginning (Removal of first node) in a Doubly Linked List

Given a doubly linked list, the task is to delete the node from the beginning of the linked list.

**Examples:**

Input : 1 <-> 2 <-> 3 -> NULL

Output : 2 <-> 3 <-> NULL

Input : 2 <-> 4 <-> 6 <-> 8 <-> 33 <-> 67 <-> NULL

Output : 4 <-> 6 <-> 8 <-> 33 <-> 67 <-> NULL

**Approach:**

The idea is to update the head of the doubly linked list to the node next to head node and if the new head is not NULL, then set the previous pointer of new head to NULL. 

![Deletion1](https://media.geeksforgeeks.org/wp-content/uploads/20240809124112/Deletion-at-the-Beginning-of-Doubly-Linked-List.webp)

To delete a node at the beginning in doubly linked list, we can use the following steps:

- Check if the list is empty, there is nothing to delete, return.
- Store the head pointer in a variable, say temp.
- Update the head of linked list to the node next to the current head, head = head->next.
- If the new head is not NULL, update the previous pointer of new head to NULL, head->prev = NULL.

**Time Complexity**: O(1)

**Auxiliary Space**: O(1)

## Deletion at end (Removal of last node) in a Doubly Linked List

Given a doubly linked list, the task is to delete the last node of the given linked list.

**Examples:**

Input: 1 <-> 2 <-> 3 <-> NULL

Output: 1 <-> 2 <-> NULL

Explanation: The last node of the linked list is 3, so 3 is deleted.

Input: 15 -> NULL

Output: NULL

Explanation: The last node of the linked list is 15, so 15 is deleted.

**Approach:**

To perform the deletion operation at the end of doubly linked list, we need to traverse the list to find the second last node, then set its next pointer to null. 

![Deletion2](https://media.geeksforgeeks.org/wp-content/uploads/20240809124140/Deletion-at-the-End-in-Doubly-Linked-List.webp)

To delete a node at the end in doubly linked list, we can use the following steps:

- Check if the doubly linked list is empty. If it is empty, then there is nothing to delete.
- If the list is not empty, then move to the last node of the doubly linked list, say curr.
- Update the second-to-last node’s next pointer to NULL, curr->prev->next = NULL.
- Free the memory allocated for the node that was deleted.

**Time Complexity**: O(N), where N is the number of nodes in the linked list

**Auxiliary Space**: O(1)

## Delete a Doubly Linked List node at a given position

Given the head of a doubly linked list and an integer x, delete the node at the x-th position (1-based index) from the beginning of the list.

- If x = 1, delete the head node and update the head pointer.
- If x is greater than the length of the list, no deletion should be performed.

Ensure that the list remains valid after deletion, i.e., the prev and next pointers of the remaining nodes are correctly updated.

Input: x = 2

![Deletion3](https://media.geeksforgeeks.org/wp-content/uploads/20250901121130854282/Screenshot-2025-09-01-121047.png)

Output: 1 <-> 3

Explanation: The node at position 2 is 2. After deleting it, the remaining list is 1 <-> 3.

![Deletion3](https://media.geeksforgeeks.org/wp-content/uploads/20250901121215044941/Screenshot-2025-09-01-121200.png)

**Approach:** Traversal and Pointer Adjustment

The idea is simple: find the node at the given position and remove it by updating the links of the nodes before and after it, so the list stays connected. If the node to delete is the head, we just move the head to the next node.

### Step by Step Approach:

- If the list is empty, there’s nothing to delete, so just return the head.
- Go through the list to find the x-th node. If x is larger than the number of nodes, just return the head as it is.
- If x is 1, we need to remove the head: move the head to the next node and make sure its previous link is null, then delete the old head.
- For any other node, link its previous node to its next node, and if there’s a next node, link it back to the previous node, then remove the current node.
- Return the head of the updated list.

### Handling Deletion of Head and Last Node
**Head Node:** If the node to remove is the first one, we must move the head pointer to the next node. At the same time, if a next node exists, we should make sure its backward link no longer points to the old head.

**Last Node:** If the node to remove is the last one, we cut the link from its previous node so that the previous node becomes the new end of the list. In this case, the forward link is set to null.

**Time Complexity**: O(n)

**Auxiliary Space**: O(1)