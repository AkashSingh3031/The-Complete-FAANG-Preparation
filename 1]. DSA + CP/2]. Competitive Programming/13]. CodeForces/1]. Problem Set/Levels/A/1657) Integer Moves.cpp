// https://codeforces.com/contest/1657/problem/A

#include <iostream>
#include <cmath>

using namespace std;

void solve(){
    int x,y;
    cin >> x >> y;
    
    if(x == 0 && y == 0) cout << 0 << "\n";
    else if(x == 0 || y == 0) cout << 1 << "\n";
    else{
        int d = sqrt(x * x + y * y);
        if(d * d == x * x + y * y) cout << 1 << "\n";
        else cout << 2 << "\n";
    }
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