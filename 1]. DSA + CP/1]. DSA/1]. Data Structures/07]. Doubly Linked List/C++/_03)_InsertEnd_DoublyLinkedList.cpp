#include <iostream>
using namespace std;

//doubly linked list node using struct
struct Node{
    int data;
    Node* next;
    Node* prev;
};

//insert node at the end of doubly linked list
void insert_end(Node** head_ref, int new_data){
    //allocate memory for new node
    struct Node* new_node = new Node();

    //put data in the new node
    new_node->data = new_data;

    //make next of new node as NULL
    new_node->next = NULL;

    //if the linked list is empty, then make the new node as head
    if((*head_ref) == NULL){
        new_node->prev = NULL;
        (*head_ref) = new_node;
        return;
    }

    //traverse till the last node
    Node* last = (*head_ref);
    while(last->next != NULL){
        last = last->next;
    }

    //change the next of last node
    last->next = new_node;

    //make last node as previous of new node
    new_node->prev = last;

    return;
}