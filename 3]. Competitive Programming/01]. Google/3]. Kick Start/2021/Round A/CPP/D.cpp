#include<bits/stdc++.h>
using namespace std;

int caseNo = 1;

void solve() {
	int n;
    cin >> n;
    vector<vector<int>> a(n,vector<int>(n));
    vector<vector<int>> b(n,vector<int>(n));
    vector<int> p(n),q(n);
    int R = n + 10;
    vector<vector<pair<int, int>>> v(R + n + 20);
    vector<int> vis(R + n + 20);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    int tot = 0;
    set<pair<int, int>> s;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> b[i][j];
            if(a[i][j] == -1) {
                v[i].push_back({j + R, b[i][j]});
                v[j + R].push_back({i, b[i][j]});
                tot += b[i][j];
                s.insert({0, i});
            }
        }
    }
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> q[i];
    }
    int ans = 0;
    while(s.empty() == false) {
        auto cur = *s.begin();
        s.erase(cur);
        int dis = -cur.first;
        // cout << dis << "\n";
        int ver = cur.second;
        if(vis[ver]){
            continue;
        }
        ans += dis;
        vis[ver] = 1;
        for(auto x : v[ver]){
            if(vis[x.first]){
                continue;
            }
            s.insert({-x.second, x.first});
        }
    }
    ans = tot - ans;
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