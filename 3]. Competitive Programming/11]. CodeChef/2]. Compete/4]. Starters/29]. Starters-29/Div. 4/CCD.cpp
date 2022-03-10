#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    string str, ans;
    cin >> str >> ans;
    vector<int> pref(n + 1);
    for(int i = 1; i <= n; i++) {
        int diff = (ans[i - 1] - str[i - 1] + 26) % 26;
        if(i % 2 == 0) diff *= -1;
        pref[i] = (pref[i - 1] + diff + 26) % 26;
    }
    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        if(pref[l - 1] == pref[r]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}