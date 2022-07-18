int numbersLessThan(vector<int> &row1, vector<int> &row2,int n)
{
    int ans=0;
    auto it1=upper_bound(row1.begin(),row1.end(),n);
    auto it2=upper_bound(row2.begin(),row2.end(),n);
    
    ans+=it1-row1.begin();
    ans+=it2-row2.begin();
    
    return ans;
}

int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    int low=min(row1[0],row2[0]);
    int high=max(row1[m-1],row2[n-1]);
    
    while(low<=high)
    {
        int mid=(low+high)/2;
        
        if(numbersLessThan(row1,row2,mid)<k)
            low=mid+1;
        else
            high=mid-1;
    }
    return low;
}