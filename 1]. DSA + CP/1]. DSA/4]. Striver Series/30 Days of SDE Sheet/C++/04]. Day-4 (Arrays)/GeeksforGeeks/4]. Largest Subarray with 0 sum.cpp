#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        unordered_map<int ,int> mp;
        int sum = 0;
        int maxi = 0;
        for(int i = 0 ;i<n ; i++){
            sum+= A[i];
            if(sum == 0){
                maxi = i + 1;
            }
            else{
                if(mp.find(sum) != mp.end()){
                    maxi = max(maxi , i-mp[sum]);
                }
                else{
                    mp[sum] = i;
                }
            }
        }
        return maxi;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--) {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}
