#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, d;
    cin >> n >> d;
    vector<long long> A(n + 1), B(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> B[i];
    }
    long long ans = LLONG_MIN;
    for(long long i = max(n - 2 * d, 1LL); i <= n; i++) {
        for(long long j = A[i]; j <= n; j++) {
            ans = max(ans, i * j - d * (B[i] ^ B[j]));
        }
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