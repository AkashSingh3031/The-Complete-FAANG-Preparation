#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int d){
        data=d;
        next=NULL;
    }
};
void insertatend(node*&head,int d){
    if(head==NULL){
        head= new node(d);
        return;
    }
    node *n=new node(d);
    node* temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=n;
}
node* insert_list(){
    node*head=NULL;
    int d;
    cin>>d;
    while(d!=-1){
        insertatend(head,d);
        cin>>d;
    }
    return head;
}
node* midpoint(node* head){
    if(head==NULL||head->next==NULL)
        return head;
    node* slow=head;
    node* fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}
node* merge(node*a,node*b){
    if(a==NULL)
        return b;
    if(b==NULL)
        return a;
    node* c=NULL;
    if(a->data<b->data){
        c=a;
        c->next=merge(a->next,b);
    }
    else{
        c=b;
        c->next=merge(a,b->next);
    }
    return c;
}
node* mergesort(node*head){
    if(head==NULL||head->next==NULL)
        return head;
    node* mid= midpoint(head);
    node* a=head;
    node*b=mid->next;
    mid->next=NULL;
    a=mergesort(a);
    b=mergesort(b);
    node* c=merge(a,b);
    return c;
}
void printlist(node* head){
    while(head!=NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
}
int main(){
    node* head=NULL;
    head=insert_list();
    printlist(head);
    cout<<endl;
    node* c=mergesort(head);
    printlist(c);
}
