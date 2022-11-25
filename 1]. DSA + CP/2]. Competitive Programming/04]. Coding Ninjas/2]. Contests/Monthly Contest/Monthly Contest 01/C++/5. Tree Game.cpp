/*
    Time Complexity: O(N)
    Space Complexity: O(N)

    where ‘N’ denotes the number of nodes in the tree.
*/

// It will take the adjacency matrix, a “dist” array to store the distance of 
// each node, current node ‘u’, parent node ‘p’, and current distance “cur”, 
// and will fill the “dist” array.
void dfs(vector<vector<int>> &adj, vector<int> &dist, int u, int p, int cur) {
    
    dist[u] = cur;
    
    for(int v : adj[u]) {
        if(v != p){
            dfs(adj, dist, v, u, cur + 1);
        }
    }
}


int minimumTime(int n, vector<vector<int>> &edges, int x, int y){
    
    // Declare a vector of vector “adj” to store the adjacency matrix. 
    vector<vector<int>> adj(n + 1);
    
    for(int i = 0; i < n - 1; ++i) {
        
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    // Declare two vectors “distNinja”, and “distBob” to store the distance of each 
    // node from Ninja and Bob respectively.
    vector<int> distNinja(n+1), distBob(n+1);

    // Call the “dfs” function using both ‘X’ and ‘Y’ to fill corresponding distance 
    // arrays of Ninja and Bob.
    dfs(adj, distNinja, x, -1, 0);
    dfs(adj, distBob, y, -1, 0);

    // Declare an integer variable “ans” and initialize it with 0.
    int ans = 0;

    // Iterate over the nodes.
    for(int i = 1; i < n+1; ++i) {

        // If the distance of the current node from Bob is greater 
        // than the distance from Ninja.
        if(distNinja[i] < distBob[i]) {
            // Update ”ans” as the maximum of itself and distance of that node from Bob.
            ans = max(ans, distBob[i]);
        }
    }
    
    // Finally, return the “ans”.
    return ans;
}
