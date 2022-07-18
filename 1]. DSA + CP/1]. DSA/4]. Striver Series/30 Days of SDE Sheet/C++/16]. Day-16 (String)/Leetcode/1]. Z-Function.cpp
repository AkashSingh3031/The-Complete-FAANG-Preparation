class Solution {
public:
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
                if(z[k]<R-i+1) z[i]=z[k];
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
    
    int strStr(string haystack, string needle) {
        int n=haystack.length(), m=needle.length();
        if(m==0) 
            return 0;
        string res=needle+"$"+haystack; 
        vector<int> z=calc(res);
        for(int i=0;i<res.length();i++){
            if(z[i]==m) 
                return i-m-1;
        }
        return -1;
    }
};