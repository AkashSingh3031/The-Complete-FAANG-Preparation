#include<bits/stdc++.h>

bool isCycleBFS(int node, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited){
    unordered_map<int, int> parent;
    parent[node] = -1;
    visited[node] = 1;
    queue<int> q;
    q.push(node);
   
    while(!q.empty()){
        int front = q.front();
        q.pop();
        for(auto neighbour: adj[front]){
            if(visited[neighbour] == true && neighbour != parent[front]){
                return true;
            }
            else if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour] =1;
                parent[neighbour] = front;
            }
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    unordered_map<int, list<int>> adj;
    for(int i=0;i<m; i++){
        int u = edges[i][0];
        int v = edges[i][1];
       
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
   
    unordered_map<int, bool> visited;
    for(int i =0; i<n; i++){
        if(!visited[i]){
            bool ans = isCycleBFS(i, adj, visited);
            if(ans == 1){
                return "Yes";
            }
        }
    }
    return "No";
}