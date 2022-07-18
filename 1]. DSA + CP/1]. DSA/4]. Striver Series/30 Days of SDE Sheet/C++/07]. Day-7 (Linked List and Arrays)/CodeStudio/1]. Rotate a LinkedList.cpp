#include <bits/stdc++.h> 
/********************************

    Following is the class structure of the Node class:
    
    class Node
    {
    	public:
    	    int data;
    	    Node *next;
    	    Node(int data)
    	    {
    	        this->data = data;
    	        this->next = NULL;
    	    }
    };

********************************/


Node *rotate(Node *head, int k) {
     // Write your code here.
    if(head==NULL||head->next==NULL||k==0) 
        return head;
    Node * dumy=head;

    int count=1;
    while(dumy->next!=NULL){
        dumy=dumy->next;
        count++;
    }
    dumy->next=head;
    k=k%count;
    k=count-k;
    while(k--) 
        dumy=dumy->next;
    head=dumy->next;
    dumy->next=NULL;
    return head;
}
