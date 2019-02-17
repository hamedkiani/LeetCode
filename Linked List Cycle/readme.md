# LeetCode 141. Linked List Cycle

### Link: https://leetcode.com/problems/linked-list-cycle/

### Difficulty: Easy

## Description

Given a linked list, determine if it has a cycle in it.

To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.



Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where tail connects to the second node.


Example 2:

Input: head = [1,2],

pos = 0

Output: true

Explanation: There is a cycle in the linked list, where tail connects to the first node.


Example 3:

Input: head = [1],

pos = -1

Output: false

Explanation: There is no cycle in the linked list.

Follow up:

Can you solve it using O(1) (i.e. constant) memory?

## Code and Explanation

```cpp
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if ( head == NULL || head->next == NULL)
            return false;
// this is classic CS problem, known as Floyd's Cycle detection. We initialize \
 two pointer to the head of the linked list including fast and slow pointers.\
  We move forward slow by one step \
  and the fast pointer by two steps. If there is a loop, the fast and slow will \
   meet at a node, otherwise the fast pointer goes to NULL.
        ListNode * fast = head;
        ListNode * slow = head;
        while (fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow)
                return true;
        }
        return false;
    }
};
```

### Time Complexity
O(N)

### Space Complexity
O(1)

### Useful Links

[![](http://img.youtube.com/vi/zbozWoMgKW0/0.jpg)](http://www.youtube.com/watch?v=zbozWoMgKW0 "")
