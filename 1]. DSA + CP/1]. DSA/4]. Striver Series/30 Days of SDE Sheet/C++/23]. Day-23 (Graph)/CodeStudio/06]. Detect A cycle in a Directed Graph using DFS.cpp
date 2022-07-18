#include<bits/stdc++.h>
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    // Write your code here.
    if(n==0)return 0;
    vector<int>arr[n];vector<int>indeg;
    for(int i=0;i<n;i++)
    {
        indeg.push_back(0);
    }
    for(int i=0;i<edges.size();i++)
    {
        arr[edges[i].first-1].push_back(edges[i].second-1);
        indeg[edges[i].second-1]++;
    }
    int count = 0;
    queue<int>q;
    for(int i=0;i<n;i++)
    {
        if(indeg[i]==0){
            q.push(i);count++;
            
        }
    }
    
    while(!q.empty())
    {
        int cur=q.front();q.pop();
        for(auto it:arr[cur])
        {
            indeg[it]--;
            if(indeg[it]==0)
            {q.push(it);count++;}
        }
    }
    
    if(count==n)
        return 0;
    return 1;
}