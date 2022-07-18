#include <bits/stdc++.h> 
/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    if(first == NULL)
        return second;
    if(second == NULL)
        return first;
    if(first->data > second->data)
        swap(first, second);
    
    Node<int> *res = first;
    while(first != NULL and second != NULL) {
        Node<int> *temp = first;
        while(first != NULL and first->data <= second->data) {
            temp = first;
            first = first->next;
        }
        temp->next = second;
        swap(first, second);
    }
    return res;
}
