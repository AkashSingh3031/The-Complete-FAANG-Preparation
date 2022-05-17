import java.util.*;
import java.io.*;
import java.lang.*;

class Node{
        int data;
        Node next;
        Node(int x){
            data=x;
            next=null;
        }
    }
  
class Test { 
    
    public static void main(String args[]) 
    { 
        Node head=new Node(10);
    	head.next=new Node(20);
    	head.next.next=new Node(30);
    	head.next.next.next=new Node(40);
    	head.next.next.next.next=new Node(50);
    	printlist(head);
    	System.out.print("Nth node from end of Linked List: ");
    	printNthFromEnd(head,2);
    	
    } 
    
    static void printNthFromEnd(Node head,int n){
        if(head==null)return;
        Node first=head;
        for(int i=0;i<n;i++){
            if(first==null)return;
            first=first.next;
        }
        Node second=head;
        while(first!=null){
            second=second.next;
            first=first.next;
        }
        System.out.print(second.data);
    }
    
    public static void printlist(Node head){
        Node curr=head;
        while(curr!=null){
        System.out.print(curr.data+" ");
        curr=curr.next;
    }System.out.println();
    }
} 