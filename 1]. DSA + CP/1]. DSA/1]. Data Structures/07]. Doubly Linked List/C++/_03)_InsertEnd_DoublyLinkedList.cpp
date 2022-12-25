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

int main() {
    //start with empty doubly linked list
    Node* head = NULL;

    //inserting 5. so linked list becomes 5->NULL
    insert_end(&head, 5);

    //inserting 7 at the end. so linked list becomes 5->7->NULL
    insert_end(&head, 7);

    //inserting 1 at the end. so linked list becomes 5->7->1->NULL
    insert_end(&head, 1);

    //inserting 4 at the end. so linked list becomes 5->7->1->4->NULL
    insert_end(&head, 4);

    //inserting 8 at the end. so linked list becomes 5->7->1->4->8->NULL
    insert_end(&head, 8);

    cout << "Doubly linked list is: ";
    while(head != NULL){
        cout << head->data << "-->";
        head = head->next;
    }
    cout<<"NULL";
    return 0;
}
