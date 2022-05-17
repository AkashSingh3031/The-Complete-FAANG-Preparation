#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *A, int n) 
    {
        long long int n_sum = (n*(n+1))/2, n_sq_sum = (n*(n+1)*(2*n +1))/6;
        long long int missing = 0, repeating = 0;

        for(int i = 0; i < n; i++)
        {
           n_sum -= (long long int)A[i];
           n_sq_sum -= (long long int)A[i]*(long long int)A[i];
        }

        missing = (n_sum + n_sq_sum/n_sum)/2;
        repeating = missing - n_sum;
        long long int* ans = new long long int(2);
        ans[0] = repeating;
        ans[1] = missing;
        return ans;   
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
