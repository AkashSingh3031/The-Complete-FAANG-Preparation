vector<int> calc(string pat)
{
    int n=pat.length();
    vector<int> z(n,0);
    int L=0, R=0, i=1;
    for(;i<n;i++){
        if(i>R){
            L=R=i;
            while(R<n && pat[R-L]==pat[R]) R++;
            z[i]=R-L;
            R--;
        }
        else{
            int k=i-L;
            if(i+z[k]<=R) z[i]=z[k];
            else{
                L=i;
                while(R<n && pat[R-L]==pat[R]) R++;
                z[i]=R-L;
                R--;
            }
        }
    }
    return z;
}

int zAlgorithm(string s, string p, int n, int m)
{
	// Write your code here
    string res=p+"$"+s; 
    vector<int> z=calc(res);
    vector<int> ans;
    for(int i=0;i<res.length();i++){
        if(z[i]==m) 
            ans.push_back(i-m-1);
    }
    return ans.size();
}