 int detectLoop(Node* head)
    {
        // code here
        
        Node*p=head;
        Node*q=head;
        
        while(p&& q && q->next)
        {
            
            p=p->next;
            q=q->next->next;
            Node*ptr1=head;
             if(p==q)
            {
                return 1;
            }
                  
        }
    }