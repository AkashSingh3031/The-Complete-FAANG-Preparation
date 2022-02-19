#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    if(n == m) cout << "SAME" << endl;
    else if(n > m) cout << "CAR" << endl;
    else cout << "BIKE" << endl;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}