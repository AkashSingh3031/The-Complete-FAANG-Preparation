Node* rotate(Node* head, int k)
    {
        // Your code here
            Node* temp=head;
            int count=1;
           
            
            if(k==0)
            {
                return head;
            }
           
           
            while(count<k && temp!=NULL)
            {
                temp=temp->next;
                count++;
            }
            Node*res=temp;
             
           
            while(temp->next!=NULL)
            {
               temp=temp->next;
            }
            temp->next=head;
            head=res->next;
            res->next=NULL;
            return head;
    }