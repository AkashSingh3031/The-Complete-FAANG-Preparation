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

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
     
      ListNode * pA = headA;
      ListNode * pB = headB;
  
      while (pA != pB) {
       
        pA = pA == nullptr ? headB : pA -> next;
        pB = pB == nullptr ? headA : pB -> next;
       
      }
  
      return pA;
  
}

