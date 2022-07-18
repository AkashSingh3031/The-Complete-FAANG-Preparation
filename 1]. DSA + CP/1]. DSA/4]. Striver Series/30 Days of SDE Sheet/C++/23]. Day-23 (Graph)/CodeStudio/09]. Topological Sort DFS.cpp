#include <bits/stdc++.h>
void solve(vector<vector<int>>&adj,vector<int>&indeg,vector<int>&ans,queue<int>&q){
   while(!q.empty()){
       int t=q.front();
       q.pop();
       ans.push_back(t);       
       for(auto it:adj[t]){
           indeg[it]--;
           if(indeg[it]==0){
               q.push(it);
           }
       }
   }
   return ;
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    vector<vector<int>>adj(v+1,vector<int>());
    
    for(int i=0;i<e;i++){
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    
    vector<int>indeg(v+1,0);
    queue<int>q;
    vector<int>ans;

    for(int i=0;i<v;i++){
        for(int j=0;j<adj[i].size();j++){
            indeg[adj[i][j]]++;
        }
    }
    for(int i=0;i<v;i++){
        if(indeg[i]==0){
            q.push(i);
        }
    }
    if(!q.empty()) 
        solve(adj,indeg,ans,q);
    return ans;
}