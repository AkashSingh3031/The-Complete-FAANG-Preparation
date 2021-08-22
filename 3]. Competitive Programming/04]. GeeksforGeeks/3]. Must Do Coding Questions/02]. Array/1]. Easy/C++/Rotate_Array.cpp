#include<bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    //Function to rotate an array by d elements in counter-clockwise direction. 
    void rotateArr(int arr[], int d, int n)
    {
        // code here
        int temp[d];
        for(int i=0; i<d; i++)
            temp[i] = arr[i];
        for(int i = d; i<n; i++)
            arr[i-d] = arr[i];
        for(int i=0; i<d; i++)
            arr[n-d+i] = temp[i];
    }
};


int main() 
{
	int t;
	//taking testcases
	cin >> t;
	while(t--)
  	{
	    int n, d;	    
	    //input n and d
	    cin >> n >> d;    
	    int arr[n];    
    
	    //inserting elements in the array
	    for(int i = 0; i < n; i++)
      	    	cin >> arr[i];
	    
	    Solution ob;
	    //calling rotateArr() function
	    ob.rotateArr(arr, d,n);
    
	    //printing the elements of the array
	    for(int i =0;i<n;i++)
      		cout << arr[i] << " ";
	    
	    cout << endl;
	}
	return 0;
}  
