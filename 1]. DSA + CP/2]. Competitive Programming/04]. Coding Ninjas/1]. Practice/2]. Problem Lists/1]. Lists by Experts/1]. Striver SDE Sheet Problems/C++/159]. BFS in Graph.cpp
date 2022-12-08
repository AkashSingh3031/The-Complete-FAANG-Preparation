#include<bits/stdc++.h>
vector<int> BFS(int vertex, vector<pair<int, int>> edges){
    vector<int> ans;
    vector<int> vis(vertex,0);
    vector<int>adj[vertex];
    for(int i=0;i<edges.size();i++){
        adj[edges[i].second].push_back(edges[i].first);
        adj[edges[i].first].push_back(edges[i].second);
    }
    for(int i=0;i<vertex;i++){
        if(!vis[i]){
        queue<int>q;
        q.push(i);
        vis[i]=1;
        sort(adj[i].begin(),adj[i].end());    
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
        }
    }
    return ans;    
}