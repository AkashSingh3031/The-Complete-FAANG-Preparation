/*
    Time Complexity: O(N)
    Space Complexity: O(N)

    where 'N' denotes the number of vertices in the tree.
*/


/*
 * 'i' is the current vertex.
 * 'par' is the parent of vertex 'i'.
 * 'adj' is the adjacency list.
 * 'dep[i]' stores the distance from root till 'i'.
 */
void dfs(int i, int par, vector<vector<pair<int, int>>> &adj, vector<int> &dep) {
    // Iterate over all the edges of vertex 'i'.
    for (auto &p: adj[i]) {

        // 'j' is the adjacent vertex, and 'w' is the weight of the edge.
        int j = p.first, w = p.second;

        // If 'j' is not the parent of 'i'.
        if (j != par) {

            // Store the distance from root till 'j'.
            dep[j] = dep[i] + w;

            // Recurse for the child 'j'.
            dfs(j, i, adj, dep);
        }
    }
}

int shortestJourney(int n, vector<vector<int>> &edges) {

    // 'tot' stores the sum of all edge weights.
    int tot = 0;

    /*
     * 'adj[i]' stores the adjacency List of the tree, in form of pairs.
     * The first value in pair is the adjacent vertex and second is the weight of the edge.
     */
    vector<vector<pair<int, int>>> adj(n);

    for (int i = 0; i < n - 1; ++i) {

        // Add the edge weight to 'tot'.
        tot += edges[i][2];

        // Add the edge in the adjacency list.
        adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
    }

    // 'dep[i]' stores the distance from root till 'i'.
    vector<int> dep(n);

    // Pick '0' as source vertex and do a dfs from it.
    dfs(0, -1, adj, dep);

    //  'best' is the farthest vertex from the vertex '0',
    int best = 0;
    for (int i = 1; i < n; ++i) {

        if (dep[best] < dep[i]) {
            best = i;
        }
    }

    // Set all the values of 'dep[i]' to '0'.
    fill(dep.begin(), dep.end(), 0);

    // Now do a dfs from the vertex 'best'.
    dfs(best, -1, adj, dep);

    // 'diam' stores the diameter of the tree.
    int diam = 0;

    // Find the maximum distance obtained from dfs of 'best'.
    for (int i = 0; i < n; ++i) {

        // Update 'diam' if a new maximum distance is found.
        diam = max(diam, dep[i]);
    }

    // As discussed in editorial, return the answer.
    return 2 * tot - diam;
}