//<----------> Iterative Solution <------------------->

#include<vector>
class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        vector<int> ans;
        
        struct Node* curr;
        
        if(head == NULL) return{};
        for(curr = head; curr!=NULL; curr=curr->next){
            ans.push_back(curr->data);
        }
        
        for(curr = head; curr!=NULL; curr=curr->next){
            curr->data = ans.back();
            ans.pop_back();
        }
        return head;
        
    }
    
};
