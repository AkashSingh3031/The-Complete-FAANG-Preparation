/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        
        ListNode* dumy=head;

        int count=1;
        while(dumy->next!=NULL){
            dumy=dumy->next;
            count++;
        }
        
        dumy->next=head;
        k=k%count;
        k=count-k;
        
        while(k--) 
            dumy=dumy->next;
        
        head=dumy->next;
        dumy->next=NULL;
        return head;
    }
};
