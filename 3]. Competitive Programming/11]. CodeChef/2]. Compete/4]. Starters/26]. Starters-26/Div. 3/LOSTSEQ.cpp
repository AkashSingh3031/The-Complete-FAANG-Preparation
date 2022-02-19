#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(2 * n);
    long long sum = 0;
    for(int i = 0; i < 2 * n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    sum % 2 == 0 ? cout << "YES" << endl : cout << "NO" << endl;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}