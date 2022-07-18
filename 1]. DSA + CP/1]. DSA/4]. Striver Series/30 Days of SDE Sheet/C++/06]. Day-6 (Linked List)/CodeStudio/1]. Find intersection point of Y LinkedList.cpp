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

int findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    if(firstHead == NULL || secondHead == NULL) 
        return -1;
    Node *cur1 = firstHead, *cur2 = secondHead;
    map<Node*,bool> visited;
    visited[firstHead] = true;
    while(cur1!=NULL) {
        visited[cur1] = true;
        cur1 = cur1->next;
    }
   
    while(cur2!=NULL){
        if(visited[cur2]==true) 
            return cur2->data;
        else
            cur2=cur2->next;
    }
    return -1;
}
