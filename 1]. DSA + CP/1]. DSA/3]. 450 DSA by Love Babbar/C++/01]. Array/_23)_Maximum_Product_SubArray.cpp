#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(int *arr, int n) {
	    // code here
	    long long minVal = arr[0];
        long long maxVal = arr[0];
        long long maxProduct = arr[0];
        for (int i = 1; i < n; i++)
        {
        if (arr[i] < 0)
            swap(maxVal, minVal);
        maxVal = max(1ll*arr[i], maxVal * arr[i]);
        minVal = min(1ll*arr[i], minVal * arr[i]);
        maxProduct = max(maxProduct, maxVal);
        }
        return maxProduct;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends