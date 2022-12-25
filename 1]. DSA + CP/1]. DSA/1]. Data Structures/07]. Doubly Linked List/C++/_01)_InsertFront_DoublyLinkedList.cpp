#include <iostream>
using namespace std;

//doubly linked list node using struct
struct Node{
    int data;
    Node* next;
    Node* prev;
};

//insert node at the front of doubly linked list
void insert_front(Node** head_ref, int new_data){
    //allocate memory for node
    struct Node* new_node = new Node();

    //put data in the new node
    new_node->data = new_data;

    //make next of new node as head and previous as NULL
    new_node->next = (*head_ref);
    new_node->prev = NULL;

    //change previous of head node to new node
    if((*head_ref) != NULL){
        (*head_ref)->prev = new_node;
    }

    //move the head to point to the new node
    (*head_ref) = new_node;
}

int main (){
    //start with empty doubly linked list
    Node* head = NULL;

    //inserting 6. so linked list becomes 6->NULL
    insert_front(&head, 6);

    //inserting 7 at the front. so linked list becomes 7->6->NULL
    insert_front(&head, 7);

    //inserting 1 at the front. so linked list becomes 1->7->6->NULL
    insert_front(&head, 1);

    //inserting 4 at the front. so linked list becomes 4->1->7->6->NULL
    insert_front(&head, 4);

    //inserting 8 at the front. so linked list becomes 8->4->1->7->6->NULL
    insert_front(&head, 8);

    cout << "Doubly linked list is: ";
    while(head != NULL){
        cout << head->data << "-->";
        head = head->next;
    }
    cout<<"NULL";

    return 0;
}