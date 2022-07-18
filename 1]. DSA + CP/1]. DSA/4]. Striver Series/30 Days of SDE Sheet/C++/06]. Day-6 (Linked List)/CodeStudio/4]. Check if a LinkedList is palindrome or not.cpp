#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int>* temp;
bool check(LinkedListNode<int>* p) {
    if (NULL == p) 
        return true;
    bool isPal = check(p->next) & (temp->data == p->data);
    temp = temp->next;
    return isPal;
}

bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    temp = head;
    return check(head);
}
