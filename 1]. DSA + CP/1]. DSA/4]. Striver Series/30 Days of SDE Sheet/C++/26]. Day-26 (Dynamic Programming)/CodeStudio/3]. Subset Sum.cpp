bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<bool>prev(k+1);
    prev[arr[0]] = true;
    prev[0]=true;
    for(int i=1;i<n;i++)
    {
        prev[0] = true;
        vector<bool>curr(k+1);
        for(int j=1;j<k+1;j++)
        {
            bool take = false;
            if(arr[i]<=j)take = prev[j-arr[i]];
            bool notTake = prev[j];
            curr[j] = take|notTake;
        }
        prev = curr;
    }
    return prev[k];
}