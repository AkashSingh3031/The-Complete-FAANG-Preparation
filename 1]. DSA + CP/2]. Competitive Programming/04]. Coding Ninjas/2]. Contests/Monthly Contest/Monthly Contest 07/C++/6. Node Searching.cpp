/*
    Time Complexity: O(Q * log(N) * log(N))
    Space Complexity: O(N * log(N))

    Where, 'N' is the number of nodes in tree and 'Q' is the number of queries.
*/


void dfs(int currNode, int parNode, vector<vector<int>> &adj, vector<int>&par) {
	// Set 'par[currNode]' to 'parNode' as it is the parent.
	par[currNode] = parNode;

	for (auto &x : adj[currNode]) {
		// Visit all the nodes except the parent from the current node.
		if (x != parNode) {
			dfs(x, currNode, adj, par);
		}
	}
}

int findKth(int node, int mid, vector<vector<int>> &binPar) {
	// Iterate over the bits.
	for (int i = 17; i > -1; i--) {
		int curr = (1 << i);
		// If the 'ith' bit is present then make 'node = binPar[i][node]'.
		if ((curr & mid)) {
			node = binPar[i][node];
		}
	}
	// Return 'node' once all the bits are processed.
	return node;
}
vector<int> nodeSearching(vector<vector<int>>&edges, vector<int>&v, vector<vector<int>>&queries) {
	int n = v.size();
	// Declare 'adj': adjacency list for the given tree.
	vector<vector<int>>adj(n + 1);

	for (auto &x : edges) {
		// Insert edges.
		adj[x[0]].push_back(x[1]);
		adj[x[1]].push_back(x[0]);
	}

	// Declare an array 'par' to store parent of each node.
	vector<int>par(n + 1, 0);
	par[1] = 1;

	// Start 'dfs' from root node.
	dfs(1, 1, adj, par);

	// Declare 'binPar' to store ancestor which are power of 2 apart.
	vector<vector<int>>binPar(18, vector<int>(n + 1, 1));

	// Here, '18' is kepth because '2^18' >= '10^5'.
	for (int i = 1; i <= n; i++) {
		binPar[0][i] = par[i];
	}

	for (int j = 1; j < 18; j++) {

		for (int i = 1; i <= n; i++) {
			// 4th parent is 2nd parent's 2nd parent.
			binPar[j][i] = binPar[j - 1][binPar[j - 1][i]];
		}
	}

	vector<int>ans(queries.size());
	for (int i = 0; i < queries.size(); i++) {
		// Iterate over each query.
		int node = queries[i][0];
		int val = queries[i][1];

		if (v[0] < val) {
			// If required value is greater than that of root node, then its impossible.
			ans[i] = -1; continue;
		}
		else {
			// Binary search space '[l, r]'.
			int l = 0, r = n;
			while (r - l > 1) {
				int mid = (l + (r - l) / 2);
				// Find the parent which is at 'mid' distance.
				int midPar = findKth(node, mid, binPar);

				// If it's value greater or equal to 'val' move down.
				if (v[midPar - 1] >= val) {
					r = mid;
				}
				else {
					l = mid;
				}
			}

			// First check if 'l' satisfy then that is answer.
			int forL = findKth(node, l, binPar);
			if (v[forL - 1] >= val) {
				ans[i] = forL;
			}
			else {
				// Otherwise, 'rth' parent is the answer.
				ans[i] = findKth(node, r, binPar);
			}
		}
	}

	// Return 'ans' once all the queries are processed.

	return ans;
}
