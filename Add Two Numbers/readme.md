# LeetCode 2. Add Two Numbers

### Link: https://leetcode.com/problems/add-two-numbers/

### Difficulty: Medium

## Description

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input:

    (2 -> 4 -> 3) + (5 -> 6 -> 4)

Output:

    7 -> 0 -> 8

Explanation:

    342 + 465 = 807.

## Code and Explanation

```cpp
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // head and tail pointers to add new node and keep the address of head
        // we need a dummy node as head, and point tail to head
        ListNode * head = new ListNode(0);
        ListNode * tail = head;
        // carry initialized to 0, we need it to keep track of carry
        int carry = 0;
        while(l1 != NULL || l2 != NULL)
        {
            int x = (l1!=NULL)? l1->val:0;
            int y = (l2!=NULL)? l2->val:0;
            int sum = x + y + carry;
            tail->next = new ListNode(sum%10);
            carry = (sum)/10;
            tail = tail->next;
            if (l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
        }
        // if carry is not zero, then add it to the last node.
        if (carry > 0)
            tail->next = new ListNode(carry);
        // remove the dummy node at head, and return the address of head->next
        return head->next;        
    }
};
```

### Time Complexity

O(N)

There is just a loop over the longest linked list

### Space Complexity

O(1)

There is no additional memory required. The output is not considered.

### Useful Links

[![](http://img.youtube.com/vi/qOyO7MCd1G8/0.jpg)](http://www.youtube.com/watch?v=qOyO7MCd1G8 "")

[![](http://img.youtube.com/vi/WdOORzQFfqQ/0.jpg)](http://www.youtube.com/watch?v=WdOORzQFfqQ "")
