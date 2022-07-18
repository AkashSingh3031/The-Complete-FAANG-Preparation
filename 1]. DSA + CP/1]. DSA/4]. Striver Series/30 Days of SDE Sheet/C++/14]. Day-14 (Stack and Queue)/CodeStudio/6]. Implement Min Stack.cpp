// Implement class for minStack.
#include<bits/stdc++.h>
class minStack
{
	// Write your code here.
	int Top;
    int size;
    int *mini;
    int *arr;
	public:
		
		// Constructor
		minStack() 
		{ 
			// Write your code here.
            size=100000;
            Top=-1;
            arr=new int[size];
            mini=new int[size];
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			// Write your code here.
            Top=Top+1;
            arr[Top]=num;
            if(Top==0)
                mini[Top]=num;
            else
                mini[Top]=min(mini[Top-1],num);    
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			// Write your code here.
            if(Top==-1)
                return -1;
            else
                return arr[Top--];
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			// Write your code here.
            if(Top==-1)
                return -1;
            else
                return arr[Top];
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			// Write your code here.
            if(Top==-1)
                return -1;
            else
                return mini[Top];
		}
};