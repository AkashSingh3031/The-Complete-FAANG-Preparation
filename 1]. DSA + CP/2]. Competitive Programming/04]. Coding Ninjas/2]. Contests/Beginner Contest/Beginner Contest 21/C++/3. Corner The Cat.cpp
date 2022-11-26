/*
    Time Complexity: O(N)
    Space Complexity: O(N)

    where N is the number of nodes in tree.
*/

int cornerTheCat(int n, vector<pair<int, int>> &edges) {
    // Initialise array that will store the degree of all nodes.
    vector<int> degree(n);

    // Iterate over all edges.
    for (int i = 0; i < n - 1; i++) {
        // Add 1 to the degree of both nodes connected by an edge.
        degree[edges[i].first]++, degree[edges[i].second]++;
    }

    // Initialise variable that will store the max degree.
    int mx = 0;

    // Iterate over all degrees to find the max.
    for (int x : degree) {
        mx = max(mx, x);
    }

    // Return the final answer: 'MaxDegree - 1'.
    return mx - 1;
}
