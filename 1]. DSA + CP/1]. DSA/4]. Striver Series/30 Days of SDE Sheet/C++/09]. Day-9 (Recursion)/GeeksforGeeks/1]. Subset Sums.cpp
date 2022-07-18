#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
private:
    void fun(vector<int> arr, int N,vector<int>&sumOfSubsets,int index,int sum) {
        if(index>=N) {
            sumOfSubsets.push_back(sum); 
            return;
        }
        fun(arr,N,sumOfSubsets,index+1,sum+arr[index]);
        fun(arr,N,sumOfSubsets,index+1,sum);
    }
public:
    vector<int> subsetSums(vector<int> arr, int N) {
        // Write Your Code here
        vector<int> sumOfSubsets;
        fun(arr,N,sumOfSubsets,0,0);
        return sumOfSubsets;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends