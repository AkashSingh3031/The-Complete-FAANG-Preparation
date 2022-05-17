 
#include <iostream>
#include <bits/stdc++.h> 
using namespace std;
#define ll long long

void solve(){
    ll l , r , a;
    cin >> l >> r >> a ;
    ll ans= floor(r/a) + r%a ;
    ll down = r/a*a ;
    
    if(l<down) down--;
    ans = max(ans,down/a + down%a) ;
    cout << ans << '\n';
}

int main()
{   
    int n= 0;
    cin >> n;
    while(n--){
      solve();
    }
}
