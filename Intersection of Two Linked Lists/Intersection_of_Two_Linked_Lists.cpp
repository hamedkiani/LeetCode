class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (!headA || !headB)
            return NULL;

        int lA = 0;
        int lB = 0;
        ListNode * temp = headA;
        while(temp){
            lA ++; temp = temp->next;
        }

        temp = headB;
        while(temp){
            lB ++; temp = temp->next;
        }

        ListNode * temp2 = NULL;
        if ( lA >lB){
            temp = headA;temp2 = headB;}
        else{
            temp = headB;temp2 = headA;
        }

        for(int i = 0; i <abs(lA-lB); i++)
            temp = temp->next;

        while(temp!= temp2)
        {
            temp = temp->next;
            temp2 = temp2->next;
        }
        return temp;
    }
};
