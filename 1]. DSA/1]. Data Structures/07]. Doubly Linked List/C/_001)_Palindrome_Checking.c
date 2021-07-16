#include<string.h>
#include<stdlib.h>
#include<stdio.h>
struct node{
	char letter;
	struct node *next;
	struct node *prev;
}*head,*newhead,*temp,*newtemp,*new;
int main(){
	int i,length,flag=1;
	char input[20];
	printf("\nEnter String: ");
	scanf("%s",input);
	length = strlen(input);
	for(i=0;i<length;i++){ 	//storing one letter per node
	
		new = (struct node *)malloc(sizeof(struct node));
		new->letter = input[i]; 
		new->next = NULL;
		new->prev = NULL;
		
		if(head==NULL){
			head = new;
			temp = new;
		}
		else{
			new->prev = temp;
			temp->next = new;
			temp = new;
			temp->next = NULL;
		}
	}
	newhead = head;
	newtemp = temp;
	for(i=0;i<length;i++){
		if(newhead->letter!=newtemp->letter){
			flag=0;
			break;
		}
		else{
			flag=1;
		}
		newhead = newhead->next;	
		newtemp = newtemp->prev;
	}
	if(flag==0){
		printf("Not palindrome");
	}
	else{
		printf("Palindrome");
	}
	return 0;
}
