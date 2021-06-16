//Link : https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1
/*
Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2, …N} is missing and one number 'B' occurs twice in array. Find these two numbers.

Example 1:

Input:
N = 2
Arr[] = {2, 2}
Output: 2 1
Explanation: Repeating number is 2 and 
smallest positive missing number is 1.*/
int *findTwoElement(int *arr, int n) {
        // code here
        int *result=new int(2);
        int count[n+1]={0};
        for(int i=0;i<n;i++) {
            count[arr[i]]++;
            
        }
        for(int i= 1;i <= n;i++) 
        {
            if(count[i] >1)
            {
                result[0]=i;
            }
        
            if(count[i]==0)
            {
                result[1]=i;
            }
        }
        
        return result;
    }