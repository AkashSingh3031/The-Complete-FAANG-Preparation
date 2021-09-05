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
        int i = 1;
        while(i*i <= x)
            i++;
        return (i-1);
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
