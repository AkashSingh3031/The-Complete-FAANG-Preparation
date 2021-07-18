 long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    sort(a.begin(),a.end());
    long long i=0;
    long long j=m-1;
    long long mn=INT_MAX;
    long long res;
    while(j<n)
    {
        res=a[j]-a[i];
        if(mn>res)
        {
            mn=res;
        }
        i++;
        j++;
    }
       
       
       
    return mn;
    }