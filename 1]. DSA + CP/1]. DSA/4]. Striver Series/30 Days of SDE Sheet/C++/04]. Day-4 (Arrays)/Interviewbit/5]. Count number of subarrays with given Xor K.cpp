int Solution::solve(vector<int> &A, int B) {
    map<int,int> mp;
    int xr =0 , count = 0;
    for(int i=0;i<A.size();i++) {
        xr ^=A[i];
        if(xr == B) 
            count++;
        if(mp.find(xr ^ B) != mp.end())
            count += mp[xr ^ B];
        mp[xr]++;
    }
    return count;
}
