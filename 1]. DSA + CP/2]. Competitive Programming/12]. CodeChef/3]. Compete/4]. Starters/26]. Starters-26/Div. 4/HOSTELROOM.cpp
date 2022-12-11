#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    int ans = m, cnt = m;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        cnt += arr[i];
        ans = max(ans, cnt);
    }
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}