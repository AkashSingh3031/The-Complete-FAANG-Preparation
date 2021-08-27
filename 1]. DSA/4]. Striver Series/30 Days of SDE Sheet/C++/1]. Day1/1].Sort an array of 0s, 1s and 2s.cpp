#include<bits/stdc++.h>
using namespace std;
// } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        int lo = 0;
        int mid = 0;
        int hi = n - 1;
        
        while(mid <= hi)
        {
            if(a[mid] == 0)
               swap(a[lo++], a[mid++]);
            else if(a[mid] == 1)
               mid++;
            else
               swap(a[mid], a[hi--]);
        }
    }
    
};

// { Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

  // } Driver Code Ends
