#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<long long> arr(n);
    vector<int> eq[n + 1];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        for(int j = 0; j < 2 * b; j++) {
            int x;
            cin >> x;
            eq[a].push_back(x);
        }
    }
    for(int i = 0; i < n; i++) {
        if(eq[i + 1].size() == 0) continue;
        else {
            for(int j = 0; j < eq[i + 1].size(); j += 2) {
                arr[eq[i + 1][j + 1] - 1] += eq[i + 1][j] * arr[i];
                arr[eq[i + 1][j + 1] - 1] %= MOD;
            }
            arr[i] = 0;
        }
    }
    for(auto i : arr) {
        cout << i << endl;
    }
}

int main() {
    solve();
    return 0;
}