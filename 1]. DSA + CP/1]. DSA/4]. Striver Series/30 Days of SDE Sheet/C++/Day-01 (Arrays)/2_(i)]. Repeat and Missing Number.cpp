#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *A, int n) 
    {
        int count[n + 1];
        memset(count, 0, sizeof(count));
        for(int i = 0; i < n; i++)
          count[A[i]]++;

        int* ans = new int(2);
        for(int i = 1; i <= n; i++)
        {
            if(count[i] == 0)
              ans[1] = i;
            if(count[i] == 2)
              ans[0] = i;
        }

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
}  // } Driver Code Ends
