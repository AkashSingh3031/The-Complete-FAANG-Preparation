// https://codeforces.com/contest/1657/problem/B

#include <iostream>
#include <vector>

using namespace std;

void solve(){
    long long n,b,x,y;
    cin >> n >> b >> x >> y;
    
    vector <long long> a(n + 1, 0);
    
    for(int i = 1; i <= n; ++i){
        if(a[i - 1] + x <= b) a[i] = a[i - 1] + x;
        else a[i] = a[i - 1] - y;
    }
    
    long long result = 0;
    for(int i = 0; i <= n; ++i) result += a[i];
    
    cout << result << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    
    int t;
    cin >> t;
    while(t--) solve();
    
    return 0;
}