#include<bits/stdc++.h>
double median(vector<int> a, vector<int> b)
{
    // Write your code here.
    if(b.size() < a.size()) return median(b,a);
   int n1= a.size();
   int n2 = b.size();
   
   int low = 0;
   int high = n1;
   while(low<=high){
       int count1 = (low+ high)/2;
       int count2 = ((n1+n2 +1)/2) - count1;
       
       int l1 = count1==0 ? INT_MIN : a[count1-1];
       int l2 = count2 ==0 ? INT_MIN : b[count2-1];
       
       int r1 = count1 == n1 ? INT_MAX : a[count1];
       int r2 = count2 == n2 ? INT_MAX : b[count2];
       
       
       if(l1 <= r2 && l2 <= r1){
           if((n1+n2) %2 == 0){
               return double(((double)max(l1,l2) + (double)(double)min(r1,r2))/2);
               
           }
           else {
               return max(l1,l2);
           }
       }
       else if(l1 > r2){
           high = count1-1;
       }
       else{
           low = count1+1;
       }
   }
   
   return 0.0;
}
