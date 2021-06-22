#include<iostream>
#include"List.hpp"
#include<cassert>
#define ASSERT_NULL(PTR)\
    (assert(PTR==nullptr))
int main() {
    //construct list
    /*
        Method 1
    */
    ptr_node linked_list1= LIST(1,2,LIST(1,2,3),3,4,5,6);

    ptr_node linked_list2 = nullptr;
    /*
        Method 2
    */
    ptr_node linked_list3 = Cons(1,Cons(Cons(1,NIL),Cons(2,NIL)));
    ptr_node linked_list4 = Cons(1,Cons(2,Cons(3,Cons(4,NIL))));
    /*
        Display List
    */
    std::cout<<"Linked_list1 : ";
    DisplayList(linked_list1);
    std::cout<<std::endl;
    std::cout<<"Linked_list1 : ";
    DisplayList(linked_list2);
    std::cout<<std::endl;
    std::cout<<"Linked_list3 : ";
    DisplayList(linked_list3);
    std::cout<<std::endl;
    std::cout<<"Linked_list4 : ";
    DisplayList(linked_list4);
    std::cout<<std::endl;
    std::cout<<"Linked_list1 = "<<length(linked_list1)<<std::endl;
    std::cout<<"Linked_list2 = "<<length(linked_list2)<<std::endl;
    std::cout<<"Linked_list3 = "<<length(linked_list3)<<std::endl;
    std::cout<<"Linked_list4 = "<<length(linked_list4)<<std::endl;
    /*
        delete list
    */
    free_cons(linked_list1);
    free_cons(linked_list2);
    free_cons(linked_list3);
    free_cons(linked_list4);
    ASSERT_NULL(linked_list1);
    ASSERT_NULL(linked_list2);
    ASSERT_NULL(linked_list3);
    ASSERT_NULL(linked_list4);
    return 0;
}