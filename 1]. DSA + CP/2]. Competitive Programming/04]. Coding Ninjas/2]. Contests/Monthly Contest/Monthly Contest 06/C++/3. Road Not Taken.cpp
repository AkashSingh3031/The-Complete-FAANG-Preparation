/*
    Time Complexity: O(N)
    Space Complexity: O(N)

    where 'N' is the number of city.
*/

void dfs(int curr, vector<int> &vis, vector<int> adj[]){
    vis[curr] = 1;
    for (auto i : adj[curr]){
        if (vis[i] == 0){
            dfs(i, vis, adj);
        }
    }
}

int roadNotTaken(int n, vector<vector<int>> roads){

    // Creating adjacency list.
    vector<int> adj[n + 1];
    for (int i = 0; i < n - 1; i++){
        int u = roads[i][0];
        int v = roads[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Creating 'vis'.
    vector<int> vis(n + 1, 0);

    // Creating variable 'c' to store our answer.
    int c = 0;

    // Calculating minimum number of days.
    for (int i = 1; i <= n; i++){
        if (vis[i] == 1){

            // Already visited city.
            continue;
        }
        dfs(i, vis, adj);
        c++;
    }

    // 'c'- 1 is our answer.
    return c - 1;
}