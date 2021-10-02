#include <bits/stdc++.h>

using namespace std;
#define ll long long

 // } Driver Code Ends

class Solution{
public:
    vector<ll> nthRowOfPascalTriangle(int n) 
    {
        vector<vector<ll>> res(n+1);
        for (ll line = 1; line <= n; line++)
        {
            ll C = 1; // used to represent C(line, i)
            vector<ll> temp;
            for (ll i = 1; i <= line; i++)
            {
                // The first value in a line is always 1
                temp.push_back(C);
                C = C * (line - i) / i;
            }
            res.push_back(temp);
        }
        
        return res[res.size()-1];
    }
};


// { Driver Code Starts.


void printAns(vector<ll> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}
  // } Driver Code Ends
