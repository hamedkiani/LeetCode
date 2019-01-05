# LeetCode 237. Delete Node in a Linked List

### Link: https://leetcode.com/problems/delete-node-in-a-linked-list/

### Difficulty: Easy

## Description

Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

Given linked list -- head = [4,5,1,9],

which looks like following:

    4 -> 5 -> 1 -> 9


Example 1:

Input: head = [4,5,1,9], node = 5

Output: [4,1,9]

Explanation: You are given the second node with value 5, the linked list should become 4 -> 1 -> 9 after calling your function.

Example 2:

Input: head = [4,5,1,9], node = 1

Output: [4,5,9]

Explanation: You are given the third node with value 1, the linked list should become 4 -> 5 -> 9 after calling your function.

**Note:**

1. The linked list will have at least two elements.
2. All of the nodes' values will be unique.
3. The given node will not be the tail and it will always be a valid node of the linked list.

## Code and Explanation

```cpp
class Solution {
public:
    void deleteNode(ListNode* node)
    {
        // we assume the node is not tail, and the list is not empty
        // we save the value in the next node in current nodes
        // then we remove the target node by pointing the next pointer to the\
         next->next
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
```

### Time Complexity

O(1): no need to explain

### Space Complexity

O(1): no additional memory is needed

### Useful Links

N/A
