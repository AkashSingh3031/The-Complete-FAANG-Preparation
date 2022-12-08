#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

class Node {
public:
	int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};

*****************************************************************/
Node* merge(Node* a , Node* b){
    if(a == NULL) return b;
    if(b == NULL) return a;
    
    Node* result;
    if(a->data < b->data){
        result = a;
        result->child = merge(a->child , b);
    }
    else{
        result = b;
        result->child = merge(a,b->child);
    }
    result->next = NULL;
    return result;
}

Node* flattenLinkedList(Node* head) 
{
    // Write your code here
    if(head == NULL || head->next == NULL)
        return head;
    return merge(head , flattenLinkedList(head->next));
}
