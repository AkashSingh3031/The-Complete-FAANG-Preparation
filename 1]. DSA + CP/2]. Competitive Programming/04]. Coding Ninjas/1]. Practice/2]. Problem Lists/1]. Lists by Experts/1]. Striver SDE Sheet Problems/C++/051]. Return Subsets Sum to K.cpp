void Sum(vector<int> &arr,int n,int i,int k, vector<int> &v,vector<vector<int>>&ans) {
    if(k==0) {
        ans.push_back(v);
    }
    if(i>=n) return ;
    for(;i<n;i++) {
        v.push_back(arr[i]);
        Sum(arr,n,i+1,k-arr[i],v,ans);
        v.pop_back();
    }
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{  
    vector<vector<int>> ans;
    vector<int> v;
    Sum(arr,n,0,k,v,ans);
    return ans;
}