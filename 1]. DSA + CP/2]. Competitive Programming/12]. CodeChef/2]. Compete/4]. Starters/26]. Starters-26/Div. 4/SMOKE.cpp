#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    int ans = 0;
    if(x > 25 * y) {
        if(n % 4 == 0) {
            ans += (n / 4) * y;
        }
        else {
            ans += (n / 4) * y;
            ans += y;   
        }
    }
    else {
        ans += (n / 100) * x;
        n = n % 100;
        int rem = n % 4 == 0 ? (n / 4) * y : (n / 4 * y + y);
        if(x > rem) ans += rem;
        else ans += x;
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