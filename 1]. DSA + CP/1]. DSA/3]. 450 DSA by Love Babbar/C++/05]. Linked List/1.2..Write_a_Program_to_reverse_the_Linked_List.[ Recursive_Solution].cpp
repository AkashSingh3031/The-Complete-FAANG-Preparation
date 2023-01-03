
//<------------> Recursive Solution <----------->

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

//<----------> GFG Question Solution <------->


class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        Node* curr = head;
        Node* prev = NULL;
        Node* move = NULL;
        
        while(curr!=NULL){
            
            move = curr -> next;
            curr->next = prev;
            prev = curr;
            curr = move;
            
        }
        return prev;
    }
    
};
    
