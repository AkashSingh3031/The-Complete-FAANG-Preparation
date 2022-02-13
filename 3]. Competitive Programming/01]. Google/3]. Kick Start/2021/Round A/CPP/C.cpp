#include<bits/stdc++.h>
using namespace std;

int caseNo = 1;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> arr(n, vector<int>(m));
	priority_queue<pair<int, pair<int, int>>> PQ; // set also can be used instead of priority queue
	for(int i = 0; i < n; i++) {				 // If set is used insert {-arr[i][j], {i, j}} into the set.
		for(int j = 0; j < m; j++) {
			cin >> arr[i][j];
			PQ.push({arr[i][j], {i, j}});
		}
	}
	long long ans = 0;
	while(!PQ.empty()) {
		int currHt = PQ.top().first;
		int x = PQ.top().second.first, y = PQ.top().second.second;
		PQ.pop();
		for(int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx < 0 || nx == n || ny < 0 || ny == m) continue;
			if(arr[nx][ny] >= currHt - 1) continue;
			int diff = currHt - 1 - arr[nx][ny];
			ans += diff;
			arr[nx][ny] = currHt - 1;
			PQ.push({arr[nx][ny], {nx, ny}});
		}
	}
	cout << "Case #" << caseNo++ << ": " << ans << endl;
}

int main() {
	int T;
	cin >> T;
	while(T--) {
		solve();
	}
	return 0;
}