#include<bits/stdc++.h>
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<bool> visited(n+1);
    for(int i=0;i<=n;i++){
        visited[i]=false;
    }
    vector<int> distance(n+1);
    for(int i=0;i<=n;i++){
        distance[i]=INT_MAX;
    }
    distance[src]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            int u=edges[j][0];
            int v=edges[j][1];
            int w=edges[j][2];
            if(distance[u]!=INT_MAX && distance[u]+w<distance[v]){
                distance[v]=distance[u]+w;
            }
            
        }
    }
    if(distance[dest]==INT_MAX){
        return 1000000000;
    }
    return distance[dest];
    
}