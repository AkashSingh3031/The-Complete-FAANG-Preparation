#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int K)
{
    // Write your code here.
   LinkedListNode<int> *start=new LinkedListNode<int>(1);
   LinkedListNode<int> *fast=start;
   LinkedListNode<int> *slow=start;
   start->next=head;
   
    if(head==NULL || K==0)
       return head;

   for(int i=1;i<=K;i++)
       fast=fast->next;

   while(fast->next!=NULL) {
       fast=fast->next;
       slow=slow->next;
   }
   slow->next=slow->next->next;
   return start->next;
}