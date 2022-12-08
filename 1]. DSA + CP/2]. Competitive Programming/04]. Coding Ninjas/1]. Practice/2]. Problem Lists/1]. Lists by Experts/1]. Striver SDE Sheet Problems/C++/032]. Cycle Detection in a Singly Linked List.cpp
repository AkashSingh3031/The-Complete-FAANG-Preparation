#include <bits/stdc++.h> 
/****************************************************************

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

*****************************************************************/

bool detectCycle(Node *head)
{
    // Write your code here
    Node *fast=head;
    Node *slow=head;
    
    while(fast->next!=NULL and fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
            return true;
    }
    return false;
}
