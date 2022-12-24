#include <iostream>
using namespace std;

//doubly linked list node using struct
struct Node{
    int data;
    Node* next;
    Node* prev;
};

//insert node after a given node in doubly linked list
void insert_after(Node* prev_node, int new_data){
    //check if the given previous node is NULL
    if(prev_node == NULL){
        cout << "The given previous node cannot be NULL";
        return;
    }

    //allocate memory for node
    struct Node* new_node = new Node();

    //put data in the new node
    new_node->data = new_data;

    //make next of new node as next of prev_node
    new_node->next = prev_node->next;

    //make the next of prev_node as new_node
    prev_node->next = new_node;

    //make prev_node as previous of new_node
    new_node->prev = prev_node;

    //change previous of new_node's next node
    if(new_node->next != NULL){
        new_node->next->prev = new_node;
    }
}

int main() {
    //start with empty doubly linked list
    Node* head = NULL;

    //inserting 2. so linked list becomes 6->NULL
    insert_after(head, 2);

    //inserting 7 after. so linked list becomes 2->7->NULL
    insert_after(head, 7);

    //inserting 1 after. so linked list becomes 2->7->1->NULL
    insert_after(head, 1);

    //inserting 4 after. so linked list becomes 2->7->1->4->NULL
    insert_after(head, 4);

    //inserting 8 after. so linked list becomes 2->7->1->4->8->NULL
    insert_after(head, 8);

    cout << "Doubly linked list is: ";
    while(head != NULL){
        cout << head->data << "-->";
        head = head->next;
    }

    return 0;
}