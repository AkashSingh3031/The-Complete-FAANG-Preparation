#include <iostream>
using namespace std;

class Solution
{
  public:
    int RotateArray(int arr[], int n, int d)
    {
        int temp[d];
        for(int i=0; i<d; i++)
            temp[i] = arr[i];
        for(int i=d; i<n; i++)
            arr[i-d] = arr[i];
        for(int i=0; i<d; i++)
            arr[n-d+i] = temp[i];
    }
};

int main() 
{
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n, d;
	    cin>>n>>d;
	    
	    int arr[n];
	    for(int i=0; i<n; i++)
            	cin>>arr[i];
		
	    Solution ob;
	    int res = ob.RotateArray(arr, n, d);
		
	    for(int i=0; i<n; i++)
            	cout<<arr[i]<<" ";
            cout<<endl;
	}
	return 0;
}
