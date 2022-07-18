#include <bits/stdc++.h>
void solve(int i,vector<vector<int>>&adj,vector<int>&vis,vector<int>&ans){
    vis[i]=1;
    
    for(auto it:adj[i]){
        if(!vis[it]){
            solve(it,adj,vis,ans);
        }
    }
    ans.push_back(i);
    return ;
    
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    vector<vector<int>>adj(v+1,vector<int>());
    
    for(int i=0;i<e;i++){
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    vector<int>vis(v+1,0);
    vector<int>ans;
    for(int i=0;i<v;i++){
        if(!vis[i]){
            solve(i,adj,vis,ans);
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}