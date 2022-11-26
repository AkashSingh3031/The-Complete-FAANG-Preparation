/* 
    Time Complexity : O((N+M)*log(N+M))
    Space Complexity : O(N+M)
    where 'N' is the number of cities,
    and 'M' is the number of possible connections.
*/

// Header for 'sort' function.
#include <algorithm>

// Disjoint Set Union.
class DSU
{
    int n;
    vector<int> par, sz;

    public:
    DSU(int t)
    {
        n = t;
        par.resize(n), sz.resize(n);
        // Initialization.
        for (int i = 0; i < n; ++i)
        {
            par[i] = i;
            sz[i] = 1;
        }
    }

    // Find representative node of a set.
    int find_set(int v)
    {
        if (v == par[v])
            return v;
        return par[v] = find_set(par[v]);
    }

    // Merge two sets.
    void union_sets(int a, int b)
    {
        a = find_set(a);
        b = find_set(b);
        if (a == b)
            return;
        if (sz[a] < sz[b])
            swap(a, b);
        par[b] = a;
        sz[a] += sz[b];
    }
};

// Custom comparator to sort by cost. 
bool comparator(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}

int minimumCost(int n, int m, vector<int> cost, vector<vector<int>> connections)
{
    // 0 is the infinte source node, so add edges from 0 to all other cities.
    for (int i = 1; i <= n; ++i)
        connections.push_back({0, i, cost[i - 1]});

    DSU dsu(n + 1);
    int ans = 0;

    // Sort according to cost.
    sort(connections.begin(), connections.end(), comparator);

    for (auto i : connections)
    {
        int x = i[0], y = i[1], c = i[2];

        // If nodes are in same connected componenet.
        if (dsu.find_set(x) == dsu.find_set(y))
            continue;
        
        // Add edge between x and y.
        dsu.union_sets(x, y);

        // Add weight of the ede to ans.
        ans += c;
    }

    // Return answer.
    return ans;
}