class Solution {
private:
    void fun(int i,vector<int>arr,vector<int>&subset,vector<vector<int>>&ans)
    {
        if(i==arr.size())
        {
            ans.push_back(subset);
            return;
        }
        subset.push_back(arr[i]);
        fun(i+1,arr,subset,ans);
        subset.pop_back();       
        while(i+1 < arr.size() && arr[i]==arr[i+1])
            i++;  
        fun(i+1,arr,subset,ans);  
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& S) {
        sort(S.begin(), S.end());
        vector<vector<int>> ans;
        vector<int> subset;
        fun(0, S, subset, ans);
        sort(ans.begin(), ans.end());
         return ans;
    }
};