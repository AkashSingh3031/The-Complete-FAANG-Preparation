/*
    Time Complexity: O(N * log(N))
    Space Complexity: O(N)

    where 'N' is the size of the array.
*/

// This function will return the current parent of the node 'i'.
int parent(int i, vector < int > & par) {
    if (par[i] == -1) {
        return i;
    } else {
        return par[i] = parent(par[i], par);
    }
}

long long int minCost(vector < int > & x, vector < int > & y) {
    // Here 'n' stores the number of points(vertex).
    int n = x.size();

    // Here 'xx' and 'yy' will store the pair of 'x'/'y' coordinate and the index of the point.
    vector < pair < int, int >> xx(n), yy(n);
    for (int i = 0; i < n; i++) {
        xx[i] = {
            x[i],
            i
        };
        yy[i] = {
            y[i],
            i
        };
    }

    // Sort 'xx' and 'yy' in the increasing order of their 'x' and 'y' coordinates respectively.
    sort(xx.begin(), xx.end());
    sort(yy.begin(), yy.end());

    // Here 'e' will store all the edges.
    vector < vector < int >> e;

    // Add an edge between each adjacent pair of 'x' and 'y' coordinates.
    for (int i = 1; i < x.size(); i++) {
        e.push_back({
            xx[i].first - xx[i - 1].first,
            xx[i].second,
            xx[i - 1].second
        });
    }
    for (int i = 1; i < x.size(); i++) {
        e.push_back({
            yy[i].first - yy[i - 1].first,
            yy[i].second,
            yy[i - 1].second
        });
    }

    // Sort the edges in the increasing order of their costs.
    sort(e.begin(), e.end());

    // Here 'par' will store the current parent of the node and 'rnk' will store the number of nodes having the parent 'i'.
    vector < int > par(n), rnk(n);
    for (int i = 0; i < n; i++) {
        par[i] = -1;
        rnk[i] = 1;
    }

    // Here 'ans' will store the min cost required to connect all the points.
    long long int ans = 0;

    for (int i = 0; i < e.size(); i++) {
        // Here 'pa' will store the parent of the node 'e[i][1]' and 'pb' will store the parent of the node 'e[i][2]'.
        int pa = parent(e[i][1], par), pb = parent(e[i][2], par);

        // If they are already connected, then we will not add the current edge. Else we will connect them by adding an edge between these nodes.
        if (pa == pb) {
            continue;
        }
        ans += e[i][0];
        if (rnk[pa] < rnk[pb]) {
            swap(pa, pb);
        }
        rnk[pa] += rnk[pb];
        par[pb] = pa;
    }

    // In the end, return the 'ans'.
    return ans;
}