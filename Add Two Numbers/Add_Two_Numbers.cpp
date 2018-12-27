class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * head = new ListNode(0);
        ListNode * tail = head;
        int carry = 0;
        while(l1 != NULL || l2 != NULL){
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
        if (carry > 0)
            tail->next = new ListNode(carry);
        return head->next;
    }
};
