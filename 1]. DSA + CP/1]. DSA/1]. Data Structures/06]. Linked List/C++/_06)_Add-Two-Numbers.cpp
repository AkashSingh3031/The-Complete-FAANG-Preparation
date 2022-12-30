ListNode* addTwoNumbers(ListNode* A, ListNode* B) {
        if(A==NULL) return B;
        if(B==NULL) return A;
        
        int carry = 0;
        ListNode *head = NULL;
        
        while(A!=NULL && B!=NULL){
            int sum = A->val + B->val + carry;
            ListNode *newAdditionList = new ListNode(sum%10);
            newAdditionList->next = head;
            head = newAdditionList;
            carry = sum/10;
            
            A = A->next;
            B = B->next;
        }
        
        while(A!=NULL){
            int sum = A->val + carry;
            ListNode *newAdditionList = new ListNode(sum%10);
            newAdditionList->next = head;
            head = newAdditionList;
            carry = sum/10;
            
            A = A->next;
        }
        
        while(B!=NULL){
            int sum = B->val + carry;
            ListNode *newAdditionList = new ListNode(sum%10);
            newAdditionList->next = head;
            head = newAdditionList;
            carry = sum/10;
            
            B = B->next;
        }
        
        if(carry > 0){
            ListNode *newAdditionList = new ListNode(carry);
            newAdditionList -> next = head;
            head = newAdditionList;
        }
        
        //reverse linked list sum
        ListNode *prev = NULL;
        ListNode *curr = head;
        
        while(curr!=NULL){
            ListNode *newAdditionList = curr -> next;
            curr -> next = prev;
            
            prev = curr;
            curr = newAdditionList;
        }
        
        head = prev;
        return head;
        
    }
