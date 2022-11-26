/*
    Time complexity: O(N)
    Space complexity: O(N)

    where N' is the number of cities.
*/

// Infinity value to be used ( > 'k')
const int inf = 1e9 + 5;

bool canWeReach(vector<int> &a, vector<int> &b, vector<int> &c, int n, int k) {
    // Store the minimum time to reach city 'i'.
    vector<int> min_time(n, inf);

    // Store all the edges with weights in an adjacency list, where 'i-th' index will store all the roads endings at 'i'.
    vector<vector<pair<int, int>>> adj(n);

    // Loop through the cities.
    for(int i = 0; i < n - 1; ++i) {
        // Add the edges going from 'i' to 'i' + 1.
        adj[i + 1].push_back({i, a[i]});
        // Add the edges going from 'i' to 'b[i]'.
        adj[b[i]].push_back({i, c[i]});
    }

    // We are standing at city 0, so time to reach 0-th city  is 0.
    min_time[0] = 0;

    // Loop through all the cities.
    for(int i = 1; i < n; ++i) {
        // Loop through all the roads ending at 'i'.
        for(auto &v : adj[i]) {
            // Let 'c' = adjacent city, 'w' = time to travel this road.
            int c = v.first, w = v.second;
            // Calculate the time to reach 'i' using this road.
            int cur_time = min((long)min_time[c] + w, (long)inf);
            // Update the minimum time.
            min_time[i] = min(min_time[i], cur_time);
        }
    }

    // Return true if minimum time to reach 'n' - 1 is at most 'k', else return false.
    return min_time[n - 1] <= k;
}
