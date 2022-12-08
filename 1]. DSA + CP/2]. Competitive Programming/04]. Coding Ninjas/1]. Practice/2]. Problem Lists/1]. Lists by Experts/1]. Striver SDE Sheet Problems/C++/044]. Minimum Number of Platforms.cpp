int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    sort(at,at+n);
    sort(dt,dt+n);
    int j=0;
    int ans=0;
       
    for(int i=0;i<n;i++)
    {
        if(at[i]<=dt[j])
            ans++;
        else
            j++;
    }
    return ans;
}