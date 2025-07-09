#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

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
