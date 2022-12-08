#include<bits/stdc++.h>
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    unordered_map<int,int> m;
    unordered_map<int,int>:: iterator it;
    vector<int> ans;
    for(int i=0;i<k-1;i++)
    {
        m[arr[i]]++;
    }
//     ans.push_back(m.size());
    int n=arr.size();
    int u=0;
    int ft=1;
    for(int i=k-1;i<n;)
    {
        if(ft==0)
        {
         it=m.find(arr[u]);
            it->second--;
            if(it->second==0)
            {
                m.erase(arr[u]);
                
//                 m[arr[i]]++;
            }
            u++;
            ft=1;
        }
        else
        {
            if(m.size()<k)
            m[arr[i]]++;
            ans.push_back(m.size());
            ft=0;
            i++;
        }
    }
    return ans;
    
}