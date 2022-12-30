class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL) 
             return NULL;
        else if(head->next == NULL)
             return head;
        else{
            vector<int> v;
            ListNode *result = head;
            while(result != NULL){
                v.push_back(result->val);
                result = result->next;
            } 
            sort(v.begin(),v.end());
            result = head;
            for(int i=0;i<v.size();i++){
                result->val = v.at(i);
                result = result->next;
            } 
            return head;            
        }
    }
};
