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
    
    
    static Node insertEnd(Node head, int x){
        Node temp=new Node(x);
        if(head==null)return temp;
        Node curr=head;
        while(curr.next!=null){
            curr=curr.next;
        }
        curr.next=temp;
        return head;
    }
    
    public static void main(String args[]) 
    { 
        Node head=null;
	    head=insertEnd(head,10);
	    head=insertEnd(head,20);
	    head=insertEnd(head,30);
	    printlist(head);
    	
    } 
    
    public static void printlist(Node head){
        Node curr=head;
        while(curr!=null){
        System.out.print(curr.data+" ");
        curr=curr.next;
    }
    }
} 