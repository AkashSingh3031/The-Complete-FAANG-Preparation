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

Node *addTwoNumbers(Node *head1, Node *head2)
{
    // Write your code here.
    if (head1 == NULL and head2 == NULL) 
        return NULL;
    else if (head1 == NULL) 
        return head2; 
    else if (head2 == NULL) 
        return head1; 

    int add = head1->data + head2->data;
    Node *res = new Node(add % 10);
    res->next = addTwoNumbers(head1->next, head2->next);
        
    if (add >= 10) 
        res->next = addTwoNumbers(res->next, new Node(1));
    return res;
}
