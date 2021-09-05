#include<bits/stdc++.h>
using namespace std;

// Function to find square root
// x: element to find square root
class Solution
{
  public:
    long long int floorSqrt(long long int x) 
    {
        // Your code goes here 
        long long int low=1, high=x, ans = -1;
        while(low <= high)
        {
            long long int mid = (low+high)/2;
            long long int mSq = mid*mid;
            if(mSq == x)
                return mid;
            else if(mSq > x)
                high = mid-1;
            else
            {
                low = mid+1;
                ans = mid;
            }
        }
        return ans;
    }
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
  return 0;   
}
