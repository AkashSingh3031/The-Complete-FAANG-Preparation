 ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //Approach - 01
  /*    
       while(headA!=NULL){
            ListNode *head2 = headB;
            while(head2 != NULL){
                if(headA == head2){
                    return headA;
                }
                head2 = head2->next;
            }
            headA = headA->next;
        }
        return NULL;
        
    }   
    
 */
  
        
        
        //<----------->  Approach - 03  <----------------->
        
      ListNode * pA = headA;
      ListNode * pB = headB;
      while (pA != pB) {
        pA = pA == nullptr ? headB : pA -> next;
        pB = pB == nullptr ? headA : pB -> next;
      }
        return pA;
      }
       