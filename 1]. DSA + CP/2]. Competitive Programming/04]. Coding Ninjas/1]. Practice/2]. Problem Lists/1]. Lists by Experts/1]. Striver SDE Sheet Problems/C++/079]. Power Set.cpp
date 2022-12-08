void helper(vector<int>&v,int i,vector<int>&subset,vector<vector<int>> &ans){
 
    if(i==v.size())
    {
        ans.push_back(subset);
        return;
    }
    
    subset.push_back(v[i]);
     helper(v,i+1,subset,ans);

     subset.pop_back();
       helper(v,i+1,subset,ans);
}
vector<vector<int>>pwset(vector<int>v)
{
    vector<vector<int>>ans;
    vector<int>subset;
     helper(v,0,subset,ans);
    return ans;
}