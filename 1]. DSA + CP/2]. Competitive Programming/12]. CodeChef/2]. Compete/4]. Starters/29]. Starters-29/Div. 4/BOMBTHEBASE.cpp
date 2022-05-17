#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int ans = 0;
    for(int i = n - 1; i >= 0; i--) {
        if(arr[i] < x) {
            ans = i + 1;
            break;
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