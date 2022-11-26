/*
    Time Complexity: O(N)
    Space Complexity: O(N)

    where 'N' denotes the number of vertices in the tree.
*/

/*
 * 'i' is the current vertex.
 * 'par' is the parent of vertex 'i'.
 * 'adj' is the adjacency list.
 * 'dis[i]' stores the distance from root till 'i'.
 */
void dfs(int i, int par, vector<vector<int>> &adj, vector<int> &dis) {
    // Iterate over all the edges of vertex 'i'.
    for (int j: adj[i]) {

        // If 'j' is not the parent of 'i'.
        if (j != par) {

            // Store the distance from root till 'j'.
            dis[j] = dis[i] + 1;

            // Recurse for the child 'j'.
            dfs(j, i, adj, dis);
        }
    }
}

int countPairs(int n, vector<vector<int>> &edges) {

    // 'adj[i]' stores the adjacency List of the tree.
    vector<vector<int>> adj(n);

    for (int i = 0; i < n - 1; ++i) {

        // Add the edge in the adjacency list.
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    // 'dis[i]' stores the distance from root till 'i'.
    vector<int> dis(n);

    // Do a dfs with '0' as the root of the tree.
    dfs(0, -1, adj, dis);

    // 'x' stores the size of set 'L' and 'y' stores the size of set 'R'.
    int x = 0, y = 0;

    // Iterate over all the vertices of the tree.
    for (int i = 0; i < n; ++i) {

        // If 'i' is at an even depth.
        if (dis[i] % 2 == 0) {

            // Increment the size of set 'L'.
            x++;
        } else {

            // Otherwise, increment the size of set 'R'.
            y++;
        }
    }

    // Return the answer as discussed in the editorial.
    return x * (x - 1) / 2 + y * (y - 1) / 2;
}