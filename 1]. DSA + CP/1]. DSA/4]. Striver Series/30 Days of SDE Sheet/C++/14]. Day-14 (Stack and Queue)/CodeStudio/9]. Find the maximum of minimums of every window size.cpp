#include<stack>
vector<int> nextSmaller(vector<int> &a)
{
    int n=a.size();
    vector<int> v(n,n);
    stack<pair<int,int>> s;
    s.push({a[n-1],n-1});
    
    for(int i=n-2;i>=0;i--)
    {
        while(!s.empty() and s.top().first>=a[i])
            s.pop();
        
        if(!s.empty())
            v[i]=s.top().second;
        s.push({a[i],i});
    }
    
    return v;
}
vector<int> prevSmaller(vector<int> &a)
{
    int n=a.size();
    vector<int> v(n,-1);
    stack<pair<int,int>> s;
    s.push({a[0],0});
    
    for(int i=1;i<n;i++)
    {
        while(!s.empty() and s.top().first>=a[i])
            s.pop();
        
        if(!s.empty())
            v[i]=s.top().second;
        s.push({a[i],i});
    }
    
    return v;
}
vector<int> maxMinWindow(vector<int> a, int n) {
    vector<int> ns=nextSmaller(a);
    vector<int> ps=prevSmaller(a);
    
    vector<int> ans(n,INT_MIN);
    for(int i=0;i<n;i++)
    {
        int l=(ns[i]-ps[i]-1)-1; 
        if(a[i]>ans[l])
            ans[l]=a[i];
    }
    for(int i=n-2;i>=0;i--)
        if(ans[i]<ans[i+1])
            ans[i]=ans[i+1];
    return ans;
}