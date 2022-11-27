/*
    Time Complexity: O(N+M)
    Space Complexity: O(N+M).

    'N' is the number of ninjas and 'M' is the number of pairs given.
*/


void dfs(int curr, vector<vector<int>>&adj, vector<int>&cols) {
	// Declare, 'nextCol' which will be opposite of current node's color.

	int nextCol = 0;
	if (cols[curr] == 0)
		nextCol = 1;

	for (auto &x : adj[curr]) {
		// If any unvisited neighbour is found give it 'nextCol' and start 'dfs' from that node.
		if (cols[x] == -1) {
			cols[x] = nextCol;
			dfs(x, adj, cols);
		}
	}
}

bool isTopoSort(int n, vector<vector<int>>&adj) {

	// Calculate in degree of every node in the given graph, store it in 'inDeg'.
	vector<int>inDeg(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		for (auto &y : adj[i]) {
			inDeg[y]++;
		}
	}
	queue<int>q;

	// Insert all the nodes with 0 in degree into the 'q'.
	for (int i = 1; i <= n; i++) {
		if (inDeg[i] == 0) {
			q.push(i);
		}
	}

	// Declare, 'done' to store the number of nodes completed.
	int done = 0;
	while (q.size() > 0) {
		auto front = q.front();
		q.pop();
		done++;
		// Decrease in degree of all the adjacent node of the current node.
		for (auto &y : adj[front]) {
			inDeg[y]--;
			if (inDeg[y] == 0) {
				q.push(y);
			}
		}
	}
	// If all the nodes are visited then topological sort exists.
	return done == n;
}

int ninjaMarch(int n, vector<vector<int>> &pairs) {

	// Declare, 'adj' to store the given pairs in graphical form.
	vector<vector<int>>adj(n + 1);

	// Declare, 'cols' to store the color of node in bipartite matching.
	vector<int>cols(n + 1, -1);

	for (auto &x : pairs) {
		// Create graph.
		adj[x[1]].push_back(x[2]);
		adj[x[2]].push_back(x[1]);
	}


	// Iterate through every node.
	for (int i = 1; i <= n; i++) {
		if (cols[i] == -1) {
			// If unvisited node found, give it a color and start 'dfs' from that node.
			cols[i] = 0;
			dfs(i, adj, cols);
		}
	}

	// Check if all the nodes sharing an edge have different color.
	for (int i = 1; i <= n; i++) {
		for (auto &y : adj[i]) {
			if (cols[i] == cols[y]) {
				// If two nodes have same color then the given graph is not bipartite.
				return -1;
			}
		}
	}

	// Clear 'adj' so that we can create directed graph.
	for (int i = 0; i <= n; i++) {
		adj[i].clear();
	}


	// Create an edge from node 'A' to 'B' if position of 'A' is after 'B' in final configuration.
	for (auto &x : pairs) {
		if (cols[x[1]] == 1) {
			// Swap given nodes if 'col[x[1]]' = 1 to avoid unessasery conditions.
			swap(x[1], x[2]);
		}
		// Now all the edges will be directed from nodes whose color is 2 to nodes whose color is 1.

		if (x[0] == 1) {
			// Ninja must meet at a point.
			adj[x[1]].push_back(x[2]);
		}
		else {
			adj[x[2]].push_back(x[1]);
		}
	}

	// If Topological sort exists then answer exists.
	if (isTopoSort(n, adj)) {
		return 1;
	}
	return -1;
}