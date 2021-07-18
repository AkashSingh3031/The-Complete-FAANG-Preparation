int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    Node*temp1=head1;
    Node*temp2=head2;
    int count1=0;
    int count2=0;
    int res;
    if(head1==NULL ||head2==NULL)
    {
        return 0;
    }
    while(temp1!=NULL)
    {
        temp1=temp1->next;
        count1++;
    }
    while(temp2!=NULL)
    {
        temp2=temp2->next;
        count2++;
    }
    temp1=head1;
    temp2=head2;
    if(count1>count2)
    {
       res=count1-count2;
        while(res)
        {
            temp1=temp1->next;
            res--;
        }
        while(temp1!=temp2)
        {
            temp1=temp1->next;
            temp2=temp2->next;
            
        }
       return temp1->data;
    }
    else
    {
      res=count2-count1;
        while(res)
        {
            temp2=temp2->next;
            res--;
        }
        while(temp1!=temp2)
        {
            temp2=temp2->next;
            temp1=temp1->next;
           
        }
        return temp2->data;
    }
    return 0;