#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    long long ans;
    cin >> n;
    vector<int> even, odd;
    int x;
    for(int i = 0; i < n; i++) {
        cin >> x;
        if(i & 1) odd.push_back(abs(x));
        else even.push_back(abs(x));
    }
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());
    long long evensum = accumulate(even.begin(), even.end(), 0LL);
    long long oddsum = accumulate(odd.begin(), odd.end(), 0LL);
    ans = evensum - oddsum;
    int temp = even[0];
    even[0] = odd[odd.size() - 1];
    odd[odd.size() - 1] = temp;
    long long sum = accumulate(even.begin(), even.end(), 0LL) - accumulate(odd.begin(), odd.end(), 0LL); 
    ans = max(ans, sum);
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