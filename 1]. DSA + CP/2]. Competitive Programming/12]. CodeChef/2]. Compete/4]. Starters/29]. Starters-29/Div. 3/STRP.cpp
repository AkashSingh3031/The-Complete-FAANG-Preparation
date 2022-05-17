#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string str;
    cin >> str;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(i + 1 < n && str[i] == str[i + 1]) {
            ans++;
            i++;
        }
        else ans++;
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