#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        //Your code here
        int sum=0;
        int flag=0;
         map <int,int> m;
        for(int i=0;i<n;i++){
            sum=sum+arr[i];
            if(sum==0 or m[sum]>0 or arr[i]==0){// sum=0 syntax error 
                flag=1;
                break;
            }
            else{
                m[sum]=1;
            }
        }
        if(flag==1)
            return true;
        else 
            return false;
    }
};

// { Driver Code Starts.
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    Solution obj;
	    	if (obj.subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}  // } Driver Code Ends