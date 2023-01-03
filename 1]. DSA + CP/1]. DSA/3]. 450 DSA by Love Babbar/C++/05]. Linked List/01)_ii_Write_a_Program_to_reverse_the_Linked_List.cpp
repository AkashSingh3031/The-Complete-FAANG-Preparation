

//<----------> LeetCode Question Solution <------->

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        
        while(curr != NULL){
            ListNode* n = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = n;
        }
        return prev;
    }
};

