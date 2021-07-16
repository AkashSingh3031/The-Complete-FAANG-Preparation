/*
Linked List operations

1. Creation

2. Insertion
  2a. At beginning 
  2b. At end 
  2c. Before specific node

3. Deletion
  3a. Beginning 
  3b. End 
  3c. Specific
  
4. Search

5. Display
*/
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
}*head,*temp,*new,*iterator,*newhead;  
void create();
void insertion();
void deletion();
void search();
void disp();
int main(){
	int ch,a=1; 
  while(a!=0) 
  { 
    printf("\n1. Create LL"); 
    printf("\n2. Insertion"); 
    printf("\n3. Deletion"); 
    printf("\n4. Search"); 
    printf("\n5. Display"); 
    printf("\n6. EXIT"); 
    printf("\nEnter your choice :"); 
    scanf("%d",&ch); 
   switch(ch) 
   { 
     case 1:  
            create(); 
            break; 
     case 2:  
            insertion(); 
            break; 
     case 3: 
            deletion(); 
            break; 
     case 4: 
            search(); 
            break;        
     case 5: 
            disp(); 
            break; 
     case 6: 
            printf("\nExiting!!\n"); 
            a=0; 
            break; 
     default: 
            printf("\nInvalid input!"); 
   } 
  } 
	return 0;
}
void create(){
	int size;
	printf("Enter size of LL: ");
	scanf("%d",&size);
	for(int i=0;i<size;i++){
		
		new = (struct node *)malloc(sizeof(struct node));
		
		printf("Enter value: ");
		scanf("%d",&new->data);
		new->next=NULL;
		
		if(head==NULL){
			head = new;    
			temp = new;
		}
		else{
			temp->next = new;
			temp = new;
		}
		
		
	}
}
void disp(){
	
	if(head==NULL){
		printf("NULL");
	}
	else{
		iterator = head;
		while(iterator!=NULL){
			printf("%d\t",iterator->data);
			iterator = iterator->next;
		}
	}
	
}
void search(){
	int x,count=0;
	printf("Enter search value: ");
	scanf("%d",&x);
	iterator = head;
	if(iterator==NULL){
		printf("Empty LL");
		return;
	}
	while(iterator!=NULL){
		if(iterator->data==x){
			printf("Element found in node %d",count);
			return;
		}
		count++;
		iterator = iterator->next;
	}
	printf("Element not found");
}
void deletion(){
	int choice;
	printf("1. beginning \t 2. End \t 3. Specific");
	scanf("%d",&choice);
	if(choice==1){
		printf("Deleting first node");
		head = head->next;
	}
	else if(choice==2){
		iterator = head;
		while(iterator->next!=NULL){
			newhead = iterator;
			iterator = iterator->next;
		}
		newhead->next = NULL;
	}
	else{
		int x;
		printf("enter value to delete");
		scanf("%d",&x);
		iterator = head;
		while(iterator->data!=x && iterator->next!=NULL){
			temp = iterator;
			iterator = iterator->next;
		}
		temp->next = iterator->next;
		
	}
}
void insertion(){
	int choice;
	printf("1. at beginning 2. at end 3. before specific node");
	scanf("%d",&choice);
	if(choice==1){
		int x;
		printf("Enter value to insert");
		scanf("%d",&x);
		new = (struct node *)malloc(sizeof(struct node));
		new->data = x;
		new->next=head;
		head = new;
	}
	else if(choice==2){
		int x;
		printf("Enter value to insert");
		scanf("%d",&x);
		new = (struct node *)malloc(sizeof(struct node));
		new->data = x;
		temp->next = new;
		temp = new;
		temp->next= NULL;
	}
	else{
		int x;
		printf("enter before node value");
		scanf("%d",&x);
		iterator = head;
		new = (struct node *)malloc(sizeof(struct node));
		while(iterator!=NULL && iterator->data!=x){
			iterator = iterator->next;
		}
		iterator->next = new->next;
		iterator->next = new;
	}
}



