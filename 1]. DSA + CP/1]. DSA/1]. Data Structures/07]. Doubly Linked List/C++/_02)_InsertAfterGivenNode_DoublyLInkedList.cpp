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
        cout << "The given previous node cannot be NULL"<<endl;
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
   //Creating a node with a value 9 so the list becomes 9->NULL
    Node* head = new Node();
    head->next = nullptr;
    head->data = 9;

    //inserting 2 after head. so linked list becomes 9->2->NULL
    insert_after(head, 2);

    //inserting 7 after head. so linked list becomes 9->7->2->NULL
    insert_after(head, 7);

    //inserting 1 after head. so linked list becomes 9->1->7->2->NULL
    insert_after(head, 1);

    //inserting 4 after head. so linked list becomes 9->4->1->7->2->NULL
    insert_after(head, 4);

    //inserting 8 after head. so linked list becomes 9->8->4->1->7->2->NULL
    insert_after(head, 8);

    cout << "Doubly linked list is: ";
    while(head != nullptr){
        cout << head->data << "-->";
        head = head->next;
    }
    cout<<"NULL";

    return 0;
}
