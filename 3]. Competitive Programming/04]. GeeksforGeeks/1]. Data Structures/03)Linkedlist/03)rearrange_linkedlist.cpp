 void rearrangeEvenOdd(Node *head)
    {
       // Your Code here
       Node*slow=head;
       Node*fast=head->next;
       Node*temp=fast;
     while(1)
     {
         if(!slow || !fast ||!(fast->next))
         {
             slow->next=temp;
             break;
         }
         slow->next=fast->next;
         slow=fast->next;
         
         
         if(slow->next==NULL)
         {
             fast->next=NULL;
             slow->next=temp;
             break;
         }
         fast->next=slow->next;
         fast=slow->next;
     }
     
     }