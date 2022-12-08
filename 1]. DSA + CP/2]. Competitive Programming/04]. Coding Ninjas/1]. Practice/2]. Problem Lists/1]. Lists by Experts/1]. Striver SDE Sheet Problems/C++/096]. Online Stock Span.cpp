#include<bits/stdc++.h>
vector<int> findSpans(vector<int> &price) {
    int n=price.size();
    stack<pair<int,int>>s;
    vector<int>ans(n);
    for(int i=0; i<n ; i++)
    {
        if(s.empty())
            ans[i]=1;
        else if(s.size()>0 && s.top().first>price[i])
            ans[i]=1;
        else if(s.size()>0 && s.top().first<=price[i])
        {
            while(s.size()>0 && s.top().first<=price[i])
                s.pop();
            if(s.empty())
                ans[i]=i+1;
            else
                ans[i]=i-s.top().second;
        }
        s.push({price[i],i});
    }
    return ans;
}