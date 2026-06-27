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

