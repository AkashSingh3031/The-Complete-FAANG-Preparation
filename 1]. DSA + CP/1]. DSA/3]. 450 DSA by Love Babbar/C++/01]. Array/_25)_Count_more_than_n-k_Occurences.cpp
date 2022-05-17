// A C++ program to print elements with count more than n/k

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find all elements in array that appear more than n/k times.
    int countOccurence(int arr[], int n, int k) {
        // Your code here
         map<int,int> m;
        int res=0;
        for(int i=0;i<n;i++){
            if(m.find(arr[i])!=m.end())
                m[arr[i]]++;
            else if(m.size()<k-1)
                m[arr[i]]=1;
            else
                for(auto x:m){
                    x.second--;
                    if(x.second==0)
                        m.erase(x.first);}
        }
        for(auto x:m)
        {
            int count=0;
            for(int i=0;i<n;i++)
            {
                if(x.first==arr[i])
                    count++;
            
           }
           
            if(count>n/k)
                 res ++;
                
                
        }
        return res;
        }
};


// { Driver Code Starts.
int main() {
    int t, k;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;

        int arr[n];

        for (i = 0; i < n; i++) cin >> arr[i];
        cin >> k;
        Solution obj;
        cout << obj.countOccurence(arr, n, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends