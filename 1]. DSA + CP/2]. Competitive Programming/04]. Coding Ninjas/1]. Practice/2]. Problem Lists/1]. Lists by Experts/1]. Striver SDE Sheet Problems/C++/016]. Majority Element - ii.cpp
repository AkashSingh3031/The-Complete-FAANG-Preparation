#include <bits/stdc++.h> 
vector<int> majorityElementII(vector<int> &arr)
{
        // Write your code here.
        int cnt1 = 0, cnt2 = 0, num1=0, num2=1;
    
        for(int n: arr){
            if (num1==n){
                cnt1++;
            }
            else if (num2==n){
                cnt2++;
            }
            else if (cnt1==0){
                num1 = n;
                cnt1 = 1;
            }
            else if (cnt2 == 0){
                num2 = n;
                cnt2 = 1;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = cnt2 = 0;
        for(int n: arr){
            if (n==num1)   
                cnt1++;
            else if (n==num2)  
                cnt2++;
        }

        vector<int> res;
        if (cnt1 > arr.size()/3)   
            res.push_back(num1);
        if (cnt2 > arr.size()/3)   
            res.push_back(num2);
        return res;
}
