#include<bits/stdc++.h>
using namespace std;

int caseNo = 1;

void solve() {
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;
    int cnt = 0;
    for(int i = 0, j = n - 1; i < j; i++, j--) {
        if(str[i] != str[j]) cnt++;
    }
    int ans = abs(k - cnt);
    cout << "Case #" << caseNo++ << ": " << ans << endl;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
}