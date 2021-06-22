#ifndef LIST_H_
#define LIST_H_

#include<iostream>
#define NIL nullptr
#define TYPE int  // Type of data field

/**
 *  Some declarations and definitions
 *  TypeSelect : Is the corresponding data field a linked list or data
 *  ptr_node : Node pointer
 *
 */
typedef enum {DATA_TYPE,LIST_TYPE} TypeSelect ;

struct node {
    TypeSelect type;
    union {
        TYPE data;
        struct node* List;
    } field;
    struct node* next {
        nullptr
    };
};
using ptr_node = struct node *;
/**
 * Overloading two Cons facilitates the
 * splicing between data and linked lists
 *
 * @param d
 * @param next
 * @return ptr_node
 */
ptr_node Cons(TYPE d,ptr_node next) {
    ptr_node n = new node;
    n->type = DATA_TYPE;
    n->next = next;
    n->field.data = d;
    return n;
}
ptr_node Cons(ptr_node lhs,ptr_node next) {
    if(lhs) {
        ptr_node n = new node;
        n->type = LIST_TYPE;
        n->next = next;
        n->field.List=lhs;
        return n;
    }
    return nullptr;
}

/**
 *  A more general way of constructing linked lists
 *  List(1,2,3,4,.....)
 *
 * @return ptr_node
 */
ptr_node LIST() {
    return nullptr;
}
template<typename First,typename... Args>
ptr_node LIST(First arg,Args... parampkg) {
    return Cons(arg,LIST(parampkg...));
}


void DisplayList(ptr_node list) {
    std::cout<<"(";
    if(list!=nullptr) {
        while(list) {
            if(list->type==DATA_TYPE)
                std::cout<<list->field.data<<",";
            if(list->type==LIST_TYPE)
                DisplayList(list->field.List);
            list=list->next;
        }

    }
    std::cout<<")";
}
void free_cons(ptr_node& phead) {
    while(phead) {
        if(phead->type==LIST_TYPE)
            free_cons(phead->field.List);
        ptr_node ptr = phead->next;
        ptr_node ptemp = phead;
        phead=ptr;
        delete ptemp;
        ptemp=nullptr;
    }
}

std::size_t length(ptr_node linked_list,std::size_t len =0) {
    if (linked_list) return length(linked_list->next,len+1);
    return len;
}
#endif