 /**
 * @author Mayur Ingle(https://github.com/thecoder8890)
 *Problem :- https://leetcode.com/problems/add-two-numbers/
 */
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */


class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        // Start typing your Java solution below
        // DO NOT write main() function
        return calculate(l1, l2, 0); 
    }
    
        ListNode calculate(ListNode l1, ListNode l2, int carry)
       {
        if(l1==null&&l2==null&&carry==0) return null; 
        if(l1==null&&l2==null&&carry!=0) return new ListNode(1); 
	int temp=(l1==null? 0: l1.val)+ (l2==null? 0: l2.val)+ carry; 
	ListNode result=new ListNode(temp%10); 
	result.next=calculate(l1==null? null: l1.next, l2==null? null: l2.next, temp/10); 
        return result;
	 }
}
