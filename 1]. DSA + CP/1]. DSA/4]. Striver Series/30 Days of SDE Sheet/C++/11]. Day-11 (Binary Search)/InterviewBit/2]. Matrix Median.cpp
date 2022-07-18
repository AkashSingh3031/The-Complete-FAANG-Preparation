int Solution::findMedian(vector<vector<int> > &A) {
    vector<int> ans;
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A[0].size();j++)
        {
            ans.push_back(A[i][j]);
        }
    }
    
    sort(ans.begin(), ans.end());
    int m=ans.size()/2;
    int x=ans[m];
    return x;
}
