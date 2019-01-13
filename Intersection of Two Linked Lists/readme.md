# LeetCode 160. Intersection of Two Linked Lists

### Link: https://leetcode.com/problems/intersection-of-two-linked-lists/

### Difficulty: Easy

## Description

Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:

    List 1: a1->a2->c1->c2->c3

    List 2: b1->b2->b3->c1->c2->c3

begin to intersect at node c1.

**Notes:**

1. If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
2. You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.

## Code and Explanation

```cpp
class Solution {
public:
    ListNode * getIntersectionNode(ListNode * headA, ListNode * headB)
    {
        if (!headA || !headB)
            return NULL;
// we can solve this problem using a hastable to keep the address of visited nodes of one linkedlist, and go over the second linkedlist to see if any of its node was preferably seen in the hastable. This needs O(N) space and O(N) time.

// second approach is getting the length of both linedlist, find the difference and then move the longer one with length(l1) - length(l2). Starting from the begining of the shorter list and moving both lists forward till both pointers point to the same node or  both go to Null. This gives us the intersection of two linked lists.

        int lA = 0;
        int lB = 0;
        ListNode * temp = headA;
        // length of the first linkedlist
        while(temp){
            lA ++; temp = temp->next;
        }

        temp = headB;
        // length of the 2nd linkedlist
        while(temp){
            lB ++; temp = temp->next;
        }

        ListNode * temp2 = NULL;
        // finding the longer and shotter list
        if ( lA >lB){
            temp = headA;temp2 = headB;}
        else{
            temp = headB;temp2 = headA;
        }
        // moving the longer as the length difference of two linedlists
        for(int i = 0; i <abs(lA-lB); i++)
            temp = temp->next;
            // move forward both pointers till the point to the same node/NULL
        while(temp!= temp2)
        {
            temp = temp->next;
            temp2 = temp2->next;
        }
        return temp;
    }
};
```

### Time Complexity

O(N): finding the length of the lists and moving them forward

### Space Complexity

O(1): no additional space is used here.

### Useful Links

[![](http://img.youtube.com/vi/_7byKXAhxyM/0.jpg)](http://www.youtube.com/watch?v=_7byKXAhxyM "")
