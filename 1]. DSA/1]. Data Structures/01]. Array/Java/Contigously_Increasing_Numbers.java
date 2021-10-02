/*
Ques:-
Given two integers start and end, return a sorted list of integers such that every number e is between start = e = end and the digits of e are contiguously increasing. For example, 2345 is contiguously increasing while 135 and 321 are not.

Constraints

0 = start = end < 2 ** 31
Example 1
Input
start = 0
end = 100
Output
[1, 2, 3, 4, 5, 6, 7, 8, 9, 12, 23, 34, 45, 56, 67, 78, 89]



Intuition:- 
Step 1:- Since digits are increasing contigously. So we will take next =digit+1
Step 2:- Since start can be any number its not always 0. It can be any number.So we will iterate till that start number.
Step 3:- Once we reach start we keep adding element to array and then keep increasing next and keep making digit with formula digit=digit*10+ num
Step 4:- Since values added to array will be random so we will sort the array after adding all elements till end number.

Ans:-
*/

import java.util.*;

class Solution {
    public int[] solve(int start, int end) {
        ArrayList<Integer> a=new ArrayList<>();
        for(int i=1;i<=9;i++){
            int digit=i; 
            int next=i+1;

            while(next<=10 && digit<start){
                digit=digit*10+next;
                next++;
            }

             while(next<=10 && digit<=end){
                a.add(digit);
                digit=digit*10+next;
                next++;
            }

        }
        Collections.sort(a);
        int arr[]=new int[a.size()];
        for(int j=0;j<a.size();j++){
            arr[j]=a.get(j);
        }
        return arr;
    }
}
