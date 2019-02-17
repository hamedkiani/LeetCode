# LeetCode 234. Palindrome Linked List

### Link: https://leetcode.com/problems/palindrome-linked-list/

### Difficulty: Easy

## Description

Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2

Output: false

Example 2:

Input: 1->2->2->1

Output: true

Follow up:

Could you do it in O(n) time and O(1) space?

## Code and Explanation

```cpp
class Solution {
public:
    bool isPalindrome(ListNode* head) {
      // this can be solved using reverse the linkedlist and then \
       compare two linked list, this takes O(N) of time and space \
        Complexity

      // here we use another way, using a vector and then check if \
       the vector is polindrome, O(N) time and space complexity

        if ( head == NULL)
            return true;
        vector<int> vecList;
        ListNode* temp = head;
        while(temp != NULL){
            vecList.push_back(temp->val);
            temp = temp->next;
        }
        // checking if the array is polindrome?
        int low = 0;
        int high = vecList.size() - 1;
        while(low < high){
            if (vecList[low++] != vecList[high--])
                return false;
        }
        return true;
    }
};
```

### Time Complexity
O(N)

### Space Complexity
O(N)

### Useful Links
N/A
