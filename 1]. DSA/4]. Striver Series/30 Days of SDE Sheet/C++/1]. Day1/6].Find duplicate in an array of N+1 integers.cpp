#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int duplicates(int nums[], int n) 
    {
         if(n <= 1)
            return -1;
        int slow = nums[0];
        int fast = nums[nums[0]];
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        fast = 0;
        while (fast != slow)
        {
            fast = nums[fast];
            slow = nums[slow];
        }
        return slow;

    }
};


// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
          cin >> a[i];
        Solution obj;
        int ans = obj.duplicates(a, n);
        cout << ans << ' ';
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends
