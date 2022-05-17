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
    	printlist(head);
    	head=recRevL(head);
    	printlist(head);
    	
    } 
    
    static Node recRevL(Node head){
        if(head==null||head.next==null)return head;
        Node rest_head=recRevL(head.next);
        Node rest_tail=head.next;
        rest_tail.next=head;
        head.next=null;
        return rest_head;
    }
    
    public static void printlist(Node head){
        Node curr=head;
        while(curr!=null){
        System.out.print(curr.data+" ");
        curr=curr.next;
    }System.out.println();
    }
} 