#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:

    int sb(int arr[], int n, int x)
    {
        // Your code goes here   
        int ans = n+1;
        int left=0, cur_sum=0, right=0;
        while(right < n)
        {
            while(cur_sum <= x && right < n)
            cur_sum += arr[right++];
            while(cur_sum > x && left < right)
            {
                ans = min(ans, right - left);
                cur_sum -= arr[left++];
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.sb(a,n,x)<<endl;
	}
	return 0;
}  // } Driver Code Ends