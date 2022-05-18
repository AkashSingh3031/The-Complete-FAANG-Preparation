#include<bits/stdc++.h>
using namespace std;

int caseNo = 1;

int getValue(int x, int y, vector<vector<int>>& A, vector<vector<int>>& B) {
	int ans = min(A[x][y], B[x][y] / 2) + min(A[x][y] / 2, B[x][y]) - 2;
	if(ans <= 0) return 0;
	return ans;
}

int count(int x, int y, vector<vector<int>>& top, vector<vector<int>>& left, vector<vector<int>>& bottom, vector<vector<int>>& right) {
	int ans1 = getValue(x, y, top, left);
	int ans2 = getValue(x, y, top, right);
	int ans3 = getValue(x, y, bottom, left);
	int ans4 = getValue(x, y, bottom, right);
	return ans1 + ans2 + ans3 + ans4;
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> arr(n, vector<int>(m));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	vector<vector<int>> top(n, vector<int>(m)), left(n, vector<int>(m));
	vector<vector<int>> bottom(n, vector<int>(m)), right(n, vector<int>(m));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(arr[i][j] == 0) continue;
			if(i > 0) top[i][j] = top[i - 1][j] + 1;
			else top[i][j] = arr[i][j];
			if(j > 0) left[i][j] = left[i][j - 1] + 1;
			else left[i][j] = arr[i][j];
		}
	}
	for(int i = n - 1; i >= 0; i--) {
		for(int j = m - 1; j >= 0; j--) {
			if(arr[i][j] == 0) continue;
			if(i < n - 1) bottom[i][j] = bottom[i + 1][j] + 1;
			else bottom[i][j] = arr[i][j];
			if(j < m - 1) right[i][j] = right[i][j + 1] + 1;
			else right[i][j] = arr[i][j];
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(arr[i][j] == 1) {
				ans += count(i, j, top, left, bottom, right);
			}
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