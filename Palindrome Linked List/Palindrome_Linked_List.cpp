class Solution {
public:
    bool isPalindrome(ListNode* head) {
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
