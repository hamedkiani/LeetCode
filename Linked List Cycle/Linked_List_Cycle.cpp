class Solution {
public:
    bool hasCycle(ListNode *head) {
        if ( head == NULL || head->next == NULL)
            return false;
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
