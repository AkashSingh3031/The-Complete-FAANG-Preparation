#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        //Your Code Here
        if (n < 3)
        {
            return false;
        }
        sort(A, A + n);

        for (int i = 0; i < n - 2; i++)
        {
            if (i > 0 && A[i - 1] == A[i])
                continue;

            if (A[i] + A[i + 1] + A[i + 2] > X)
                break;
            if (A[i] + A[n - 1] + A[n - 2] < X)
                continue;

            int left = i + 1;
            int right = n - 1;

            while (left < right)
            {
                int sum = A[i] + A[left] + A[right];
                if (sum == X)
                {
                    return true;

                    while (left < right && A[left] == A[left + 1])
                        left++;
                    while (right > left && A[right] == A[right - 1])
                        right--;

                    left++;
                    right--;
                }
                else if (sum < X)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }

        return false;
    }

};

// { Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}
  // } Driver Code Ends