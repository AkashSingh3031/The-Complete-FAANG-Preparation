/*

    Time Complexity: O(N + V)
    Space Complexity: O(N + V)

    where 'N' denotes the number of nodes in the graph, and 'V' represents the number of edges.

*/

void genBCC(int v, int p, int& n2, int& tim, stack<int>& scc, vector<int>& sz, vector<int>& low,
    vector<int>& curr, vector<vector<int>>& adj, vector<vector<int>>& cmp)
{

    low[v] = curr[v] = ++tim;
    scc.push(v);

    // Iterating in all the nodes that are connected to node 'v'.
    for (auto i : adj[v])
    {
        if (i == p)
            continue;

        // If the node is not visited.
        if (!curr[i])
        {
            genBCC(i, v, n2, tim, scc, sz, low, curr, adj, cmp);
            low[v] = min(low[v], low[i]);

            if (low[i] >= curr[v])
            {
                n2++;
                cmp[v].push_back(n2);
                while (!((int)cmp[n2].size()) || cmp[n2].back() != i)
                {
                    cmp[n2].push_back(scc.top());
                    scc.pop();
                }
            }
        }
        else
            low[v] = min(low[v], curr[i]);
    }
    adj[v].clear();
}


int solution(int N, int M, vector<pair<int, int>> edges)
{

    // Initializing all required variables for BCC.
    int ans = 0;

    int n2 = N;
    vector<int> sz(N + 3, 0), low(N + 3, 0), curr(N + 3, 0);
    int tim = 0;
    stack<int> scc;
    vector<vector<int>> adj(N + 3), cmp(2 * M + 3);

    // Creating adjacency list and storing in 'adj'.
    for (int i = 0; i < M; i++)
    {
        int a, b;
        a = edges[i].first;
        b = edges[i].second;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Calling 'genBCC' function to generate all Biconnected-components.
    genBCC(1, 0, n2, tim, scc, sz, low, curr, adj, cmp);

    // Finding the size of largest Biconnected-component.
    for (int i = N + 1; i <= n2; i++)
    {
        ans = max(ans, (int)cmp[i].size() + 1);
    }

    return ans;
}